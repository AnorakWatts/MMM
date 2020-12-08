//
// Created by anorak on 12.10.2020.
//

#include "Plotter.h"

Plotter::Plotter(int x, int y, int sizex, int sizey) {
    back.setSize(Vector2f(sizex,sizey));
    this->sizeX=sizex;
    this->sizeY=sizey;
    this->XL=0;
    this->YL=0;
    this->SX=x;
    this->SY=y;
    minX=INT64_MAX;
    minY=INT64_MAX;
    MaxX=INT64_MIN;
    MaxY=INT64_MIN;
    back.setFillColor(Color::Black);
    back.setSize(Vector2f(sizex,sizey));
    back.setPosition(x,y);
    back.setOutlineColor(Color::Red);
    back.setOutlineThickness(2);
}

void Plotter::addfun(double x0, double x1, double (*Fs)(double)) {
    bool reb=0;
    this->funcs.push_back(Funcs());
    funcs.back().x0=x0;
    funcs.back().x1=x1;
    if (minX > x0) {
        minX = x0;
        XL = MaxX - minX;
        reb=1;
    }
    if (MaxX < x1) {
        MaxX = x1;
        XL = MaxX - minX;
        reb=1;
    }
    double curY;
    funcs.back().Fs = Fs;
    funcs.back().typ = Funcs::tp::func;
    if(funcs.back().cur) {
        funcs.back().cur->clear();
        delete (funcs.back().cur);
    }
    int ssize=(x1 - x0) * (this->sizeX/this->XL);
    funcs.back().sssize=ssize;
    funcs.back().cur=new VertexArray(PrimitiveType::LinesStrip,ssize);
    double ii=(x1 - x0) * (this->sizeX/this->XL);
    for (double i = 0; i < (x1 - x0) * (this->sizeX/this->XL); i++) {
        curY = Fs(i + x0 - this->minX);
        if (curY < minY) {
            minY = curY;
            reb=1;
        }
        if (curY > MaxY) {
            MaxY = curY;
            reb=1;
        }
        if (curY < minY) {
            minY = curY;
            reb=1;
        }
        if (curY > MaxY) {
            MaxY = curY;
            reb=1;
        }
    }
    double tr=x0;
    YL = (MaxY - minY);
    for(int i=0;i<ssize;i++)
    {
        double xx=(i+(x0-minX)*(sizeX/XL));
        double yy=(sizeY/YL)*(Fs(xx/(sizeX/XL)))+sizeY/2;
        funcs.back().cur->operator[](i).position.x= xx+SX;
        funcs.back().cur->operator[](i).position.y= yy+SY;
        funcs.back().cur->operator[](i).color=Color::White;
    }
    if(reb)
        rebuild();
}

void Plotter::rebuild()
{
    vector<Funcs>funcsb=funcs;
    funcs.clear();
    for(int i=0;i<funcsb.size()-1;i++)
    {
        switch (funcsb[i].typ) {

            case Funcs::vectorsxy:
                addfun(funcsb[i].x,funcsb[i].y);
                break;
            case Funcs::func:
                addfun(funcsb[i].x0,funcsb[i].x1,funcsb[i].Fs);
                break;
            case Funcs::funcm:
                addfun(funcsb[i].x0,funcsb[i].x1,funcsb[i].eps,funcsb[i].Fm);
                break;
            case Funcs::lag:
                addfun(funcsb[i].x0,funcsb[i].x1,funcsb[i].x,funcsb[i].y,funcsb[i].Fl);
                break;
            case Funcs::point:
                addPoint(funcsb[i].x0,funcsb[i].x1);
                break;
        }
    }
    funcs.push_back(funcsb.back());
}



void Plotter::draw(RenderTarget &target, sf::RenderStates states) const
{
    target.draw(back);
    for(int i=0;i<funcs.size();i++)
    {
        if(funcs[i].typ!=Funcs::tp::point)
            target.draw(*funcs[i].cur);
        else
            target.draw(funcs[i].ppoint);
    }
}




void Plotter::addfun(double x0, double x1, double eps, long double (*Fm)(long double, long double)) {
    bool reb=0;
    this->funcs.push_back(Funcs());
    funcs.back().x0=x0;
    funcs.back().x1=x1;
    if (minX > x0) {
        minX = x0;
        XL = MaxX - minX;
        reb=1;
    }
    if (MaxX < x1) {
        MaxX = x1;
        XL = MaxX - minX;
        reb=1;
    }
    double curY;
    funcs.back().Fm = Fm;
    funcs.back().typ = Funcs::tp::funcm;
    funcs.back().eps=eps;
    if(funcs.back().cur) {
        funcs.back().cur->clear();
        delete (funcs.back().cur);
    }
    int ssize=(x1 - x0) * (this->sizeX/this->XL);
    funcs.back().sssize=ssize;
    funcs.back().cur=new VertexArray(PrimitiveType::LinesStrip,ssize);
    double ii=(x1 - x0) * (this->sizeX/this->XL);
    for (double i = 0; i < ssize; i++) {
        curY = Fm(i + x0 - this->minX,eps);
        if (curY < minY) {
            minY = curY;
            reb=1;
        }
        if (curY > MaxY) {
            MaxY = curY;
            reb=1;
        }
        if (curY < minY) {
            minY = curY;
            reb=1;
        }
        if (curY > MaxY) {
            MaxY = curY;
            reb=1;
        }
    }
    YL = (MaxY - minY);
    for(int i=0;i<ssize;i++)
    {
        double xx=(i+(x0-minX)*(sizeX/XL));
        double yy=(sizeY/YL)*(Fm(xx/(sizeX/XL),eps))+sizeY/2;
        funcs.back().cur->operator[](i).position.x= xx+SX;
        funcs.back().cur->operator[](i).position.y= yy+SY;
        funcs.back().cur->operator[](i).color=Color::White;
    }
    if(reb)
        rebuild();
}

void Plotter::addfun(double x0, double x1, vector<long double> arrX, vector<long double> arrY,
                     double (*Fl)(vector<long double>, vector<long double>, double))
{
    bool reb=0;
    this->funcs.push_back(Funcs());
    funcs.back().x0=x0;
    funcs.back().x1=x1;
    if (minX > x0) {
        minX = x0;
        XL = MaxX - minX;
        reb=1;
    }
    if (MaxX < x1) {
        MaxX = x1;
        XL = MaxX - minX;
        reb=1;
    }
    double curY;
    funcs.back().Fl=Fl;
    funcs.back().typ = Funcs::tp::lag;
    funcs.back().x=arrX;
    funcs.back().y=arrY;
    if(funcs.back().cur) {
        funcs.back().cur->clear();
        delete (funcs.back().cur);
    }
    int ssize=(x1 - x0) * (this->sizeX/this->XL);
    funcs.back().sssize=ssize;
    funcs.back().cur=new VertexArray(PrimitiveType::LinesStrip,ssize);
    double ii=(x1 - x0) * (this->sizeX/this->XL);
    for (double i = 0; i < ssize; i++) {
        curY = Fl(arrX,arrY,i + x0 - this->minX);
        if (curY < minY) {
            minY = curY;
            reb=1;
        }
        if (curY > MaxY) {
            MaxY = curY;
            reb=1;
        }
        if (curY < minY) {
            minY = curY;
            reb=1;
        }
        if (curY > MaxY) {
            MaxY = curY;
            reb=1;
        }
    }
    YL = (MaxY - minY);
    for(int i=0;i<ssize;i++)
    {
        double xx=(i+(x0-minX)*(sizeX/XL));
        double yy=(sizeY/YL)*(Fl(arrX,arrY,xx/(sizeX/XL)))+sizeY/2;
        funcs.back().cur->operator[](i).position.x= xx+SX;
        funcs.back().cur->operator[](i).position.y= yy+SY;
        funcs.back().cur->operator[](i).color=Color::White;
    }
    if(reb)
        rebuild();
}

void Plotter::addfun(vector<long double> arrX, vector<long double> arrY) {
    bool reb=0;
    this->funcs.push_back(Funcs());
    for(auto i:arrX) {
        if (minX > i) {
            minX = i;
            XL = MaxX - minX;
            reb = 1;
        }
        if (MaxX < i) {
            MaxX = i;
            XL = MaxX - minX;
            reb = 1;
        }
    }

    funcs.back().typ = Funcs::tp::vectorsxy;
    funcs.back().x=arrX;
    funcs.back().y=arrY;
    if(funcs.back().cur) {
        funcs.back().cur->clear();
        delete (funcs.back().cur);
    }
    funcs.back().cur=new VertexArray(PrimitiveType::LinesStrip,arrX.size());
    for(auto i:arrY) {
        if (minY > i) {
            minY = i;
            reb = 1;
        }
        if (MaxY < i) {
            MaxY = i;
            reb = 1;
        }
    }
    YL = (MaxY - minY);
    for(int i=0;i<arrX.size();i++)
    {
        double xx=arrX[i]*sizeX/XL;
        double yy=arrY[i]*sizeY/YL+sizeY/2;
        funcs.back().cur->operator[](i).position.x= xx+SX;
        funcs.back().cur->operator[](i).position.y= yy+SY;
        funcs.back().cur->operator[](i).color=Color::White;
    }
    if(reb)
        rebuild();
}

void Plotter::setColors(vector<Color> cc, Color bg) {
    int gg;
    if(cc.size()<=funcs.size())
        gg=cc.size();
    else
        gg=funcs.size();
    for(int i=0;i<gg;i++)
    {
        for(int j=0;j<funcs[i].sssize;j++)
        {
            funcs[i].cur->operator[](j).color=cc[i];
        }
    }

    back.setFillColor(bg);
}

void Plotter::addPoint(double x, double y) {
    this->funcs.push_back(Funcs());
    funcs.back().x0=x;
    funcs.back().x1=y;
    funcs.back().typ=Funcs::tp::point;
    funcs.back().ppoint.setRadius(5);
    funcs.back().ppoint.setPosition(x*sizeX/XL,(y*sizeY/YL)+(sizeY/2));
    funcs.back().ppoint.setFillColor(sf::Color::Red);
}




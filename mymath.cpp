//
// Created by valya on 03.09.2020.
#include "mymath.h"
#define ln10 2.30258509299

long double mymath::mathfunctions::sin(long double x, long double eps) {

    double res=0,cur=x,n=1;
    while (fabs(cur)>=eps)
    {
        n+=2;
        res+=cur;
        cur=(cur*(-1)*x*x)/(n*(n-1));
    }
    return res;
}

long double mymath::mathfunctions::cos(long double x, long double eps) {
    long double res=1,cur=(-(x*x))/2;
    int n=2;
    while(fabs(cur)>=eps)
    {
        n+=2;
        res+=cur;
        cur=(cur/(n*(n-1)))*x*x*(-1);
    }
    return res;
}

long double mymath::mathfunctions::exp(long double x, long double eps) {
    long double res=0,cur=1,n=0;
    while (fabs(cur)>=eps)
    {
        n+=1;
        res+=cur;
        cur=(cur*x)/n;
    }
    return res;
}

long double mymath::mathfunctions::ln(long double x, long double eps) {
    int t=0;
    bool uper1=0;
    if(x<0)
    {
        return NULL;
    }
    if(x==1)
        return 0;
    while(x>1)
    {
        uper1=1;
        x/=10;
        t++;
    }
    x-=1;
    long double res=0,cur=x,n=1;
    while (fabs(cur)>=eps)
    {
        n++;
        res+=cur;
        cur=(n-1)*(-1)*(cur*x)/n;
    }
    if(uper1)
        res+=ln10*t;
    return res;
}

long double mymath::mathfunctions::lg(long double x, long double eps) {
    long double res=(ln(x,eps)/ln10);
    return res;
}

long double mymath::mathfunctions::lAb(long double a, long double b, long double eps) {
    return ln(a,eps)/ln(b,eps);
}


mymath::plotter::plotter(int WindowL, int WindowH) {
    WL=WindowL;
    WH=WindowH;
    window=new sf::RenderWindow(sf::VideoMode(WL, WH), "plot", sf::Style::Close);
}

void mymath::plotter::setfun(long double (*fun)(long double, long double),int x0, int x1,long double eps) {
    long double xlen=fabs(x1-x0),y0,y1,y;
    y1=y0=fun(x0+((xlen/WL)*1),eps);
    sf::VertexArray curve(sf::LineStrip,WL);
    for(int i=0;i<WL;i++)
    {
        y=fun(x0+((xlen/WL)*i),eps);
        if(y<y0)
            y0=y;
        if(y>y1)
            y1=y;
    }

    long double ylen=y1-y0;
    for(int i=0;i<WL;i++)
    {

        curve[i]=sf::Vector2f(i,-(WH/ylen)*fun(x0+((xlen/WL)*i),eps)+(WH-y+y0)/2);
    }
    window->draw(curve);
    window->display();
}

void mymath::plotter::setfun(double (*fun)(double), int x0, int x1) {
    long double xlen=fabs(x1-x0),y0,y1,y;
    y1=y0=fun(x0+((xlen/WL)*1));
    sf::VertexArray curve(sf::LineStrip,WL);
    for(int i=0;i<WL;i++)
    {
        y=fun(x0+((xlen/WL)*i));
        if(y<y0)
            y0=y;
        if(y>y1)
            y1=y;
    }
    long double ylen=y1-y0;
    for(int i=0;i<WL;i++)
    {
        curve[i]=sf::Vector2f(i,-(WH/ylen)*fun(x0+((xlen/WL)*i))+(WH-y+y0)/2);
    }
    window->draw(curve);
    window->display();
}

void mymath::plotter::sleep() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                this->~plotter();
                return;
            }
        }
    }
}
mymath::plotter::~plotter() {
    delete (window);
}


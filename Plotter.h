//
// Created by anorak on 12.10.2020.
//
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

struct Funcs
{
    enum tp {vectorsxy,func,funcm,lag,mnk,point};
    double (*Fs)(double x);
    double x0,x1,eps;
    double (*Fl)(vector<long double> arrX,vector<long double> arrY,double x);
    long double (*Fm)(long double x,long double eps);
    vector<long double>x,y;
    tp typ;
    VertexArray*cur;
    CircleShape ppoint;
    int sssize;
};

class Plotter : public Drawable
{
private:
    double sizeX,sizeY,SX,SY;
    double MaxX,minX,MaxY,minY,XL,YL;
    vector<Funcs>funcs;
    RectangleShape back;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Plotter(int x,int y, int sizex, int sizey);
    void addfun(double x0,double x1,double (*Fs)(double x));
    void addfun(double x0,double x1,double eps,long double (*Fm)(long double x,long double eps));
    void addfun(double x0,double x1,vector<long double> arrX,vector<long double> arrY,double (*Fl)(vector<long double> arrX,vector<long double> arrY,double x));
    void addfun(vector<long double> arrY,vector<long double> arrX);
    void setColors(vector<Color>cc,Color bg);
    void addPoint(double x,double y);
    void rebuild();

};
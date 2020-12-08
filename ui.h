//
// Created by anorak on 17.09.2020.
//
#include"MathFuncs.h"
#include <cmath>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Plotter.h"
using namespace AnoraksMath;
using namespace std;
using namespace sf;


void ui1()
{
    char c;
    while (c!='p') {
        double eps, x;
        cout << "enter eps" << endl;
        cin>>eps;
        cout<<"enter x"<<endl;
        cin>>x;
        cout<<"s - sin    c - cos    e - exp    n - ln    g - lg    t - tan"<<endl;
        cin>>c;
        switch (c) {
            case 's':
                cout<<"c++    "<<sin(x)<<"    my    "<<MathFuncs::sin(x,eps);
                break;
            case 'c':
                cout<<"c++    "<<cos(x)<<"    my    "<<MathFuncs::cos(x,eps);
                break;
            case 'n':
                cout<<"c++    "<<log(x)<<"    my    "<<MathFuncs::ln(x,eps);
                break;
            case 'g':
                cout<<"c++    "<<log10(x)<<"    my    "<<MathFuncs::lg(x,eps);
                break;
            case 'e':
                cout<<"c++    "<<exp(x)<<"    my    "<<MathFuncs::exp(x,eps);
                break;
            case 't':
                cout<<"c++    "<<tan(x)<<"    my    "<<MathFuncs::sin(x,eps)/MathFuncs::cos(x,eps);
                break;

        }
        cout<<endl;
    }
}
/*
void ui3()
{
    vector<sf::Color>cl;
    cl.push_back(Color::Red);
    cl.push_back(Color::Blue);
    cl.push_back(Color::Green);
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!",sf::Style::Default);
    double  x0,x1, xz, step;
    x0=0; x1=0.5*3.14;step=3.14/6;
    xz=3.14/4;
    vector<long double> x,y;
    for(double i=x0;i<x1;i+=step)
    {
        x.push_back(i);
        y.push_back(cos(i));
    }
    Plotter pt1(1600,300,0,0),pt2(1600,300,300,0),pt3(1600,300,600,0);
    cout<<"c++    "<<cos(xz)<<"    lag    "<<MathFuncs::lagrange(y,x,xz)<<"    max coof   "<<MathFuncs::newtone2(x,y,xz)<<endl;
    pt1.addfun(cos,x0-10,x1*2);
    pt2.addfun(MathFuncs::lagrange,x,y,x0,x1);
    pt3.addfun(cos,x0-10,x1*2);
    pt3.addfun(MathFuncs::lagrange,x,y,x0-10,x1*2);
    pt1.setColors(cl,sf::Color::White);
    pt2.setColors(cl,sf::Color::White);
    pt3.setColors(cl,sf::Color::White);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(Color::White);
        window.draw(pt1);
        window.draw(pt2);
        window.draw(pt3);
        window.display();
    }
}
*/
void ui2()
{
    vector<double>x,y;
    x.push_back(1);
    x.push_back(1.5);
    x.push_back(2);
    x.push_back(2.5);
    x.push_back(3);
    y.push_back(0);
    y.push_back(0.40547);
    y.push_back(0.69315);
    y.push_back(0.91629);
    y.push_back(1.0986);
    cout<<"Ldif  "<<MathFuncs::ldif(y,2,0.5)<<endl<<"CDif  "<<MathFuncs::cdif(y,2,0.5)<<endl<<"Rdif  "<<MathFuncs::rdif(y,2,0.5)<<endl<<"DDif1  "<<MathFuncs::ddif(y,1,0.5)<<endl<<"DDif2  "<<MathFuncs::ddif(y,2,0.5)<<endl<<"DDif3  "<<MathFuncs::ddif(y,3,0.5)<<endl<<"TDif2  "<<MathFuncs::tdif2(y,2,0.5)<<endl<<"TDif1  "<<MathFuncs::tdif2(y,1,0.5)<<endl;
}
/*
void ui6()
{
    cout<<MathFuncs::integralls(0,4,1,fun,MathFuncs::sq::xi)<<"  prav  "<<endl<<MathFuncs::integralls(0,4,1,fun,MathFuncs::sq::xminodnavtoraya)<<"  sred  "<<endl;
    cout<<MathFuncs::integralls(0,4,1,fun,MathFuncs::sq::ximin1)<<"  lev  "<<endl<<MathFuncs::integraltroph(0,4,1,fun)<<"  trap  tochnoct<=  "<<(1.0/3.0)*fabs(MathFuncs::integraltroph(0,4,0.5,fun)-MathFuncs::integraltroph(0,4,1,fun))<<endl<<MathFuncs::the_Simpson(0,4,1,fun)<<"  simp  "<<endl;
}

*/
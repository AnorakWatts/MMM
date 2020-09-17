#include"MathFuncs.h"
#include"Plotter.h"
#include <cmath>
#include <iostream>

using namespace AnoraksMath;
using namespace std;


void ui()
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

int main()
{/*
    vector<sf::Color>cl;
    cl.push_back(Color::Red);
    cl.push_back(Color::Blue);
    cl.push_back(Color::Green);
    sf::ContextSettings g;  g.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!",sf::Style::Default,g);
    Plotter pt2(1600, 900, 0, 0);
    vector<long double>x,yn,yl;
    for(double i=0;i<1000;i++)
    {
        x.push_back(i);
        yl.push_back(sin(i)+1);
        yn.push_back(sin(i)+2);
    }
    pt2.addfun(&MathFuncs::lagrange,yl,x,5,70);
    pt2.addfun(sin, 5,70);
    pt2.addfun(MathFuncs::newtone,x,yn,5,70);
    pt2.setColors(cl,Color::White);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(Color::White);
        window.draw(pt2);
        window.display();
    }*/
ui();
}
#include"MathFuncs.h"
#include"Plotter.h"
#include <cmath>
#include <iostream>
typedef long double (*f)(long double,long double);
using namespace AnoraksMath;
using namespace std;

int main()
{
    vector<sf::Color>cl;
    cl.push_back(Color::Red);
    cl.push_back(Color::Blue);
    cl.push_back(Color::Green);
    sf::ContextSettings g;  g.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!",sf::Style::Default,g);
    Plotter pt2(1600, 900, 0, 0);
    vector<long double>x,y;
    for(double i=0;i<100;i++)
    {
        x.push_back(i);
        y.push_back(sin(i));
        //y.push_back(sin(i));
    }
    pt2.addfun(&MathFuncs::lagrange,y,x,0,100);
    pt2.addfun(sin, 0,100);
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
    }
    return 0;
}
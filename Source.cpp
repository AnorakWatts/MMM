#include"MathFuncs.h"
#include"Plotter.h"
#include <cmath>
#include <iostream>
typedef long double (*f)(long double,long double);
using namespace AnoraksMath;
using namespace std;

int main()
{
    /*sf::ContextSettings g;  g.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!",sf::Style::Default,g);
    Plotter pt2(300, 300, 10, 10);
    pt2.addfun(&tan, -1, 1);
    //pt2.addfun(&cos, -1, 1);
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

    return 0;*/
    vector<long double>x,y;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    for(int i=0;i<x.size();i++)
        y.push_back(pow(x[i],2));
    cout<<MathFuncs::lagrange(y,x,2.5);
}
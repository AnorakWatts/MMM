#include"MathFuncs.h"
#include"Plotter.h"
typedef long double (*f)(long double,long double);
using namespace AnoraksMath;

int main()
{
    sf::ContextSettings g;  g.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!",sf::Style::Default,g);
    Plotter pt2(300, 300, 10, 10);
    pt2.addfun(&MathFuncs::slojno, -1, 1,0.0001);
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
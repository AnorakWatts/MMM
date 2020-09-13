#include "Plotter.h"

AnoraksMath::Plotter::Plotter(int PlotL, int PlotH, int startY, int startX)
{
	PH = PlotH;
	PL = PlotL;
    bg->setPosition(startX, startY);
    bg->setSize(Vector2f( PlotL, PlotH));
    bg->setFillColor(Color::Black);
    bg->setOutlineColor(Color::Red);
    bg->setOutlineThickness(4);
    SX = startX;
    SY = startY;

}

void AnoraksMath::Plotter::addfun(long double (*fun)(long double, long double), int x0, int x1, long double eps) {
    long double xlen = fabs(x1 - x0), y0, y1, y;
    y1 = y0 = fun(x0 + ((xlen / PL) * 1), eps);
    sf::VertexArray curve(sf::LinesStrip, PL);
    for (int i = 0; i < PL; i++)
    {
        y = fun(x0 + ((xlen / PL) * i), eps);
        if (y < y0)
            y0 = y;
        if (y > y1)
            y1 = y;
    }

    long double ylen = y1 - y0;
    for (int i = 0; i < PL; i++)
    {

        curve[i] = sf::Vector2f(i+SX, (-(PH / ylen) * fun(x0 + ((xlen / PL) * i), eps) + (PH - y + y0) / 2)+SY);
        if (curve[i].position.y > SY + PH)
            curve[i].position.y = SY + PH;
        else if (curve[i].position.y < SY)
            curve[i].position.y = SY;
    }
    curves.push_back(curve);
}

void AnoraksMath::Plotter::addfun(double (*fun)(double), int x0, int x1) {
    long double xlen = fabs(x1 - x0), y0, y1, y;
    y1 = y0 = fun(x0 + ((xlen / PL) * 1));
    sf::VertexArray curve(sf::LinesStrip, PL);
    for (int i = 0; i < PL; i++)
    {
        y = fun(x0 + ((xlen / PL) * i));
        if (y < y0)
            y0 = y;
        if (y > y1)
            y1 = y;
    }
    long double ylen = y1 - y0;
    for (int i = 0; i < PL; i++)
    {
        curve[i] = sf::Vector2f(i+SX,( -(PH / ylen) * fun(x0 + ((xlen / PL) * i)) + (PH - y + y0) / 2)+SY);
        if (curve[i].position.y > SY + PH)
            curve[i].position.y = SY + PH;
        else if (curve[i].position.y < SY)
            curve[i].position.y = SY;
    }
    curves.push_back(curve);
}

void AnoraksMath::Plotter::clear()
{
    curves.clear();
}

void AnoraksMath::Plotter::setColors(vector<sf::Color> curvecolors, sf::Color bgc)
{
    bg->setFillColor(bgc);
    int c;
    if (curves.size() > curvecolors.size())
    {
        c = curvecolors.size();
    }
    else
    {
        c = curves.size();
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < curves[i].getVertexCount(); j++)
        {
            curves[i][j].color = curvecolors[i];
            
        }
    }
}


AnoraksMath::Plotter::~Plotter() {
    curves.clear();
}

void AnoraksMath::Plotter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*bg,states);

    for (int i = 0; i < curves.size(); i++)
        target.draw(curves[i]);
}

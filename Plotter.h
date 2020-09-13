#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
namespace AnoraksMath
{
	class Plotter : public Drawable
	{
	public:
		Plotter(int WindowL, int WindowH, int startY, int startX);
		void addfun(long double (*fun)(long double, long double), int x0, int x1, long double eps);
		void addfun(double (*fun)(double), int x0, int x1);
		void adfun(long double(*fun)(vector<long double>,vector<long double>,long double),vector<long double>xv,vector<long double>fv,long double);
		void clear();
		void setColors(vector<sf::Color>curvecolors,sf::Color bgc);
		~Plotter();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		float PL, PH,SY,SX;
		RectangleShape* bg = new RectangleShape(Vector2f(1, 1));
		vector<VertexArray>curves;
	};
}


#include <pthread.h>
#include <utility>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
namespace mymath {
    class mathfunctions
    {
    public:
        static long double sin(long double x,long double eps);
        static long double cos(long double x, long double eps);
        static long double ln(long double x, long double eps);
        static long double exp(long double x, long double eps);
        static long double lg(long double x,long double eps);
        static long double lAb(long double a,long double b,long double eps);
    };
    class plotter
    {
    public:
        plotter(int WindowL,int WindowH);
        void setfun(long double (*fun)(long double, long double),int x0,int x1, long double eps);
        void setfun(double (*fun)(double),int x0,int x1);
        void sleep();
        ~plotter();
    private:
        int WL,WH;
        static int num;
        sf::RenderWindow* window;
    };
}
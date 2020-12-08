#include<vector>
#include <string>
#include<cmath>

typedef long double (*fp)(long double,long double);
using namespace std;
struct fpn
{
    double n;
    fp f;
};
//
//
typedef long double (*aprc)(long double x, long double eps);
typedef long double (*syst)(long double x);
#define ln10 2.30258509299
//
//
namespace AnoraksMath
{
    class MathFuncs
    {
    public:
        enum sq{xi,ximin1,xminodnavtoraya};
        static long double sin(long double x, long double eps);
        static long double cos(long double x, long double eps);
        static long double ln(long double x, long double eps);
        static long double exp(long double x, long double eps);
        static long double lg(long double x, long double eps);
        static long double lAb(long double a, long double b, long double eps);
        static long double lagrange(vector<long double>fv,vector<long double>xv,long double x);
        static long double newtone(vector<long double> arrX,vector<long double> arrY,long double x);
        static long double newtone2(vector<long double> arrX,vector<long double> arrY,long double x);
        static long double ldif(vector<double>yi,int i, double h);
        static long double rdif(vector<double>yi,int i, double h);
        static long double cdif(vector<double>yi,int i, double h);
        static long double ddif(vector<double>yi,int i, double h);
        static long double tdif(vector<double>yi,int i, double h);
        static long double tdif2(vector<double>yi,int i, double h);
        static long double integralls(long double a, long double b, long double h, double (*fun)(double),sq sqQ);
        static long double integraltroph(long double a, long double b, long double h, double (*fun)(double));
        static long double the_Simpson(long double a, long double b, long double h, double (*fun)(double));
        static vector<double>Gaus(vector<vector<double>>matrixcof,vector<double>y);
        static vector<double>MNK(vector<double>x,vector<double>y,double  deg);


    private:
        static long int sum_0_to_N(long int N);
        //static long double iint (long double N);
    };
}
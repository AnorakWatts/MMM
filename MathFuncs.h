#include<vector>
#include <string>
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
        static long double sin(long double x, long double eps);
        static long double cos(long double x, long double eps);
        static long double ln(long double x, long double eps);
        static long double exp(long double x, long double eps);
        static long double lg(long double x, long double eps);
        static long double lAb(long double a, long double b, long double eps);
        static long double lagrange(vector<long double>fv,vector<long double>xv,long double x);
        //static long double slojno(long double x,string fun);
        static long double newtone(vector<long double> arrX,vector<long double> arrY,long double x);
        static long double ldif(vector<double>yi,int i, double h);
        long double rdif(vector<double>yi,int i, double h);
        long double cdif(vector<double>yi,int i, double h);
        long double ddif(vector<double>yi,int i, double h);
    private:
        static long int sum_0_to_N(long int N);
        //static long double iint (long double N);
    };
}
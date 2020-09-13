#include<vector>
using namespace std;
//
//
typedef long double (*aprc)(long double x, long double eps);
typedef long double (*syst)(long double x);
#define ln10 2.30258509299
//
//
namespace AnoraksMath
{
    class funcsforslojno
    {
    private:
        enum tp{apr,sys,cons};
        tp t;
        aprc ap;
        syst st;
        double c;
        friend MathFuncs;
    };
    class MathFuncs
    {
    public:
        static long double sin(long double x, long double eps);
        static long double cos(long double x, long double eps);
        static long double ln(long double x, long double eps);
        static long double exp(long double x, long double eps);
        static long double lg(long double x, long double eps);
        static long double lAb(long double a, long double b, long double eps);
        static long double slojno(long double x, long double eps,string st);
    };
}
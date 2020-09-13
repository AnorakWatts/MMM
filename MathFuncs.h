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
        static long double NEW_Ton();
    };
}
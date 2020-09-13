#include "MathFuncs.h"
#include<cmath>


long double AnoraksMath::MathFuncs::sin(long double x, long double eps) {

    double res = 0, cur = x, n = 1;
    while (fabs(cur) >= eps)
    {
        n += 2;
        res += cur;
        cur = (cur * (-1) * x * x) / (n * (n - 1));
    }
    return res;
}

long double AnoraksMath::MathFuncs::cos(long double x, long double eps) {
    long double res = 1, cur = (-(x * x)) / 2;
    int n = 2;
    while (fabs(cur) >= eps)
    {
        n += 2;
        res += cur;
        cur = (cur / (n * (n - 1))) * x * x * (-1);
    }
    return res;
}

long double AnoraksMath::MathFuncs::exp(long double x, long double eps) {
    long double res = 0, cur = 1, n = 0;
    while (fabs(cur) >= eps)
    {
        n += 1;
        res += cur;
        cur = (cur * x) / n;
    }
    return res;
}

long double AnoraksMath::MathFuncs::ln(long double x, long double eps) {
    int t = 0;
    bool uper1 = 0;
    if (x < 0)
    {
        return 0;
    }
    if (x == 1)
        return 0;
    while (x > 1)
    {
        uper1 = 1;
        x /= 10;
        t++;
    }
    x -= 1;
    long double res = 0, cur = x, n = 1;
    while (fabs(cur) >= eps)
    {
        n++;
        res += cur;
        cur = (n - 1) * (-1) * (cur * x) / n;
    }
    if (uper1)
        res += ln10 * t;
    return res;
}

long double AnoraksMath::MathFuncs::lg(long double x, long double eps) {
    long double res = (ln(x, eps) / ln10);
    return res;
}

long double AnoraksMath::MathFuncs::lAb(long double a, long double b, long double eps) {
    return ln(a, eps) / ln(b, eps);
}

long double AnoraksMath::MathFuncs::lagrange(vector<long double> fv, vector<long double> xv, long double x) {
    long double res,ch,zn;
    long int len;
    if(fv.size()<xv.size())
    {
        len=fv.size();
    }
    else
    {
        len=fv.size();
    }
    for(int i=0; i<len;i++)
    {
        ch=1;zn=1;
        for(int j=0;j<len;j++)
        {
            if(i!=j)
            {
                ch*=(x-xv[j]);
                zn*=(xv[i]-xv[j]);
            }
        }
        ch*=fv[i];
        res+=ch/zn;
    }
    return res;
}

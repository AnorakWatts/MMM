#include "MathFuncs.h"
#include <algorithm>
#include <iostream>
using namespace std;

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
    res=0;
    if(fv.size()<xv.size())
    {
        len=fv.size();
    }
    else
    {
        len=xv.size();
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

long double AnoraksMath::MathFuncs::newtone(vector<long double> arrX,vector<long double> arrY,long double x){
    int N;
    double res = arrY.at(0);
    double current = 1;
    if(arrX.size()>arrY.size())
        N=arrX.size();
    else
        N=arrY.size();
    vector<double> arrY0;
    for(int j=0;j<N;j++){

        for(int i=0;i<N-j-1;i++){
            arrY.at(i) = (arrY.at(i+1)-arrY.at(i))/(arrX.at(i+j+1)-arrX.at(i));
            if(i==0)
                arrY0.push_back(arrY.at(i));
        }

    }
    for (int i=0;i<N-1;i++){
        current = current*(x-arrX.at(i));
        res+=arrY0.at(i)*current;
    }
    return res;
}

long int AnoraksMath::MathFuncs::sum_0_to_N(long int N) {
    long int res=0;
    for(int i=1;i<N;i++)
        res+=i;
    return res;
}


long double AnoraksMath::MathFuncs::ldif(vector<double>yi,int i, double h) {
    return (yi[i]-yi[i-1])/h;
}

long double AnoraksMath::MathFuncs::rdif(vector<double> yi, int i, double h) {
    return (yi[i+1]-yi[i])/h;
}

long double AnoraksMath::MathFuncs::cdif(vector<double> yi, int i, double h) {
    return (yi[i+1]-yi[i-1])/(2*h);
}

long double AnoraksMath::MathFuncs::ddif(vector<double> yi, int i, double h) {
    return(yi[i+1]-2*yi[i]+yi[i-1])/(h*h);
}

long double AnoraksMath::MathFuncs::newtone2(vector<long double> arrX,vector<long double> arrY,long double x){
    int N;
    double res = arrY.at(0);
    double current = 1;
    if(arrX.size()>arrY.size())
        N=arrX.size();
    else
        N=arrY.size();
    vector<double> arrY0;
    for(int j=0;j<N;j++){

        for(int i=0;i<N-j-1;i++){
            arrY.at(i) = (arrY.at(i+1)-arrY.at(i))/(arrX.at(i+j+1)-arrX.at(i));
            if(i==0)
                arrY0.push_back(arrY.at(i));
        }

    }
    for (int i=0;i<N-1;i++){
        current = current*(x-arrX.at(i));
        res+=arrY0.at(i)*current;
    }
    return arrY0.at(arrY0.size()-1);
}

long double AnoraksMath::MathFuncs::integralls(long double a, long double b, long double h, double (*fun)(double),sq sqQ){
    long double res=0;
    switch (sqQ) {
        case sq::xi:
            break;
        case sq::ximin1: {
            a += h;
            b += h;
            break;
        }
        case sq::xminodnavtoraya:
        {
            a+=h/2;
            b+=h/2;
        }

    }
    for(double i=a;i<=b;i+=h)
    {
        res+=fun(i);
    }
    return res*h;
}

long double AnoraksMath::MathFuncs::integraltroph(long double a, long double b, long double h, double (*fun)(double)) {
    long double res=0;
    for(double i=a+h;i<=b-h;i+=h)
    {
        res+=fun(i);
    }
    return (res+(fun(a)+fun(b))/2)*h;
}

long double AnoraksMath::MathFuncs::the_Simpson(long double a, long double b, long double h, double (*fun)(double)) {
    double res=0;
    res+=fun(a);
    res+=fun(b);
    for(double i=a+0.5*h;i<=b-0.5*h;i+=h)
        res+=4*fun(i);
    for(double i=a+h;i<b;i+=h)
        res+=2*fun(i);
    return res*h/6;
}

long double AnoraksMath::MathFuncs::tdif(vector<double> yi, int i, double h) {
    return (yi[i+1]-3*yi[i]+yi[i-1]+yi[i-2])/pow(h,4);
}

long double AnoraksMath::MathFuncs::tdif2(vector<double> yi, int i, double h) {
    return ((ddif(yi,i+1,h)-(ddif(yi,i,h)))/(h*h));
}



vector<double> AnoraksMath::MathFuncs::Gaus(vector<vector<double>> matrixcof, vector<double> y) {
    vector<double>res;

    int max_a1;
    double curm;
    for(int pp=0;pp<matrixcof.size()-1;pp++) {
        curm = matrixcof[pp][pp];
        for (int i = pp; i < matrixcof.size(); i++) {
            if (matrixcof[i][pp] > curm) {
                curm = matrixcof[i][0];
                max_a1 = i;
            }
        }
        iter_swap(matrixcof.begin()+pp, matrixcof.begin() + max_a1);
        iter_swap(y.begin()+pp, y.begin() + max_a1);


        for (int i = pp; i < y.size(); i++) {
            y[i] /= matrixcof[i][pp];
        }

        for (int i = pp; i < matrixcof.size(); i++) {
            for (int j = pp + 1; j < matrixcof.size(); j++) {
                matrixcof[i][j] /= matrixcof[i][pp];
            }
            matrixcof[i][pp] = 1;
        }


        for (int i = pp + 1; i < matrixcof.size(); i++) {
            for (int j = pp; j < matrixcof[i].size(); j++) {
                matrixcof[i][j] -= matrixcof[pp][j];
            }
        }

        for (int i = pp + 1; i < y.size(); i++) {
            y[i] -= y[pp];
        }

    }
    y[y.size()-1]/=matrixcof[matrixcof.size()-1][matrixcof.size()-1];
    matrixcof[matrixcof.size()-1][matrixcof.size()-1]=1;

    res.resize(matrixcof.size());
    res[res.size()-1]=y[y.size()-1];
    double  curx;
    for(int i=matrixcof.size()-2;i>=0;i--)
    {
        curx=y[i];
        for(int j=i+1;j<res.size();j++)
        {
            curx-=matrixcof[i][j]*res[j];
        }
        res[i]=curx;
    }
    cout<<endl<<endl;
    return res;
}

vector<double> AnoraksMath::MathFuncs::MNK(vector<double> x, vector<double> y,double deg)
{
    int n=x.size();
    vector<double>res;
    vector<vector<double>>matx(deg+1,vector<double>(deg+1,0));
    vector<double>tomY(deg+1);

    for(int i=0;i<matx.size();i++)
        for(int j=0;j<matx[i].size();j++)
            if(i+j!=0)
                for(int z=0;z<x.size();z++)
                    matx[i][j]+=pow(x[z],i+j);

    matx[0][0]=n;

    for(int j=0;j<tomY.size();j++)
        if(j!=0)
            for(int z=0;z<x.size();z++)
                tomY[j]+=y[z]*pow(x[z],j);
    for(int z=0;z<x.size();z++)
        tomY[0]+=y[z];

    for (int i=0;i<matx.size();i++)
    {
        for(int j=0;j<matx[i].size();j++)
        {
            cout<<matx[i][j]<<"    ";
        }
        cout<<tomY[i];
        cout<<endl;
    }

    cout<<endl;
    res=Gaus(matx,tomY);

    return res;
}




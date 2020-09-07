#include "intf.h"
using namespace  std;
int main()
{

    mymath::plotter p(720,480);
    p.setfun(&mymath::mathfunctions::ln, 0, 10,0.001);
   mymath::plotter p1(720,480);
    p1.setfun(exp, -1, 1);
    getchar();
    for(double x=1;x<10;x+=0.1)
    {
        cout<<log(x)/log(6)<<"      "<<mymath::mathfunctions::lAb(x,6,0.0000001)<<endl;
        if(fabs(log(x)-mymath::mathfunctions::ln(x,0.0000001))>0.1)
            cout<<"HUY"<<endl;
    }
    return 0;
}
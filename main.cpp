#include "UICalc.h"
#include <unistd.h>
using namespace  std;
int main()
{
    std::vector<thread>t;
    mymath::plotter *ptr,*ptr1;
    ptr1= new mymath::plotter(720, 480);
    ptr= new mymath::plotter(720, 480);
    ptr->setfun(&sin, -1, 1);
    ptr1->setfun(&sin, -1, 1);
    std::thread plot(&mymath::plotter::sleep, ptr);
    std::thread plot1(&mymath::plotter::sleep, ptr1);
    plot.detach();
    plot1.detach();
    sleep(10);

}
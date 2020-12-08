#include "ui.h"
#include <unistd.h>
using namespace  AnoraksMath;
vector<vector<long double>>buildMHK(int points,vector<double>rres,double x0,double x1){
        vector<vector<long double>>res;
        res.push_back(vector<long double>());
        res.push_back(vector<long double>());
        for(double i=x0;i<x1;i+=(x1-x0)/points)
        {
            double xx=0;
            res[0].push_back(i);
            for(int j=0;j<rres.size();j++)
                xx+=rres[j]*pow(i,j);
            res[1].push_back(-xx);

        }
    return res;

};
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");
    Plotter p(0,0,1280,720);
    vector<double>x;
    vector<double>y;
    y.push_back(0.86603);
    y.push_back(1);
    y.push_back(0.86603);
    y.push_back(0.5);
    y.push_back(0);
    y.push_back(-0.5);
    x.push_back(-1);
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    vector<double>res=MathFuncs::MNK(x,y,3);
    vector<vector<long double>>buil=buildMHK(400,res,-10,10);
    p.addfun(buil[0],buil[1]);
    for(int i=0;i<x.size();i++)
    {
        p.addPoint(x[i],-y[i]);
    }

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<"  "<<endl;
    window.draw(p);
    window.display();
    sleep(1000);
}

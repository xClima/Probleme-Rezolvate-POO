
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include<iomanip>
#include<set>
#define PI 3.1415926535
using namespace std;
class Point2D{double x; double y;
public:

    Point2D(double x_in,double y_in){
        x=x_in;
        y=y_in;
    }
    float getx(){return x;}
    float gety(){return y;};
    Point2D(){
        x=0;
        y=0;
    }
    double distanceTo(Point2D anotherPoint){
        return sqrt(( x- anotherPoint.x)*( x- anotherPoint.x)+( y -anotherPoint.y)*( y- anotherPoint.y));
    }

    float ung(Point2D punct2, Point2D punct3){
        return acos((distanceTo(punct2)*distanceTo(punct2)+distanceTo(punct3)*distanceTo(punct3)-punct2.distanceTo(punct3)*punct2.distanceTo(punct3))/(2*distanceTo(punct2)*distanceTo(punct3)   ));

    }

};

int main(){
    int n;
    double x,y;
    cin>>n;

    vector<Point2D>vec;
    for(int i=0;i<n;i++){

        cin>>x>>y;
        vec.push_back(Point2D(x,y));
    }
    double dist = 0,aux;
    set<double>s;set<double>ss;
    aux=vec[n-1].distanceTo(vec[0]);
    for(int i=0;i<n-1;i++){
        dist =vec[i].distanceTo(vec[i+1]);
        if(aux+2>dist&&aux-2<dist){
            dist=aux;
        }
        s.insert(dist);

    }
    aux=vec[n-1].ung(vec[n-2],vec[n-3])*180/PI;
    for(int i=0;i<n-2;i++){
        
        dist =vec[i].ung(vec[i+1],vec[i+2])*180/PI;
        if(aux+2>dist&&aux-2<dist){
            dist=aux;
        }
        ss.insert(dist);

    }


    if(s.size()==1&&ss.size()==1){
        cout<<"DA";
    }else{cout<<"NU";}
    return 0;
}
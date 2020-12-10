#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;

class Puncte{
    public:double x,y;
    public: Puncte(double x_in,double y_in){
        x=x_in;
        y=y_in;
    }
};

int main(){
    vector<Puncte>vec;
    double a,b;
    char junk;
    while(cin>>a>>junk>>b){
        vec.push_back(Puncte(a,b));
    }
    double modul=0,x=0,y=0,out;
    for(int i=0;i<vec.size();i++){
        x+=vec[i].x;
        y+=vec[i].y;
    }
    modul+=sqrt(pow(x,2)+pow(y,2));
    for(int i=0;i<vec.size();i++){
        out=sqrt(pow(vec[i].x,2)+pow(vec[i].y,2));
        if(out>=modul&&vec[i].y<0){
            cout<<fixed<<setprecision(3)<<vec[i].x<<'i'<<fixed<<setprecision(3)<<vec[i].y<<'j'<<endl;
        }
        if(out>=modul&&vec[i].y>0){
            cout<<fixed<<setprecision(3)<<vec[i].x<<'i'<<'+'<<fixed<<setprecision(3)<<vec[i].y<<'j'<<endl;
        }
    }
    
}
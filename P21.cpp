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
    double result;
    for(int i=vec.size()-1;i>=0;i--){
        result=atan2(vec[i].y,vec[i].x)*180/M_PI;
        if(result>=0){
        cout<<"(r="<<fixed<<setprecision(3)<<hypot(vec[i].x,vec[i].y)<<"; phi="<<fixed<<setprecision(3)<<atan2(vec[i].y,vec[i].x)*180/M_PI<<')'<<endl;
            
        }else{cout<<"(r="<<fixed<<setprecision(3)<<hypot(vec[i].x,vec[i].y)<<"; phi="<<fixed<<setprecision(3)<<atan2(vec[i].y,vec[i].x)*180/M_PI+360<<')'<<endl;}
    }
}
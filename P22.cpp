#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;


class Puncte{
    public:double x,y,z;
    public: Puncte(double x_in,double y_in,double z_in){
        x=x_in;
        y=y_in;
        z=z_in;
    }
};
int main(){
    vector<Puncte>vec;

    double a,b,c;
    char x;
    int poz=959595;
    while(cin>>a>>x>>b){
    cin.get(x);
    if(x==';'){
        cin>>c;
        vec.push_back(Puncte(a,b,c));
        //cout<<a<<' '<<b<<' '<<c<<endl;
    }else{//cout<<a<<' '<<b<<endl;
        vec.push_back(Puncte(a,b,959595));
        
    }

    }
    double result,aux,altaux;
    for(int i=vec.size()-1;i>=0;i--){
        if(vec[i].z==959595){
        result=atan2(vec[i].y,vec[i].x)*180/M_PI;
        if(result>=0){
        cout<<"(r="<<fixed<<setprecision(3)<<hypot(vec[i].x,vec[i].y)<<"; phi="<<fixed<<setprecision(3)<<atan2(vec[i].y,vec[i].x)*180/M_PI<<')'<<endl;
            
        }else{cout<<"(r="<<fixed<<setprecision(3)<<hypot(vec[i].x,vec[i].y)<<"; phi="<<fixed<<setprecision(3)<<atan2(vec[i].y,vec[i].x)*180/M_PI+360<<')'<<endl;}}
        else{
            aux=vec[i].z/(sqrt(vec[i].x*vec[i].x+vec[i].y*vec[i].y+vec[i].z*vec[i].z));
            altaux=hypot(vec[i].x,vec[i].y);
            result=atan2(vec[i].y,vec[i].x)*180/M_PI;
        if(result>=0){
        cout<<"(r="<<fixed<<setprecision(3)<<hypot(altaux,vec[i].z)<<"; phi="<<fixed<<setprecision(3)<<atan2(vec[i].y,vec[i].x)*180/M_PI<<"; th="<<fixed<<setprecision(3)<<acos(aux)*180/M_PI<<')'<<endl;
            
        }else{cout<<"(r="<<fixed<<setprecision(3)<<hypot(altaux,vec[i].z)<<"; phi="<<fixed<<setprecision(3)<<atan2(vec[i].y,vec[i].x)*180/M_PI+360<<"; th="<<fixed<<setprecision(3)<<acos(aux)*180/M_PI<<')'<<endl;}
            
        }
    }
}
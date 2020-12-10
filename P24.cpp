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
    char junk;
    int poz=959595;
    while(cin>>a>>junk>>b){
        cin.get(junk);
        if(junk==';'){
            cin>>c;
            vec.push_back(Puncte(a,b,c));
            //cout<<a<<' '<<b<<' '<<c<<endl;
        }else{//cout<<a<<' '<<b<<endl;
            vec.push_back(Puncte(a,b,959595));

        }

    }
    double modul=0,x=0,y=0,out;
    for(int i=0;i<vec.size();i++){
        x+=vec[i].x;
        y+=vec[i].y;
    }
    modul+=sqrt(pow(x,2)+pow(y,2));
    for(int i=0;i<vec.size();i++) {
        if (vec[i].z == 959595) {
            out = sqrt(pow(vec[i].x, 2) + pow(vec[i].y, 2));
            if (out >= modul && vec[i].y < 0) {
                cout << fixed << setprecision(3) << vec[i].x << 'i' << fixed << setprecision(3) << vec[i].y << 'j'
                     << endl;
            }
            if (out >= modul && vec[i].y > 0) {
                cout << fixed << setprecision(3) << vec[i].x << 'i' << '+' << fixed << setprecision(3) << vec[i].y
                     << 'j' << endl;
            }
        } else{
            out = sqrt(pow(vec[i].x, 2) + pow(vec[i].y, 2)+pow(vec[i].z,2));
            if (out >= modul && vec[i].y < 0) {
                cout << fixed << setprecision(3) << vec[i].x << 'i' << fixed << setprecision(3) << vec[i].y << 'j'<<'+'<<fixed<<setprecision(3)<<vec[i].z<<'k'<< endl;
            }
            if (out >= modul && vec[i].y > 0) {
                cout << fixed << setprecision(3) << vec[i].x << 'i' << '+' << fixed << setprecision(3) << vec[i].y<< 'j' <<'-'<<fixed<<setprecision(3)<<vec[i].z<<'k'<< endl; 
            }

        }
    }

}
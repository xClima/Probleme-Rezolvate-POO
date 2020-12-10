#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include <sstream>

using namespace std;

struct Forma{
    string f;
    string l;
    double aria;

};



bool comp(Forma a,Forma b){
    return a.aria>b.aria;
}

int main(){
    vector<Forma>v;

    double l1,l2,l,r,n,aria;
    string forma,out;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>forma;
        if(forma=="cerc"){
            cin>>r;
            aria=r*r*3.14;
            stringstream stream;
            stream << fixed << setprecision(2) <<r;
            out=stream.str();
            v.push_back({forma,out,aria});
        }else
        if(forma=="patrat"){
            cin>>l;
            aria=l*l;
            stringstream stream;
            stream << fixed << setprecision(2) <<l;
            out=stream.str();
            v.push_back({forma,out,aria});
        }else
        if(forma=="dreptunghi"){
            cin>>l1>>l2;
            aria=l1*l2;
            stringstream stream;
            stream << fixed << setprecision(2) <<l1<<' '<<l2;
            out=stream.str();
            v.push_back({forma,out,aria});
        }
    }

    sort(v.begin(),v.end(),comp);
    for(int i=0;i<v.size();i++){
        cout<<v[i].f<<' '<<v[i].l<<endl;
    }


}
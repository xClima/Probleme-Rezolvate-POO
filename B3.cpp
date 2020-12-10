#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
    double hh,mm,out1,out2;
    char junk;
    cin>>hh>>junk>>mm;
    if(hh>12&&hh<=24){
        hh-=12;
    }
    if(hh==12){
        hh=0;
    }
    if(hh<12&&hh>=0&&mm<=60&&mm>=0){
        hh=hh+mm/60;
        hh=30*hh;
        mm=6*mm;
        out1=hh-mm;
        out2=mm-hh;
        if(max(out1,out2)<=180){
        cout<<fixed<<setprecision(0)<<max(out1,out2);}else{cout<<fixed<<setprecision(0)<<360-max(out1,out2);}
    
    }
    else{cout<<"error";}
}
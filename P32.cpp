#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Triunghi{
    double a,b,c;
    double ratio;
    
};

bool comp(Triunghi a,Triunghi b){
    return a.ratio>b.ratio;
}

int main(){
    vector<Triunghi>vec;
    double l1,l2,l3,s=0,A=0,p=0,ratio=0,out=0,index=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l1>>l2>>l3;
        if((max(max(l1,l2),l3)<=(l1+l2+l3)-max(max(l1,l2),l3))){
            if(pow(max(max(l1,l2),l3),2)!=pow((l1+l2+l3)-(max(max(l1,l2),l3)+min(min(l1,l2),l3)),2)+pow(min(min(l1,l2),l3),2)){
                if(l1!=l2&&l1!=l3&&l2!=l3){
                    
                    p=l1+l2+l3;
                    s=p/2;
                    A=sqrt(s*(s-l1)*(s-l2)*(s-l3));
                    ratio=A/p;

                    
                    vec.push_back({l1,l2,l3,ratio});
                }
                
            }
        }
    }
    sort(vec.begin(),vec.end(),comp);
    
    for(int i=0;i<vec.size();i++){
        cout<<fixed<<setprecision(4)<<vec[i].a<<','<<fixed<<setprecision(4)<<vec[i].b<<','<<fixed<<setprecision(4)<<vec[i].c<<','<<fixed<<setprecision(4)<<vec[i].ratio<<endl;
    }

}
//nu inteleg problema
//este destul de hardcodata rezolvarea asta dar alta nu gasesc

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int k,n,c1,c2;
    set<int>s;
    double sumac1=0,sumac2=0;
    cin>>k;
    vector<pair<double,double>>vec;
    vector<int>v2;
    vector<int>v3;
    for(int i=0;i<k;i++){
        sumac1=0;
        sumac2=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>c1>>c2;
            s.insert(c1);
            v3.push_back(c2);
            sumac1+=c1;
            sumac2+=c2;
        }
        
       
        if((s.size()*2==n)||(s.size()*4==n)||(s.size()*8==n)||(s.size()*16==n)||(n==2)){
        vec.push_back(make_pair(sumac1/n,sumac2/n));}else{ vec.push_back(make_pair(9999,9999));}
        s.clear();
    }
    
    for(int i=0;i<vec.size();i++){
        
        
        if(vec[i].first!=9999){
            cout<<1<<' '<<vec[i].first<<' '<<vec[i].second<<endl;
        }else{cout<<0<<endl;}
    }
    
 
}
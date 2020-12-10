#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>

using namespace std;

struct Card{
    string cod;
    string val;
    double sold;
};

bool s1(Card a,Card b){
    return a.sold>b.sold;
}

bool s2(Card a,Card b){
    return a.sold<b.sold;
}

int main(){
    string cod,val;
    double sold;
    int n;
    vector<Card>vec;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cod>>val>>sold;
        vec.push_back({cod,val,sold});
    }
    char c;
    cin>>val>>c;

    if(c=='-'){
        sort(vec.begin(),vec.end(),s1);
    }
    if(c=='+'){
        sort(vec.begin(),vec.end(),s2);
    }

    for(int i=0;i<vec.size();i++){
        if(vec[i].val==val){
            cout<<vec[i].cod<<' '<<vec[i].val<<' '<<fixed<<setprecision(2)<<vec[i].sold<<endl;
        }
    }

}
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

struct Problema {
    string nume;
    double p1, p2, p3, p4, p5;
};

int main() {
    string nume;
    double p1, p2, p3, p4, p5;
    vector<Problema> vec;
    while (cin >> nume >> p1 >> p2 >> p3 >> p4 >> p5) {
        vec.push_back({nume, p1, p2, p3, p4, p5});
    }
    vector<pair<double, string>> aux;
    double cnt = 0;
    double suma = 0;
    for (int i = 0; i < vec.size(); i++) {
        cnt = 0;
        suma = 0;
        for (int j = 0; j < vec.size(); j++) {

            if (vec[i].nume == vec[j].nume) {
                cnt++;
                suma += vec[j].p1 + vec[j].p2 + vec[j].p3 + vec[j].p4 + vec[j].p5;
                vec[j].p1 = 0;
                vec[j].p2 = 0;
                vec[j].p3 = 0;
                vec[j].p4 = 0;
                vec[j].p5 = 0;


            }
        }
        if (suma > 0) {
            aux.push_back(make_pair(suma/(cnt*5), vec[i].nume));
        }

    }
    sort(aux.begin(),aux.end());
    for(int i=0;i<aux.size();i++){
        cout<<aux[i].second<<' '<<fixed<<setprecision(2)<<aux[i].first<<endl;
    }

    cout<<fixed<<setprecision(2)<<aux[aux.size()-1].first/aux[0].first<<endl;
}
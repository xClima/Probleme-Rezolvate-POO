#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
class Masina
{
    string mtip;

public:
    Masina(){
        
    }
    
    Masina(string tip){
        mtip = tip;
    }
    
    virtual float calculeazaCost(){
        return 0;
    }
    
    virtual void print()
    {
        
    }
    
};

class Diesel: public Masina
    {
        float cantitate;
        
        public:
                Diesel(float cantitate_in)
                :Masina("diesel")
                {
                    cantitate = cantitate_in;
                }
                
        float calculeazaCost()
        {
            return 6*cantitate;
        }
        
        void print(){
             printf("diesel %.2f\n",cantitate);
             //cout<<"diesel"<<cantitate<<"\n";
        }
        
    } ;           

class Benzina: public Masina
    {
        float cantitate;
        
        public:
                Benzina(float cantitate_in)
                :Masina("benzina")
                {
                    cantitate = cantitate_in;
                }
                
        float calculeazaCost()
        {
            return 5.8*cantitate;
        }
        
        void print(){
            printf("benzina %.2f\n",cantitate);
            //cout<<"benzina"<<cantitate<<"\n";
        }
    };
    
class Hibrida: public Masina
    {
        float cantitate1;
        float cantitate2;
        
        public:
                Hibrida(float cantitate1_in, float cantitate2_in) :Masina("hibrid")
                {
                    cantitate1 = cantitate1_in;
                    cantitate2 = cantitate2_in;
                }
                
        float calculeazaCost()
        {
            return 5.8*cantitate1 + 1*cantitate2;
        }
        
        void print(){
            //cout<<"hibrid"<<cantitate1<<cantitate2<<"\n";
            printf("hibrid %.2f %.2f\n",cantitate1,cantitate2);
        }
    };
    
bool myfunction(Masina * m1, Masina * m2)
{
    return m1->calculeazaCost() < m2->calculeazaCost();
}

int main()
{
    std::vector<Masina *> masini;
    string tip_citit;
    int nr_masini;
    float cant_combustibil_citit,cant1_combustibil_citit,cant2_combustibil_citit;
    cin >> nr_masini;
    
    for(int i = 0; i< nr_masini; i++)
    {
        cin >> tip_citit;
        if(tip_citit == "benzina")
        {
            cin >> cant_combustibil_citit;
            masini.push_back(new Benzina(cant_combustibil_citit));
        }
        
        if(tip_citit == "diesel")
        {
            cin >> cant_combustibil_citit;
            masini.push_back(new Diesel(cant_combustibil_citit));
        }
        
        if(tip_citit == "hibrid")
        {
            cin >> cant1_combustibil_citit >> cant2_combustibil_citit;
            masini.push_back(new Hibrida(cant1_combustibil_citit, cant2_combustibil_citit));
        }
    }
    //cout << "bla1";
    std::sort(masini.begin(), masini.end(), myfunction);
    
    for(int i=0; i<nr_masini; i++){
    masini[i]->print();
    //cout << "bla1";
    }
}
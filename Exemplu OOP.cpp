#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

class nr_complex
{
    int real;
    int imaginar;
    
    public: nr_complex()
{
    real=0;
    imaginar=0;
}
public: nr_complex(int arg_real, int arg_in){
    real=arg_real;
    imaginar=arg_in;
    
}
int get_real(){
    return real;
}
int get_imaginar(){
    return imaginar;
}
void set_real(int arg_in){
real=arg_in;
    
}

void set_imaginar(int arg_in){
    imaginar=arg_in;
    
}

double calc_modul(){
    return sqrt(static_cast<double>(real)*real +static_cast<double>(imaginar)*imaginar);
    
    
}

nr_complex produs(nr_complex arg_nr_in)
{
    nr_complex temp;
    temp.set_real(real*arg_nr_in.get_real() - imaginar*arg_nr_in.get_imaginar());
    temp.set_imaginar(real*arg_nr_in.get_imaginar() + imaginar*arg_nr_in.get_real());
    return temp;
}

    
    void print(){
        printf("%d+%di",real,imaginar);
        
    }
};
    
    
    
    int main()
    {
        vector<nr_complex> my_vector;
        int a,b;
        nr_complex best_result;
        while(scanf("%d,%d",&a,&b)!=EOF)
        {
            my_vector.push_back(nr_complex(a,b));
        }
        
        best_result.set_real(0);
        best_result.set_imaginar(0);
        
        
        for(int i=0;i<my_vector.size()-1;i++){
              for(int j=i+1;j<my_vector.size();j++){
            if(my_vector[i].produs(my_vector[j]).calc_modul()>best_result.calc_modul())
            {
                best_result=my_vector[i].produs(my_vector[j]);
            }
            
        }
        
        
    }
best_result.print();
}


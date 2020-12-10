//prima mea problema facuta vreodata...
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <regex>
using namespace std;
class Parola
{
           /* if (sum_of_positive_results < 3){ //not enough booleans were true!
                std::cout << "NOK"<<endl;
            }
            else{ //otherwise it's valid!
                std::cout << "OK" << std::endl;
                
            }
        }
*/
    

  
  


        

        /*
           std::string line;
            while (std::getline(std::cin, line))
                {
                 if(line.size()>min_length_citit&&line.size()<max_length_citit)
               
                 
                 {cout<<"OK"<<endl;}else {cout<<"NOK"<<endl;}
                }*/
    string mtip;

public:
    Parola(){
        
    }
    
    Parola(string tip){
        mtip = tip;
    }};
     class Lungime: public Parola
    {
    int min_length,max_length;
    public:
                Lungime(int min_length_in,int max_length_in) :Parola("length")
                {
                    min_length = min_length_in;
                      max_length = max_length_in;
                  
                }
    };
    
     class Lungime2: public Parola
    {
    int qmin_length;
    public:
                Lungime2(int qmin_length_in) :Parola("length")
                {
                    qmin_length = qmin_length_in;
                  
                }
    };

        class Clasa: public Parola
    {
    int min_class_count;
    public:
                Clasa(int min_class_count_in) :Parola("class")
                {
                    min_class_count = min_class_count_in;
                
                }
    };
    
        class Include: public Parola
    {
    string include;
    public:
                Include(string include_in) :Parola("include")
                {
                   include=include_in;
                }
    };
            class nInclude: public Parola
    {
    string ninclude;
    public:
                nInclude(string ninclude_in) :Parola("ninclude")
                {
                   ninclude=ninclude_in;
                }
    };
            class Repetitie: public Parola
    {
    int repetitie;
    public:
                Repetitie(int repetitie_in) :Parola("repetition")
                {
                   repetitie=repetitie_in;
                }
    };
            class Consecutiv: public Parola
    {
    int consecutive;
    public:
                Consecutiv(int consecutive_in) :Parola("consecutive")
                {
                   consecutive=consecutive_in;
                }
    };




int main()
{   
    std::vector<Parola* > parole;
    string tip_citit,include_citit,ninclude_citit;
    int o,nr_reguli,min_length_citit=0,min_class_count_citit=0,consecutive_citit=999,repetition_citit=999,max_length_citit=9999;
    cin >> nr_reguli;
    for(int i=0;i<=nr_reguli;i++){
        cin>>tip_citit;
        
        if(tip_citit=="length"){


    
   

        
        cin>>min_length_citit>>max_length_citit;
        parole.push_back(new Lungime(min_length_citit,max_length_citit));
  if(!cin) // or if(cin.fail())
{
    // user didn't input a number
    // reset failbit
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    cin.clear(); 
    parole.push_back(new Lungime2(min_length_citit));
    max_length_citit=999;
   
}

   
   
        
    }
            
        if(tip_citit=="class"){
            cin>>min_class_count_citit;
            parole.push_back(new Clasa(min_class_count_citit));
        }
        if(tip_citit=="include"){
            cin>>include_citit;
            parole.push_back(new Include(include_citit));
        }
        if(tip_citit=="ninclude"){
            cin>>ninclude_citit;
            parole.push_back(new nInclude(ninclude_citit));
        }
        if(tip_citit=="repetition"){
            cin>>repetition_citit;
            parole.push_back(new Repetitie(repetition_citit));
        }
        if(tip_citit=="consecutive"){
            cin>>consecutive_citit;
            parole.push_back(new Consecutiv(consecutive_citit));
        }}
        
bool upper_case = false; 
    bool lower_case = false; 
    bool number_case = false; 
    bool special_char = false;
    std::regex upper_case_expression{ "[A-Z]+" };
    std::regex lower_case_expression{ "[a-z]+" };
    std::regex number_expression{ "[0-9]+" };
    std::regex special_char_expression{ "[@!?#$%^&*()]+"};
 std::string pw;
           
            while (std::getline(std::cin, pw))
                {
                    upper_case = std::regex_search(pw, upper_case_expression); 
    lower_case = std::regex_search(pw, lower_case_expression); 
    number_case = std::regex_search(pw, number_expression);
    special_char = std::regex_search(pw, special_char_expression);
      int sum_of_positive_results = upper_case + lower_case + number_case + special_char;
                   
                   
                   
    int max = 0;
    int count = 0;
    string maxCharacter;
    for(char q=' ';q<='~';q++)
        
    {
        count = 0;
        for(unsigned int i=0; i<pw.length();i++)
        {
            if(pw[i]==q)
                count++;
        }
        
        if(count == max)
        {
            maxCharacter += q;
        }
        
        if(count>max)
        {
            max=count;
            maxCharacter=q;
             
        }

      
    } 
        int len=1;
        int index=0;
        int maxlen=0;
        int maxlenstart=0;
    for(int i=0;i<pw.length();i++){
       
        if(pw[i+1]==pw[i]+1)
        {
            if(i==len)
            index=i;
            if(++len>maxlen){
                maxlen=len;
                maxlenstart=index;
            }
        }
        else len=1;
    }
  // cout<<sum_of_positive_results<<" "<<min_class_count_citit<<endl;
    
     if(pw.size()<min_length_citit){cout<<"NOK"<<endl;}else{if(pw.size()>max_length_citit){cout<<"NOK"<<endl;}else{ if(max>repetition_citit){cout<<"NOK"<<endl;}
   else{if(sum_of_positive_results< min_class_count_citit){cout<<"NOK"<<endl;}else{if(maxlen>consecutive_citit){cout<<"NOK"<<endl;}
    else{cout<<"OK"<<endl;}}}}}
               
    }
}
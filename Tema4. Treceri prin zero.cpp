
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

float s[1000] ;
float ma[1000];
float d[1000],d1[1000];
float b[1000],b1[1000];

int main()
{
    int i,j,k,p=0,w,n,nr=0,nr1=0,p1=0,p2=0, sum;
    float v[1000];
    float ma1;
    cin>>n;
    for(i=0;i<n;i++)
    {
      cin>>v[i];
    }
    cin>>w;
    int nrFerestre,ok,rest;
    if(n%w == 0)
    {
        nrFerestre = n/w;
        ok=1;
    }
    else
    {
        nrFerestre = n/w;
        rest = n%w;
        ok=0;
    }
    
    int contor=0;
    k = 0; // inainte sa parcurg vectorul initial
    
    for(i=0;i<nrFerestre*w;i=i+w) // parcurg vectorul din w in w
     {   
         sum=0; // inainte sa intru intr-o fereastra
         for(j=0;j<w;j++)
         {  
             sum=sum+v[j+contor*w];  // suma elementelor dintr-o fereastra
         }
         ma[contor]=(float)sum/(float)w; // o ma este asociata unei ferestre
         contor++;
     }
     
   
    
    contor = 0;
    for(i=0;i<nrFerestre*w;i=i+w)
    {
        for(j=0;j<w;j++)
        {
            d[j+contor*w]=v[j+contor*w]-ma[contor];
           
        }
        contor++;
    }
    
   
    
    p=0; 
    
    contor = 0; // contor e asociat intregului vector initial 
    
    for(i=0;i<nrFerestre*w;i=i+w)
     {   
         nr=0;
         for(j=0;j<w-1;j++) // (w-1) pt ca trebuie sa imi citeasca si urmatorul, deci merg pana la penultimul
         { 
             if(  (d[j+contor*w]>0) && (d[j+contor*w+1]<0) ||  (d[j+contor*w]<0) && (d[j+contor*w+1]>0)  )
             {
                nr++; // nr e asociat fiecarei ferestre
             }
         }
         b[p]=nr;
         p++;
         contor++;
     }
     
     for(i=0;i<p;i++)
     {
         cout<<b[i]<<endl;  // AFISARE NR TRECERI PRIN ZERO Partea I
     }
     
     
     
     float ma_rest=0;
     sum = 0;
     float vectorRest[1000];
     int nrTreceri0Rest;
     nrTreceri0Rest = 0;
     contor = 0;
    
     if(ok == 0)// daca nu se imparte perfect mai adaug si partea asta
     {
         for(i=nrFerestre*w;i<=nrFerestre*w + rest;i++)
         {
             sum = sum + v[i]; // suma
         }
         
         ma_rest = (float)sum/(float)rest; // media
         
         for(i=nrFerestre*w;i<nrFerestre*w+rest;i++)
         {
               vectorRest[contor] = v[i] - ma_rest; // diferenta
               contor++;
         }
       
         for(i=0;i<contor-1;i++)
         {
             if( (vectorRest[i] >0)&&(vectorRest[i+1]<0) ||  (vectorRest[i]<0)&& (vectorRest[i+1]>0)  )
            {
                nrTreceri0Rest++;
            }
         }
         cout<<nrTreceri0Rest<<endl;
     }
    


}
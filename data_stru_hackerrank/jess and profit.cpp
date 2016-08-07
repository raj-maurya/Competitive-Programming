#include <cmath>
#include<list>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
            int b=0,c=0, o, oo;
    int N, D,i,j,p;
    int Ni[100], Di[10];
    cin>>N>>D;
    int numbers[10];
   
    int smallestNumber;
   
    int m=0;
    for(i=0; i<N; i++){
        cin>>Ni[i];
    }
    for(i=0; i<D; i++){
        cin>>Di[i];
    }
    int t=0;
    
     int kik[10];
    int kis[10];
    
    for(j=0; j<D; j++){
       int z=0, c=0;
       
        for(i=0; i<N; i++){
            
            for(int k=0; k<N; k++){
                if(i>=k){
                 
                t=Ni[i]-Ni[k]; 
              //  cout<< "\n"<<t;
                }
            
          if(t==Di[j]){
             // cout<<t<<"start"<<k+1<<"end"<<i+1<<"\n"<<endl;
              m=i+1 - k-1;
                            numbers[z]=m;
              kik[z]=k+1;
              kis[z]= i+1;
            //  cout<<m<<"space"<<"\n"<<endl;
            z++;
       
          }
              
            }
 
        }
      //  cout<<"count"<<z<<"\n";
      smallestNumber= numbers[0];
b=0;
        
    for (p=0 ; p<z; p++)
            {

                if (numbers[p] < smallestNumber) 
                      {
                    smallestNumber= numbers[p];
                    b=p;
                      }
             
                    }
                
        // cout<<"numcers"<<b+1<<"for"<<smallestNumber<<"numbers"<<"value=";
        cout<<kik[b]<<" "<<kis[b]<<endl;
       
              //   for (p=0 ; p<z; p++){
                //     cout<<"numcers"<<numbers[p]<<"numbers";
                     
                // }    
        
    }
    
    return 0;
}


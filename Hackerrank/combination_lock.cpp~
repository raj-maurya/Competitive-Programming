#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int j,k;
    int i, a[6],b[6];
    for(i=0; i<5; i++){
        cin>>a[i];
    }
    
    for(j=0; j<5; j++){
        cin>>b[j];
    }
    int t=0;
  for(k=0; k<5; k++){
      if(abs(a[k]-b[k])>6){
          t=t+(5-b[k]);
          //cout<<t<<endl;
      }
      else{
         t=t+ abs(a[k]-b[k]); 
         // cout<<t<<endl;
      }
  }
     cout<<t<<endl;
    
    return 0;
}


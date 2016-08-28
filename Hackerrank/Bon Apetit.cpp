#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int n, k,b;
    int i,j;
    cin>>n>>k;
    int t=0;
    
    int a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>b;
    
    for(j=0; j<n; j++){
        if(j==k){
            t=t+0;
        }
        else{
            t=t+a[j];
        }
    }
    
    int p=t/2, l;
    
    if(p==b){
        cout<<"Bon Appetit";
    }
    else{
        l=b-p;
         cout<<l<<endl;
    }
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


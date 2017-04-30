//zigzag_array.cpp
#include <bits/stdc++.h>

using namespace std;

int minimumDeletions(vector < int > a){
    // Complete this function
    
   int k, l=0, m=0;
   k=a.size();
    for(int i=0; i<k-2; i++ ){
       // cout<<a[i]<<a[i+1]<<a[i+2]<<k<<endl;
        if(a[i]>a[i+1] && a[i+1]>a[i+2]){
          //  cout<<a[i]<<a[i+1]<<a[i+2]<<endl;
           m=m+1; 
           //cout<<m<<"m"<<endl; 
        }
        
       else if(a[i]<a[i+1] && a[i+1]<a[i+2]){
           l=l+1; 
          // cout<<l<<"l"<<endl;
        }
        else{
            m=m;
            l=l;
        }
      
    }
   
   if((m+l)>=1)
       return (m+l);
   else
       return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    // Return the minimum number of elements to delete to make the array zigzag
    int result = minimumDeletions(a);
    cout << result << endl;
    return 0;
}

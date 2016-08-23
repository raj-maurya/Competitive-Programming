#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int a[26];
    int i,j,t;
    char b[15];
    int max=0;
    
    for(i=0; i<26; i++){
        cin>>a[i];
    }
    string s;
    cin>>s;

    for(j=0; j<s.size(); j++){
        if(a[j]>max){
            max=a[j];
        }
    }
   // cout<<"\n"<<max;
    t=s.size() * 1* max;
    cout<<t<<endl;
    return 0;
}


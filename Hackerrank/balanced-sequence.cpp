#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include<bits/stdc++.h>
using namespace std;

 
int subs(string str)
{
    int n = str.length();

    stack<int> stk;
    stk.push(-1);

    int result = 0;
 
    for (int i=0; i<n; i++)
    {
    
        if (str[i] == '(')
          stk.push(i);
 
        else
        {
            stk.pop();
 
           
            if (!stk.empty())
       
                 result=result+1;
 
            else stk.push(i);
        }
    }
 
    return result*2;
}

int main()
{
    int t,i,j;
     string s;
    cin>>t;
    for(i=0; i<t; i++){
        cin>>s;
          cout << subs(s) << endl;
    }

    return 0;
}


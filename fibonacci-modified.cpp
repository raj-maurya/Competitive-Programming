#include<iostream>
using namespace std;

int main()
{
unsigned long long int n,p,k,first,second;
cin>>first;
cin>>second;

cin>>n;



int i;
for(i=3; i<=n; i++)
{
k=second*second+first;
first=second;
second =k;
}

cout<<k;
return 0;
}


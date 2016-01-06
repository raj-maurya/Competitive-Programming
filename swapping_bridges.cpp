#include<iostream>
using namespace std;

int main()
{
int  a[50000],n, i,t,j,k=0;
cin>>t;
int p[10],m;
for(i=1; i<=t; i++)
{
cin>>n;
for(j=1; j<=n; j++)
{
cin>>a[j];

}
if(n>3)
{
p[i]=n-3;
}
else
{
 p[i] = 0;
}
}
for(i=1; i<=t; i++)
{
cout<<p[i];
cout<<"\n";

}

}

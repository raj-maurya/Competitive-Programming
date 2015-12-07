#include<iostream>
using namespace std;

int main()
{
int a[3],b[100],i,j,n,t,k;
cin>>t;
for( i=1; i<=t; i++)
{
for(j=1; j<=3; j++)
{
cin>>a[j];
}
for(k=1; k<=a[1]; k++)
{
cin>>b[k];
}
if(a[2]==b[1] && a[3]==b[a[1]])
{
cout<<"BOTH";
}
else if(a[2]==b[1])
{
cout<<"EASY";
}
else if(a[3]==b[a[1]])
{
cout<<"HARD";
}
else
cout<<"OKAY";
}
}

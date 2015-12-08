#include<iostream>
using namespace std;

int main()
{
long long a,m=0,n=0 ,i, j,t;
//cout<<"enter t";
cin>>t;
t=t+1;
for(i=1; i<=t; i++)
{
if(i%2==0)
{
for(j=i+1; j<=t+1; j++)
{
//if(j%2==0)
//cout<<"";
//else
//cout<<"";
m++;
}
//cout<<"\n";
}
else
{
for(j=i+1; j<=t+1; j++)
{
//if(j%2!=0)
//cout<<"";
//else
//cout<<"";
n++;
}
//cout<<"\n";
}
}
//cout<<n<<"\n";
cout<<n-1;
}

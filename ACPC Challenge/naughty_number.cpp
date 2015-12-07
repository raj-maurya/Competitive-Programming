#include<iostream>
using namespace std;

int main()
{
int i,j,a[100], b[101],n;
int k,l,no;
cin>>n;
for(i=1; i<=n; i++)
{
cin>>a[i];
}
for(j=1; j<=n+1; j++)
{
cin>>b[j];
}
for(k=1; k<=n+1; k++)
{
for(l=1; l<=n; l++)
{
if(b[k]==a[l])
{
no=0;
break;
}
else
{
no=1;
continue;
}
}
if(no==1)
cout<<b[k];
}
}

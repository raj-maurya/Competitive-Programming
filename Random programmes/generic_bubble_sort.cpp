#include<iostream>
using namespace std;

template <class x> void sot(x *a[])

{
x i,pass,temp;
for(pass=0; pass<5; pass++)
for(i=1; i<5; i++)
{
if(a[i]>a[i+1])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
}
for(i=0; i<5; i++)
{
cout<<a[i];
}
}

int main()
{
int i,a[5];
for(i=0; i<5; i++)
{
cin>>a[i];
}
sot(a[i]);
}

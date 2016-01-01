#include<iostream>
using namespace std;

void divide(int a,int b)
{
if(b!=0)
{
int k;
k=a/b;
cout<<" remainder"<<k<<"\n";
}
else
throw 1;
}
int main()
{
try{
divide(15,3);
divide(5,0);
}
catch(int i)
{
cout<<"there is the exception";
}
}

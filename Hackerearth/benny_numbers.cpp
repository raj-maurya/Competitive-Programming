#include <iostream>
using namespace std;

int main()
{
     int i,j,n,f,m;
    long int a[1000];

    cin>>n;
    for(i=0; i<n; i++){
    	cin>>a[i];
    }
   for(i=0;i<n;i++)
{
f=0;
for(j=2;j<a[i];j++)
{

if(a[i]%j==0)
{
f=1;
cout<<"No"<<endl;
}
}
if(f==0)
cout<<"Yes"<<endl;
}
    return 0;
}

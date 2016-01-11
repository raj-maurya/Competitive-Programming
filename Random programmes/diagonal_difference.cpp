#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int i,j,n, a[200][200],k=0,l=0;

cin>>n;

for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
cin>>a[i][j];
}

}

for(i=0; i<n; i++)
{
k=k+a[i][i];
l=l+a[i][n-i-1];
}
cout<<abs(k-l);
}

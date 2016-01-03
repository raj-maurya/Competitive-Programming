#include<iostream>
using namespace std;

main()
{

int a[100][100],b[100][100],c[100][100];
int i,j,m,n;
cout<<"\n enter the 1st matrix";
cout<<" \n enter the no of rows:";
cin>>i;
cout<<" \n enter the no of columns:";
cin>>j;

for(m=0; m<i; m++)
	for(n=0; n<j; n++)

cin>>a[m][n];

for(m=0; m<i; m++)
{
cout<<" \n ";
	for(n=0; n<j; n++)
cout<<" " <<a[m][n];
}

cout<<"enter the 2nd matrix";
cout<<"\nno. of rows"<<i;
cout<<"\n no. of columns"<<j;

for(m=0; m<i; m++)
        for(n=0; n<j; n++)

cin>>b[m][n];

for(m=0; m<i; m++)
{
cout<<" \n ";
        for(n=0; n<j; n++)
cout<<" " <<b[m][n];
}

for(m=0; m<i; m++)
        for(n=0; n<j; n++)

c[m][n]=a[m][n]+b[m][n];
cout<<"\n the addition of matrix is:";
for(m=0; m<i; m++)
{
cout<<" \n ";
        for(n=0; n<j; n++)
cout<<" " <<c[m][n];
}
}

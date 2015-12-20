#include<iostream>

using namespace std;

int main()
{

int i;
int  j;
int data;
cout<<"Enter the no of data you want to  enter";

cin>>j;
cout<<"now enter your data";


for(i=0; i<j; i++)
{
cin>>data;
}

int mean=0;
for(i=0; i<j; i++)
{
mean=mean+data;
}

cout<<"the mean of the data sample is"<<float(mean/j);
}

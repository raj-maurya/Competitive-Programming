#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
	    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	   string arr[1000];
	cin>>n;
for(int i=0; i<n; i++)
{
	cin>>arr[i];
}	
	int m;
	cout<<"enter next number";
	string arr1[1000];
	cin>>m;
for(int j=0; j<m; j++)
{
	cin>>arr1[j];
}
int p=0;
for( int x=0; x<m; x++)
{
	for(int y=0; y<n; y++)
	{
		if(arr1[x]==arr[y]){

			p++;}
	}
	cout<<p<<"\n";
	p=0;
}
//	return 0;
}

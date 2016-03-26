#include<iostream>
#include<math.h>
using namespace std;

int main()

{
	int i,j,n,a,t,e;
	cin>>t;
	
//	cout<<pow(a,e);
	for(i=0; i<t; i++)
	{cin>>a>>e;
		int temp=0;
		for(j=1; j<=a; j++)
		{
			n=pow(j,e);
			temp +=fmod((pow((j-1),n)+pow((j+1),n)),n) ;


		}
	cout<<fmod(temp,(pow(10,9)+7));
	}	
}

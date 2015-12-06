#include<iostream>
using namespace std;

int main()
{
long 	int i,j,k,l=0,m=0;
long	int n,a,b;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>a>>b;
	
		if(a==b)
		{
			cout<<"1";
		}
		
	if(a>b)
	{
		for(j=1; j<=b; j++)
		{
			if((a*b)%(j*j)==0)
				m=j;
		}
		cout<<"\n"<<m;
	}
	if(b>a)
	{
		{
			                for(j=1; j<=a; j++)
						                {
								   if((a*b)%(j*j)==0)
								    l=j;
								 }
					cout<<"\n"<<l;
		 }

	}
}
}

#include<iostream>
using namespace std;

int main()
{
	int a,b,c,i,j;

	//int test=0;
	int n,m;
	cin>>m;
	for(i=1; i<=m; i++){
	int sum=0;
	cin>>n;
	for(i=2; i<=n; i++)
	{
		int test=0;
	//	cin>>m;
		for(j=1; j<=i; j++)
		{
			cin>>a;
			if(a>test)
			{
				test=a;
			}
		//	cout<<"max="<<test;
	//		cout<<test<<"test";
		}
		cout<<"max="<<test;

	//	if(i==1)
	//		sum=0;
	//	else{
			sum= sum+test;
	//	}
	//cout<<"sum"<<sum;
		
	}
//	cout<<sum;
	}
	return 0;
}


#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define k long double

inline k distance(k a,k b,k c,k d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int x[1000],y[1000];

int main()
{
	int z;
    cin>>z;

    for(int i=1;i<=z;i++)
    	cin>>x[i]>>y[i];

    k mn=-1;

    for(int i=1;i<=z;i++)
    for(int j=i+1;j<=z;j++)
    {
    	mn=max(mn,distance(x[i],y[i],x[j],y[j]));
    }

    k squarert=sqrt(2.0);
    k result=mn/squarert;

    printf("%.4LF",result);


	return 0;
}

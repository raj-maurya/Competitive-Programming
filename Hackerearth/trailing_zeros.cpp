#include <iostream>
using namespace std;


int trail(int n)
{
	int k=0;
	for(int i=5; i<n; i=i*5)
	k=k+n/i;

	return k;
}

int main()
{
  int n;
  cin>>n;
  cout<<trail(n);
    return 0;
}

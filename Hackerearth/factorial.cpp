#include <iostream>
using namespace std;

int main()
{

	int n,i,k=1;
	cin>>n;
	for(i=1; i<=n; i++){
		k=k*i;
	}
    cout << k << endl;
    return 0;
}

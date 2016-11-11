#include <iostream>
#include<string>

using namespace std;

int main()
{
	char a[100];
	cin>>a;
	string b=a;
	int i, j;
	j=end(b)-begin(b);
	//cout<<j;
	for(i=0; i< j; i++){
		if(a[i]>=97 && a[i]<=122){
			a[i]=a[i]-32;
		}

		else{
			a[i]=a[i]+32;
		}
	}
    cout <<a << endl;
    return 0;
}

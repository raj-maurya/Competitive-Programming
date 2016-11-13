#include <iostream>
using namespace std;

int main()
{
    int i,j,n,m, arr[100][100], dup[100][100];
    cin>>n>>m;
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		cin>>arr[i][j];
    	}
    }
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		dup[j][i]=arr[i][j];
    	}
    }
    for(int i=0; i<m; i++){
    	for(int j=0; j<n; j++){  		
    		cout<<dup[i][j]<<" ";
    		 if(j==n-1)
            cout << endl;
    	}

    }
    return 0;
}

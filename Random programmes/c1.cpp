#include <iostream>
#include <vector>
#include <cstdlib>
#include<fstream>
#include <cmath>

using namespace std;


template<class T>
void comp(vector<T> v1, vector<T> v2){
	if(v1.size() != v2.size()){
		cout << "vectors not the same size\n";
		exit(1);
	}
}


template<class T>
double cosine(vector<T> v1, vector<T> v2){
	comp(v1, v2);

	T lv1 = v1[0] * v1[0];
	T lv2 = v2[0] * v2[0];
	T dot12 = v1[0] * v2[0];

	for (unsigned int i=0; i < v1.size(); i++){
		lv1 += v1[i] * v1[i];
		lv2 += v2[i] * v2[i];
		dot12 += v1[i] * v2[i];
	}
	return double(dot12) / ( sqrt(double(lv1)) * sqrt(double(lv2)) );
}


int main()
{
ifstream in("yfile"); // input
if(!in) {
cout << "Cannot open INVENTORY file.\n";
return 1;
}

//int  tellg( );
ofstream out("yfile");
if(!out)
{
cout<<"can not open";
return 1;
}
vector<int> aX(4); aX[0] = 1; aX[1] = 1; aX[2] = 1; aX[3] = 1;
	vector<int> aY(4); aY[0] = 2; aY[1] = 2; aY[2] = 2; aY[3] = 2;

cout << "a. cosine: " << cosine(aX, aY) <<endl;

in.close();
out.close();

}

#include <bits/stdc++.h>

using namespace std;

int getPoints(int month1, int month2, int month3){
    // Complete this function
    
  
   month1 = month1*10;
    month2 = month2*10;
    month3 = month3*10;
    
    if(month1>100){
        month1=100;
    } 
    if(month2>100){
        month2=100;
    }
    if(month3>100){
        month3=100;
    }
    
    return (month1 +month2+month3 );
}

int main() {
    int month1;
    int month2;
    int month3;
    cin >> month1 >> month2 >> month3;
    int pointsEarned = getPoints(month1, month2, month3);
    cout << pointsEarned << endl;
    return 0;
}

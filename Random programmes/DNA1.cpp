#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
int i;
int temp=0,temp1=0,temp2=0,temp3=0;
ifstream in("rosalind_dna.txt");


char line[1000];
char c;
while(!in.eof())
{
in>>c;

if(c=='A')
temp=temp+1;

else if(c=='C')
temp1=temp1+1;

else if(c=='G')
temp2=temp2+1;

else if(c=='T')
temp3=temp3+1;
}
ofstream out("output.txt");

out<<temp<<"  "<<temp1<<"  "<<temp2 <<"  "<<temp3;

in.close();
out.close();
}




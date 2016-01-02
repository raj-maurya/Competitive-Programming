#include<iostream>
using namespace std;
const int size=100;
template<class x> class queu{
x q[size];
int siz;
int en, de;

public:
queu(int len)
{
if(len>size)
len=size;

else if(len<=0)

len=1;
siz=len;
en=de=0;
}
void ene(x data)
{
if(en==size)
{
cout<<"full";

return;
}
en++;
q[en]=data;
}

x dee()
{
if(de==en)
{
cout<<"empty";
return 0;
}
de++;
return q[de];
}
};

int main()
{

queu<int> inqe(10),inqe2(10);

inqe.ene(1);
cout<<inqe.dee();
}

#include<iostream>
#include<cmath>
using namespace std;

class polar
{
float r;
float o;

public:
polar():r(0),o(0)
{
}

polar(float a,float b)
{
r=a;
o=b;
}

float add_polar(polar d)
{
float a,b;
a=sqrt(r*r+d.r*d.r+(2*r*d.r));
b=(r*sin(o)+d.r*(sin(d.o)))/(r*(cos(o))+d.r*(cos(d.o)));

cout<<"\n"<<a<<" "<<b;
}

void show()
{
cout<<"\n"<<r<<" "<<o;
}
};

int main()
{
polar p(2,30);
polar p2(3,30);
float p3;
p3=p.add_polar(p2);

p.show();
p2.show();
//p3.show();
//cout<<p3;
}

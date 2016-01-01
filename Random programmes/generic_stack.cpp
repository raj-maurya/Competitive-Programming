#include<iostream>
using namespace std;
const int size=10;
template <class st>
class stack
{
st stk[size];
int top;

public:
stack()
{
top=0;
}

void push(st a)
{
if(top==size)
{
cout<<"full";

}
else
 stk[top++]=a;
//top++;
}

st pop()
{
if(top==0)
{
cout<<"empty";
}
else
//top--;
return stk[--top];

}
};

int main()
{
stack <int> s1;
//stack <char> s2;
//cout<<s1.pop();
//s1.push(5);
cout<<s1.pop();

}


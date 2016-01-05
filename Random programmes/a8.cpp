// class using template with default argument
#include<iostream>
using namespace std;

template<class x=int, class y=char>
class myclass                     
   {
	x a;
	y b;
   public:
	myclass(x p,y q)
	{
	a=p;
	b=q;
	}
    void show()                
        { 
	cout<<"\na=  "<<a;
	cout<<"\nb=  "<<b;
	}
   };

   

int main()
   {
 	myclass<> c1(10,'*');
	myclass<float,int> c2(5.5,6);
	c2.show();
	c1.show();
       }

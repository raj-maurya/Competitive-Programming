#include<iostream>
using namespace std;


	 int a[50];
	int top=-1;

	void push(int ab){
		if(top==50){
			cout<<"full stack";
		}
		else{
			top=top+1;
			a[top]=ab;
			//top++;
		}
	}

	int  pop(){
		if (top==-1){
			cout<<"\n"<<"Can not pop more";
		}
		else{
			top=top-1;
			return a[top];

			
		}
	}

	void display(){
		if(top==-1){
			cout<<"\n"<<"stack is empty";
		}
		else
		cout<<a[top];
	}

int main(){
  push(5);
display();
pop();
display();
pop();
}
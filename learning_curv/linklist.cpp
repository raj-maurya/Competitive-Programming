#include<iostream>
using namespace std;

	/* code */
	struct node{
		int data;
		struct node* next;

	};
	void push(){
	struct node* first=NULL;
	first = new (struct node);
	struct node* second=NULL;
	second = new (struct node);
	first->data=5;
	first->next=second;
	second->data=6;
	second->next-NULL;

	
}

void print(struct node* node)
{
	cout<<node->data;
	
}
int main()
{
	struct node* node=NULL;
 push();
 print(node);
 return 0;
}	
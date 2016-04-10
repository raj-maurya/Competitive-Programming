#include<iostream>
using namespace std;

	/* code */
	struct node{
		int data;
		struct node* next;

	};
	void init_node(struct node*& node, int dat){
	struct node* first;
	first=new (struct node);
	first->data=dat;
	first->next=node;
	node= first;
	}

	void insert_last(struct node* node, int dat){
		struct node* append;
		append= new (struct node);
		append->data=dat;
		append->next=NULL;
		struct node* current = node;
		while(current){
			if (current->next==NULL)
			{
				current->next=append;
				return;
			}
			current=current->next;
		}
	}

void print(struct node* node)
{
	struct node* current=node;
	while(current!=NULL)
	{
			cout<<current->data<< " ";
		current=current->next;
	}
	cout<<endl;
}
int main()
{
	struct node* node = NULL;
 init_node(node, 8);
 print(node);
 insert_last(node, 1);
 print(node);
 insert_last(node, 7);
 print(node);
 insert_last(node, 8);
 print(node); 
 return 0;
}	
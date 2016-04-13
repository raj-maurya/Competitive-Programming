#include<iostream>
using namespace std;

	
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

void insert_front(struct node*& node, int dat){
	struct node* first_append;
	first_append= new (struct node);
	first_append->data= dat;
	//first_append->next=NULL;
	//struct node* current =node;
	first_append->next=node;
	node=first_append;
}
void insert_between(struct node* node, int dat, int pos){
	struct node* mid_insert;
	mid_insert= new(struct node);
	mid_insert->data=dat;
	struct node* mid=node;
	struct node* mid_next=node;
	for(int i=1; i<pos-1; i++){
		mid=mid->next;
	}
	mid_next=mid->next;
	mid->next=mid_insert;
	mid_insert->next=mid_next;

}
struct node* search_node(struct node* node, int dat){
	struct node *search = node;
	while(search){
		if(search->data==dat){
			return search;
			//cout<<"Node is"<< search;
		}
		search=search->next;
	}
	cout<<"NO node "<<dat <<" in the list";

}
//delete a node from front
void delete_front(struct node* node){
	struct node* track= node;
	
	node=node->next;
	delete track;
	node=track;

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
 init_node(node, 5);
 print(node);
 insert_last(node, 1);
 print(node);
 insert_last(node, 7);
 print(node);
 insert_last(node, 8);
 print(node); 
 insert_front(node, 9);
 print(node);
  insert_last(node, 3);
 print(node); 
 search_node(node, 9);
 insert_between(node, 2,5);
 print(node);
 delete_front(node);
 print(node);
 return 0;
}	


/*
// same inpplementation Using different format of pointers "*"
 struct Node {
	int data;
	Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,int n){
	head->data = n;
	head->next =NULL;
}

// apending
void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}
void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

	int main() 
{
	//struct Node *newHead;
	struct Node *head = new Node;
	
	initNode(head,10);
	display(head);

	addNode(head,20);
	display(head);

	addNode(head,30);
	display(head);

	addNode(head,35);
	display(head);
}
*/
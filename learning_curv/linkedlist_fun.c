#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node* next;
};

void push(struct node** head_ref, int ndata)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ndata;
	newnode->next=*head_ref;
	*head_ref=newnode;
}
void inserbetween(struct node* prenode, int ndata)
{
	if(prenode==NULL)
		printf("empty node");
	//return 0;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ndata;
	newnode->next=prenode->next;
	prenode->next=newnode;
}
void insertlast(struct node** head_ref, int ndata)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	struct node* last= *head_ref;
	newnode->data=ndata;
	newnode->next=NULL;
	if(*head_ref==NULL)
		*head_ref=newnode;
	//return 0;
	while(last->next!=NULL)
		last=last->next;
	last->next=newnode;
	//return 0;


}
 void printlist(struct node* head)
{
	while(head!=NULL)
	{
		printf("\n%d", head->data);
	head=head->next;
	}

}

int count(struct node* node)
{
	int getcount =0;
	while(node!=NULL)
	{
		getcount++;
		node=node->next;
	}
	return getcount;

}

void delete(struct node** head_ref, int key)
{
	struct node* temp= *head_ref;
	struct node* prev;
	if(temp!=NULL && temp->data==key)
		*head_ref=temp->next;
	free(temp);
	//return;
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	prev->next=temp->next;
	free(temp);
}
int main()
{
	struct node* head=NULL;
	push(&head,1);
	push(&head,5);
	push(&head,3);
	inserbetween(head,8);
	printlist(head);
printf("\n %d",count(head));
	delete(&head,5);

	printlist(head);
	return 0;

}

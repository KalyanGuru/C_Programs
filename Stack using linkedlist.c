#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;
void insert_beg(node **phead,int item)
{
	node *new_node=(node *)malloc(sizeof(node));
	new_node->data=item;
	new_node->next=*phead;
	*phead=new_node;
}
void del_beg(node **phead)
{
	if (*phead==NULL)
	{
		printf("Your Stack is EMPTY");
	}
	else
	{
	node *ptr=*phead;
	*phead=ptr->next;
	printf("%d is deleted\n", ptr->data);
	free(ptr);
	}
}
int main()
{
 node*head=NULL;
 int n=1;
 while(n)
 {
 int ch;
 printf("\nEnter your choice\n Press 1 for push\n press 2 for pop\n press 3 for EXIT\n ");
 scanf("%d",&ch);
 int item;
 switch(ch)
 {
    case 1: printf("Enter the item you want to insert:" );
		    scanf("%d",&item);
	        insert_beg(&head,item);
	        break;
    case 2: del_beg(&head);
            break;
    case 3: n=0;
  }
 }
}

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;
void insert_node(node**prear,int item)
{
	node *new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	new_node->next=NULL;
	node*ptr=*prear;
	if(*prear==NULL)
	{
		new_node->next=new_node;
	}
	else
	{
		new_node->next=ptr->next;
		ptr->next=new_node;
	}
	*prear=new_node;
}
void del_node(node**prear)
{
	if(*prear==NULL)
	{
		printf("EMPTY\n");
		return;
	}
	else if(*prear==(*prear)->next)
	{
		node*ptr=*prear;
		*prear=NULL;
		 printf("Deleted Item is %d\n",ptr->data);
        free(ptr);
        return;
	}
	else
	{
		node*ptr=(*prear)->next;
		(*prear)->next=ptr->next;
        printf("Deleted Item is %d\n",ptr->data);
        free(ptr);
        return;
	}
}
int main()
{
	node*rear=NULL;
	int ch,item,n=1;
	printf("Choose any operation: \n");
	while(n)
	{
	printf("1.Enqueue \n2.Dequeue \n3.To Exit\n_");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the item: ");
			        scanf("%d",&item);
			        insert_node(&rear,item);
			        break;
			case 2: del_node(&rear);
			        break;
			case 3: n=0;
					break;
	     	default: printf("Enter the correct choice\n");
			         break;         
		}
    }
}

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;

void append(node **phead,int item)
{
	
	node *new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	new_node->next=NULL;
	if(*phead==NULL)
	{
	    *phead=new_node;
	}
	else
	{
		node*ptr=*phead;
		while(ptr->next!=NULL)
		{
		  ptr=ptr->next;
	    }
		ptr->next=new_node;
	}
}

void insert_beg(node **phead,int item)
{
	node *new_node=(node *)malloc(sizeof(node));
	new_node->data=item;
	new_node->next=*phead;
	*phead=new_node;
}/*
node *searchNode(node** phead, int key) 
{
	node*ptr=*phead;
    int c=1;
    while(c!=key)
    {	
    	ptr=ptr->next;
    	c++;
	}
	return (ptr);
}*/
void insert_mid(node **phead,int pos,int item)
{
	node *new_node=(node *)malloc(sizeof(node));
	new_node->data=item;
	new_node->next=NULL;
	node *ptr=*phead;
	node *prev=*phead;
	int c=1;
	while(c!=pos)
     {
	prev=ptr;
	ptr=ptr->next;
		c++;
    }
    new_node->next=ptr;
	prev->next=new_node;
	
}
void display(node *phead)
{
	printf("Elements are:\n");
	node*ptr=phead;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void del_beg(node **phead)
{
	node *ptr=*phead;
	*phead=ptr->next;
	printf("%d is deleted\n", ptr->data);
	free(ptr);
}

void del_mid(node **phead,int pos)
{
	int c=1;
	if(pos==1)
	{
	del_beg(phead);	
	}
	else
	{
		node *ptr=*phead;
    	node *prev=*phead;
	while(c!=pos)
     {
	prev=ptr;
	ptr=ptr->next;
		c++;
    }
	prev->next=ptr->next;
	printf("%d is deleted\n", ptr->data);
	free(ptr);
}
}
int main()
{
	node* head=NULL;
	int ch,pos,item,n=1;
	printf("Choose any operation: \n");
	while(n)
	{
	printf("1.Insert in End \n2.Insert in beginning \n3.Insert in middle \n4.Delete in beginning \n5.Delete in position \n6.Display \n7.To Exit\n");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the item you want to append:" );
			    	scanf("%d",&item);
			    	append(&head,item);
			    	break;
			case 2: printf("Enter the item you want to insert in begining:" );
			        scanf("%d",&item);
			        insert_beg(&head,item);
			        break;
			case 3: printf("Enter the item you want to insert: " );
				    scanf("%d",&item);
				    printf("Enter the position: ");
				    scanf("%d",&pos);
				    insert_mid(&head,pos,item);
				    break;
			case 4: del_beg(&head);
				    break;
			case 5:	printf("Enter the position: ");
				    scanf("%d",&pos);
			        del_mid(&head,pos);
			        break;
			case 6: display(head);
			        break;
			case 7: n=0;
			        break;
			default:printf("Enter the right choice\n");
		}
	}
}


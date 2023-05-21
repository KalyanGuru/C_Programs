#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	 struct node *left;
	 struct node *right;
}node;
 insert_end(node**phead,node**ptail,int item)
 {
 	node*new_node=(node*)malloc(sizeof(node));
 	new_node->data=item;
 	new_node->left=NULL;
 	new_node->right=NULL;
 	if(*phead==NULL)
 	{
 		*phead=*ptail=new_node;
	 }
	 else if(*phead==*ptail)
	 {
	 	(*ptail)->right=new_node;
	 	new_node->left=*ptail;
	 	(*ptail)=new_node;
	 }
	 else
	 {
	 	(*ptail)->right=new_node;
	 	new_node->left=*ptail;
	 	(*ptail)=new_node;
	 }
 }
 insert_beg(node**phead,node**ptail,int item)
 {
 	node*new_node=(node*)malloc(sizeof(node));
 	new_node->data=item;
 	new_node->left=NULL;
 	new_node->right=NULL;
 	if(*phead==NULL)
 	{
 		*phead=*ptail=new_node;
	 }
	 else if(*phead==*ptail)
	 {
	 	(*phead)->left=new_node;
	 	new_node->right=*phead;
	 	*phead=new_node;
	 }
	 else
	 {
	 	(*phead)->left=new_node;
	 	new_node->right=*phead;
	 	*phead=new_node;
	 }
 }
 node*search(node*ptr,int key)
 {
 	while(ptr->data!=key&&ptr!=NULL)
 	{
 		ptr=ptr->right;
	 }
	 if(ptr->data==key)
	   return ptr;
	else
	   printf("!!Entered element is not found!!\n");
	   return NULL;
 }
 insert_midafter(node**phead,node**ptail,int item,int key)
 {
 	node*new_node=(node*)malloc(sizeof(node));
 	new_node->data=item;
 	new_node->left=NULL;
 	new_node->right=NULL;
 	node*ptr=*phead;
 	if(*phead==NULL)
 	   {
 		*phead=*ptail=new_node;
	   }
	else
	 {
	   	node*ptr1=search(ptr,key);
	   	new_node->left=ptr1;
	   	new_node->right=ptr1->right;
	   	ptr1->right->left=new_node;
	   	ptr1->right=new_node;
	   	
	 }
 }
 insert_midbefore(node**phead,node**ptail,int item,int key)
 {
 	node*new_node=(node*)malloc(sizeof(node));
 	new_node->data=item;
 	new_node->left=NULL;
 	new_node->right=NULL;
 	node*ptr=*phead;
 	if(*phead==NULL)
 	{
 		*phead=*ptail=new_node;
	 }
	 else
	 {
	 	node*ptr1=search(ptr,key);
	 	new_node->right=ptr1;
	 	new_node->left=ptr1->left;
	 	ptr1->left->right=new_node;
	 	ptr1->left=new_node;
	 }
 }
 void position_append(node**phead,node**ptail,int item,int pos)
 {
 	node*new_node=(node*)malloc(sizeof(node));
 	new_node->data=item;
 	new_node->left=NULL;
 	new_node->right=NULL;
 	node*ptr1=*phead;
 	int count=1;
 	if(*phead==NULL)
 	{
 		*phead=*ptail=new_node;
	 }
	 else
	 {
	 	while(count!=pos)
	 	{
	 		ptr1=ptr1->right;
	 		count++;
		 }
		new_node->right=ptr1;
	 	new_node->left=ptr1->left;
	 	ptr1->left->right=new_node;
	 	ptr1->left=new_node;
	 }
 }
 void del_beg(node**phead,node**ptail)
 {
 	if(*phead==NULL)
 	{
 		printf("!!!!EMPTY!!!!\n");
 		return;
	 }
	 else
	 {
	 	node*ptr=*phead;
	 	if(*phead==*ptail)
	 	{
	 		printf("Deleted item is %d",ptr->data);
	 		free(ptr);
	 		*ptail=*phead=NULL;
	 		return;
		 }
		 else
		 {
		 	*phead=ptr->right;
		 	(*phead)->left=NULL;
		 	printf("Deleted item is %d",ptr->data);
		 	free(ptr);
		 	return;
		 }
	 }
 }
  void del_end(node**phead,node**ptail)
  {
  	if(*phead==NULL)
 	{
 		printf("!!!!EMPTY!!!!\n");
 		return;
	 }
	 else
	 {
	 	node*ptr=*ptail;
	 	if(*ptail==*phead)
	 	{
	 		printf("Deleted item is %d",ptr->data);
	 		free(ptr);
	 		*ptail=*phead=NULL;
	 		return;
		 }
		 else
		 {
		 	(*ptail)=ptr->left;
		 	(*ptail)->right=NULL;
		 	printf("Deleted item is %d",ptr->data);
		 	free(ptr);
		 	return;
		 }
	 }
  }
  void del_key(node**phead,node**ptail,int key)
  {
  	node*ptr=*phead;
  	node *ptr1=search(ptr,key);
  	if(*phead==NULL)
 	{
 		printf("!!!!EMPTY!!!!\n");
 		return;
	 }
	 else if(*ptail==*phead)
	{
		*ptail=*phead=NULL;
	 }
	else if(ptr1==*phead)
	{
		*phead=ptr1->right;
		(*phead)->left=NULL;
	}
	else if (ptr1==*ptail)
	{
		*ptail=ptr1->left;
		(*ptail)->right=NULL;
	}
	else
	{
		ptr1->left->right=ptr1->right;
		ptr1->right->left=ptr1->left;
	}
	printf("Deleted item is %d\n",ptr1->data);
	free(ptr1);
	return;
  }
  void display(node*phead,node*ptail)
  {
  	node*ptr=phead;
  	node*ptr1=ptail;
  	printf("FORWARD_\n");
  	while(ptr!=NULL)
  	 {
  	 	printf("%d",ptr->data);
  	 	ptr=ptr->right;
	   }
	printf("\nBACKWARD_\n");
  	while(ptr1!=NULL)
  	 {
  	 	printf("%d ",ptr1->data);
  	 	ptr1=ptr1->left;
	   }
  }
  int main()
  {
  	node* head=NULL;
  	node* tail=NULL;
	int ch,pos,item,key,n=1;
	printf("Choose any operation: \n");
	while(n)
	{
	printf("\n1.Insert in Beginning \n2.Insert in END \n3.Insert in Position \n4.Insert after given data\n5.Insert before given data\n6.Delete in beginning \n7.Delete Data \n8.Delete in End\n9.Display \n0.To Exit\n");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the item you want to insert in begining:" );
			       scanf("%d",&item);
			       insert_beg(&head,&tail,item);
			       break;
			case 2:printf("Enter the item you want to insert in end:" );
			       scanf("%d",&item);
			       insert_end(&head,&tail,item);
			       break;
			case 3:printf("Enter the item you want to insert:" );
			       scanf("%d",&item);
			       printf("Enter the position: ");
				   scanf("%d",&pos);
			       position_append(&head,&tail,item,pos);
			       break;
			case 4:printf("Enter the item you want to insert:" );
			       scanf("%d",&item);
			       printf("Enter the DATA: ");
				   scanf("%d",&key);
			       insert_midafter(&head,&tail,item,key);
			       break;
			case 5:printf("Enter the item you want to insert:" );
			       scanf("%d",&item);
			       printf("Enter the DATA: ");
				   scanf("%d",&key);
			       insert_midbefore(&head,&tail,item,key);
			       break;
			case 6:del_beg(&head,&tail);
			       break;
			case 7:printf("Enter the Data you want to delete: ");
				    scanf("%d",&key);
			        del_key(&head,&tail,key);
			        break;
			case 8:del_end(&head,&tail);
			       break;
			case 9:display(head,tail);
			       break;
			case 0:	n=0;
			        break;
			default: printf("Enter the right choice");
        }
    }
}

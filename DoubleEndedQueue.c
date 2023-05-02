#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
  int *a;
  int size;
  int front;
  int rear;
}qu;

void init (qu *q)
{
  int len;
  printf("Enter the lenth: ");
  scanf("%d",&len);
  q->front=-1;
  q->rear=-1;
  q->size=len;
  q->a=(int*) malloc(q->size*sizeof(int));
}

int isfull(qu *q)
{
  if((q->rear==q->size-1 && q->front==0) || (q->front==q->rear+1))
       return 1;
  else 
       return 0;
} 

int isempty(qu *q)
{
 if(q->front==-1 && q->rear==-1)
     return 1;
 else
     return 0;
}

int front_dequeue(qu *q)
{
	int item=q->a[q->front];
	if(isempty(q))
	  {
	  	   printf("\nQueue is EMPTY");
	       return;
	  }
    else if(q->front==q->rear)
       {
           q->front=-1;
           q->rear=-1;
       }
    else if(q->front==q->size-1)
      {
          q->front=0;
      }
    else
      {
	    q->front++;
      }
    printf("Deleted item is %d",item);
    return;
}
void rear_dequeue(qu *q)
{
		int item=q->a[q->front];
	if(isempty(q))
	  {
           printf("\nQueue is EMPTY");
	       return;
	  }
    else if(q->front==q->rear)
       {
           q->front=-1;
           q->rear=-1;
       }
    else if(q->rear==0)
      {
          q->rear=q->size-1;
      }
    else
      {
	    q->rear--;
      }
    printf("Deleted item is %d",item);
    return;
}
void rear_enqueue(qu *q , int item)
{
	if(isfull(q))
	{
	 	printf("Queue is fULL");
		 return;
	 }
  	else if(q->front==-1 && q->rear==-1)
  	{
	 	 q->front=q->rear=0;
		 q->a[q->rear]=item;
	}
 	else if(q->rear==q->size-1)
 	{
		 q->rear=0;
		 q->a[q->rear]=item;
	}
 	else
	{ 
		q->a[++q->rear]=item;
	}
}
void front_enqueue(qu *q , int item)
{
	if(isfull(q))
	{
	 	printf("Queue is fULL");
		 return;
	 }
  	else if(q->front==-1 && q->rear==-1)
  	{
	 	 q->front=q->rear=0;
	 	// printf("%d",q->front);
		 q->a[q->front]=item;
	}
 	else if(q->front==0)
 	{
		 q->front=q->size-1;
		 q->a[q->front]=item;
	}
 	else
	{ 
		q->a[--q->front]=item;
	}
}
int main()
{
 qu q;
 init (&q);
 int n;
 printf("\nEnter 1 to continue: ");
 scanf("%d",&n);
 while(n)
 {
 int ch;
 printf("\nEnter your choice Press");
 printf("\n1 for Insert in End ");
 printf("\n2 for Insert in Front ");
 printf("\n3 for Delete from End ");
 printf("\n4 for Delete from Front ");
 printf("\n5 to EXIT\n");
 scanf("%d",&ch);
 int x,y;
 int item;
 switch(ch)
 {
    case 1: printf("\nEnter the element to be insert: ");
            scanf("%d",&item);
            rear_enqueue(&q,item);
            break;
    case 2: printf("\nEnter the element to be insert: ");
            scanf("%d",&item);
            front_enqueue(&q,item);
            break;
    case 3: rear_dequeue(&q);
            break;
	case 4: front_dequeue(&q);
            break;      
    case 5: n=0;
    default: printf("Enter The Correct Choice");
             break;
  }
 }
}

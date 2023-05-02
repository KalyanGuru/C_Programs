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

void dequeue(qu *q)
{
	int item=q->a[q->front];
	if(isempty(q))
	  {
	  	printf("Queue is EMPTY");
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
void enqueue(qu *q , int item)
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
 printf("\nEnter your choice (Press 1 for Insert or press 2 for Delete and press 3 for EXIT): ");
 scanf("%d",&ch);
 int x,y;
 int item;
 switch(ch)
 {
    case 1: printf("\nEnter the element to be insert: ");
            scanf("%d",&item);
            enqueue(&q,item);
            break;
    case 2: dequeue(&q);
            break;
    case 3: n=0;
  }
 }
}

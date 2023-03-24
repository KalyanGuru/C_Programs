#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int *a;
  int size;
  int top;
}st;

void init (st *s1)
{
  int len;
  printf("Enter the lenth: ");
  scanf("%d",&len);
  s1->top=-1;
  s1->size=len;
  s1->a=(int*) malloc(s1->size*sizeof(int));
}

int isfull(st *s)
{
  if(s->top==s->size-1)
    return 1;
  else 
    return 0;
} 

int isempty(st *s)
{
 if(s->top==-1)
   return 1;
 else
    return 0;
}

int push(st *s2, int item)
{
 if( isfull(s2) )
        return 1;
 s2->a[++s2->top]= item;
    
}

int pop(st *s2)
{
 int value;
 if(isempty(s2))
 {
  return 1;
 }
 else
 {
  value=s2->a[s2->top--];
  return value;
 }
}

int main()
{
 st s;
 init (&s);
 int n;
 printf("\nEnter 1 to continue 0 to stop:");
 scanf("%d",&n);
 while(n)
 {
 int ch;
 printf("\nEnter your choice (Press 1 for push or press 2 for pop): ");
 scanf("%d",&ch);
 int x,y;
 int item;
 switch(ch)
 {
    case 1: printf("\nEnter the element to be pushed: ");
            scanf("%d",&item);
            x= push(&s,item); 
            if(x==1) 
             printf("\nSTACK OVERFLOW");
            break;
    case 2: y=pop(&s);
            if(y==1)
             printf("\nSTACK UNDERFLOW");
            else
             printf("poped item is %d",y);
            break;
  }
 }
}

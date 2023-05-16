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

void push(st *s2, int item)
{
 if( isfull(s2) )
 {
         printf("\nSTACK OVERFLOW");
         return;
 }
 else
 {
    s2->a[++s2->top]= item;
    return;
 }
}

void pop(st *s2)
{
 int value;
 if(isempty(s2))
 {
  printf("\nSTACK UNDERFLOW");
   return;
 }
 else
 {
  value=s2->a[s2->top--];
   printf("poped item is %d",value);
   return;
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
 printf("\nEnter your choice (Press 1 for push or press 2 for pop and press 3 for EXIT): ");
 scanf("%d",&ch);
 int item;
 switch(ch)
 {
    case 1: printf("\nEnter the element to be pushed: ");
            scanf("%d",&item);
            push(&s,item); 
            break;
    case 2: pop(&s);
            break;
    case 3: n=0;
  }
 }
}

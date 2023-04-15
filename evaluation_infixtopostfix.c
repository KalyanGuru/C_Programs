#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct stack
{
  char *a;
  int size;
  int top;
  int *ar;
}st;

void init (st *s1, int len)
{
  s1->top=-1;
  s1->size=len;
  s1->a=(char*) malloc(s1->size*sizeof(char));
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

char push(st *s2, char item)
{
 if( isfull(s2) )
        return 0;
 else
        s2->a[++s2->top]= item;
}

char pop(st *s2)
{
 char value;
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
int isoperator(char c)
{
	if(c=='+'||c=='-'||c=='/'||c=='*')
    	return 1;
	else
    	return 0;
}
int pressedence(char ch)
{
	switch (ch)
	 {
	 	 case '/':  return 4;
	 	 case '*':    return 3;
	 	       
	 	 case '+': return 2; 
		 case '-':   return 1;
		       
		 default : return 0;
	 }
}
char peek(st*s3)
{
	return(s3->a[s3->top]);
}
char * infix_postfix(char* infix)
{
	int i,j;
	int len=strlen(infix);
	st s;
	
	init(&s,len);
	char*postfix=(char*)malloc(sizeof(char)*len+1);
	
	for(i=0,j=0;i<len;i++)
	{
		if(isalnum(infix[i]))
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			push(&s,infix[i]);
		}
		else if(isoperator(infix[i]))
		{
			while(pressedence(infix[i])<=pressedence(peek(&s)) && !isempty(&s))
			{
				postfix[j++]=pop(&s);
			}
			push(&s,infix[i]);
	    }
		else if(infix[i]==')')
		{
			while(peek(&s)!='(' && !isempty(&s))
			{
				postfix[j++]=pop(&s);
			}
			pop(&s);
		}
	}
		while(!isempty(&s))
		{
			postfix[j++]=pop(&s);
		}
    postfix[j] = '\0';
	return postfix;
}
void init2(st*b, int s)
{
	b->top=-1;
    b->size=s;
    b->ar=(int*) malloc(s*sizeof(int));
}
int peek2(st*b3)
{
	return(b3->ar[b3->top]);
}
int pop2(st *b2)
{
 int value;
 if(!isempty(b2))
 {
  value=b2->ar[b2->top--];
  return value;
 }
}
void push2(st *b2, int item)
{
 if( !isfull(b2) )
        b2->ar[++b2->top]= item;
        printf("Pushed %d\n",b2->ar[b2->top]);
}
int eval_postfix(char *postfix)
{
	st b;
	int len=strlen(postfix);
//	printf("%d",len);
	init2(&b,len);
	int i;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
		{
			push2(&b,postfix[i]-'0');
		//	printf("isdigit for entry");
		}
		else if(isoperator(postfix[i]))
		{
			int val1=pop2(&b);
			int val2=pop2(&b);
		//	printf("%d    %d  ",val2,val1);
			switch (postfix[i])
			{
				case '/':  push2(&b,val2/val1);
				            break; 
				case '*':  push2(&b,val2*val1);
				       	    break;
				case '+':  push2(&b,val2+val1);
							break;
				case '-':  push2(&b,val2-val1);
							break;
				default: printf("INVALIDE");
							break;
			}
		}
	}
	 int ans=peek2(&b);
	 printf("%d\n",ans);
	 return ans;
}
int main()
{
  char infix[]="(5*2+2/2)";
  printf("%s\n",infix);
  char *postfix = infix_postfix(infix);
  printf("%s\n",postfix);
  printf("\nThe result is %d",eval_postfix(postfix));
}

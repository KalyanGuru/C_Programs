#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct stack
{
  char *a;
  int size;
  int top;
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
int main()
{
  char infix[]="(A*B+C/D)";
  printf("%s\n",infix);
  char *v = infix_postfix(infix);
  printf("%s\n",v);
}

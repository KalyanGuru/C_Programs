#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack
{
    char *a;
    int top;
    int size;
} st;

void init(st *s1, int len)
{
    s1->top = -1;
    s1->size = len;
    s1->a = (char *)malloc(sizeof(char) * (len - 1));
}

int isFull(st *S)
{
    if (S->top == S->size - 1)
        return 1;
    return 0;
}
void push(st *s2, char item)
{
    if (!isFull(s2))
        s2->a[++s2->top] = item;
}

int isEmpty(st *S)
{
    if (S->top == -1)
        return 1;
    return 0;
}
char pop(st *s2)
{
    if (!isEmpty(s2))
    {
        char value;
        value = s2->a[s2->top--];
        return value;
    }
}

char peek(st *s3)
{
    return (s3->a[s3->top]);
}

int isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 3;
    case '*':
    case '/':
        return 2;
    case '^':
        return 1;
    default:
        return 0;
    }
}

char *infix_to_postfix(st s, char *infix, int len)
{
    char *postfix = (char *)malloc(sizeof(char) * (len + 1));

    int i, j;
    for (i = 0, j = 0; i < len; i++)
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];

        else if (infix[i] == '(')
            push(&s, infix[i]);

        else if (isoperator(infix[i]))
        {
            while ((precedence(infix[i]) <= precedence(peek(&s))) && !isEmpty(&s))
                postfix[j++] = pop(&s);
            push(&s, infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (peek(&s) != '(' && !isEmpty(&s))
                postfix[j++] = pop(&s);
            pop(&s);
        }
    }
    while (!isEmpty(&s))
                postfix[j++] = pop(&s);
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    st s;
    char infix[] = "(A+B)*C+D*F";
    int len = strlen(infix);

    init(&s, len);

    printf("%s\n", infix);

    
    char *result = infix_to_postfix(s, infix, len);
    printf("%s\n", result);

    return 0;
}
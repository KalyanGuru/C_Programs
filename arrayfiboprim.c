//Generate an array of length n whose every odd position is filled with the numbers
//from fibonacci series and every even position is filled with prime numbers in order.

#include<stdio.h>
int fibo();
int prime( int n);
void main()
{
    int ar[100],n,i,s,num;
    printf("Enter how many elements you want: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
             ar[i]=0;
        }
        else if(i==2)
        {
            ar[i]=1;
        }
        else if(i%2==0)
        {
            ar[i]=fibo(s);
        }
        else
        {
            ar[i]=prime(n);
        }
    }
    printf("The array is:[");
    for(i=0;i<n;i++)
    {
        printf(" %d ",ar[i]);
    }
    printf("]");
}
int fibo()
{
    static int a=0,b=1;
    int s;
    s=a+b;
    a=b;
    b=s;
    return s;
}
int prime(int n)
{
    static int num=0;
    while(num>=0)
    {
        int count = 0;
        num++;
        for(int i=2;i<=num/2;i++)
        {
             if(num%i==0)
             {
                 count++;
                 break;
             }
        }
        if(count==0)
            return num;
           
    } 
   
}
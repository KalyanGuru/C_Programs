#include<stdio.h>
int bubblesh(int a[],int n);
void main ()
{
    int i,n,a[100];
    printf ("Enter the range :");
    scanf ("%d",&n);
    for (i=0;i<n;i++)
    {
        printf ("Enter the element of %d position: ",i);
        scanf ("%d",&a[i]);
    }
    printf ("The sorted elements are:\n");
    bubblesh(a,n);
}
int bubblesh(int a[],int n)
{
    int i,temp,j;
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
     for (i=0;i<n;i++)
    {
        printf (" %d ",a[i]);
    }
}

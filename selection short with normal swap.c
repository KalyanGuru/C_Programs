#include<stdio.h>
void selection (int a[], int n);
int main()
{
    int i,n,a[100];
    printf ("Enter the range: ");
    scanf ("%d",&n);
    for (i=0;i<n;i++)
    {
        printf ("Enter the %d no element: ",i+1);
        scanf ("%d",&a[i]);
    }
    printf ("The shorted list is given below\n");
    selection (a,n);
}
void selection (int a[], int n)
{
    int i,j,min;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
        {
            if (a[min]>a[j])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            int k;
            k=a[min];
            a[min]=a[i];
            a[i]=k;
        }
    }
    for (i=0;i<n;i++)
    {
        printf (" %d ",a[i]);
    }
}
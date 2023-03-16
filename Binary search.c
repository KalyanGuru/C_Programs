#include<stdio.h>
void binaryse(int a[],int n,int key);
int main()
{
    int i,a[100],n,key;
    printf ("Enter the range: ");
    scanf ("%d",&n);
    for(i=0;i<n;i++)
    {
        printf ("Enter the in position %d ",i);
        scanf ("%d",&a[i]);
    }
    printf ("Enter the element you want to search");
    scanf ("%d",&key);
    binaryse(a,n,key);
}
void binaryse (int a[],int n,int key)
{
    int i,low,high,mid,flag=0;
    low=i;
    high=n;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (key==a[mid])
        {
            flag=1;
            break;
        }
        else if (key<a[mid])
        {
            high=mid-1;
        }
        else if (key>a[mid])
        {
            low=mid+1;
        }
    }
    if (flag==1)
    {
        printf ("The Element %d is found in %d position",key,mid);
    }
    else 
    {
        printf ("Searched element is not found ");
    }
}
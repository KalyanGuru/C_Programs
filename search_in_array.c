#include<stdio.h>
void search(int ar[],int key,int n);
int main()
{
 int ar[100],n,i,key;
 printf( "enter the number of element: ");
 scanf ("%d",&n);
 for(i=0;i<n;i++)
 {
    printf("Enter the %d no element of the array",i+1);
    scanf("%d",&ar[i]);
 }
 printf("Enter the element you want to find: ");
 scanf("%d",&key);
 search(ar,key,n);
}
void search(int ar[],int key,int n)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(ar[i]==key)
        {
            flag++;
            printf("\nThe element is found in %d no pisition",i+1);
        }
    }
    if (flag==0)
        {
            printf("\nSorry item not found!!!!");
        }
}
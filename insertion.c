#include<stdio.h>
void insertion(int a[],int n);
void main()
 {
  int a[100],n,i;
  printf("Enter the element:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }
 printf("The sorted array is:\n");
 insertion(a,n);
 }
void insertion(int a[],int n)
{
 int key,j,i;
 for(i=1;i<n;i++)
 {
  key=a[i];
  for (j=i-1;j>=0 && a[j]>key;j--)
   {
     a[j+1]=a[j];
   }
   a[j+1]=key;
 }
 for(i=0;i<n;i++)
   {
    printf(" %d ",a[i]);
   }
}

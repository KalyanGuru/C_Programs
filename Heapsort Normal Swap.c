#include<stdio.h>
#include<stdlib.h>
void hepify(int ar[],int n)
{
	int i, left,right,larg,temp;
	for(i=n/2-1;i>=0;i--)
	{
		do
		{
			left=2*i+1;
			right=2*i+2;
			larg=left;
			if(left>=n)
			  {
			  break;
              }
			if(left<n-1 && ar[right]>ar[left])
			  {
			  larg=right;
              }
			if(ar[larg]>ar[i])
			   {
			  	temp=ar[larg];
			  	ar[larg]=ar[i];
			  	ar[i]=temp;
			    i=larg;
		       }
			else
			  break;
		}while(left<n);
	}
}
void heapsort(int *a,int n)
{
	int j,i,temp;
	hepify(a,n);
	 for(j=n-1;j>=0;j--)
	 {
	 	temp=a[j];
		a[j]=a[0];
		a[0]=temp;
	 	hepify(a,j);
	 }
	 for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
    }
}
void main()
{
	int n,i,a[100];
	printf("Enter the size: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Sorted array is:\n");
	heapsort(a,n);
}

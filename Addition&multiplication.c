#include<stdio.h>
int addition(int a[][100],int b[][100],int n)
{
	int c[100][100],i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("Result of the addition is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d    ",c[i][j]);
		}
		printf("\n");
	}
}
int multiplication(int a[][100],int b[][100],int n)
{
	int c[100][100],i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	printf("Result of the multiplication is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d    ",c[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n,i,j,ch,a[100][100],b[100][100];
	printf("Enter the number of rows and column: ");
	scanf("%d",&n);
	printf("Enter the data for first matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the data for %d,%d position",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the data for secound matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the data for %d,%d position",1+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	printf("Enter your choice\n");
	printf("Press 1 for addition\nPress 2 for Multiplication\nPress 3 for both");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1: addition(a,b,n);
		        break;
		case 2: multiplication(a,b,n);
		        break;
		case 3: addition(a,b,n);
		        multiplication(a,b,n);
				break;
		default: printf("Enter the right choice");		        
	}
}


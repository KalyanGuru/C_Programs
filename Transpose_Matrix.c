#include<stdio.h>
int main()
{
    int ar[100][100],r,c,i,j;
    printf("Enter the number of row and colume you want: ");
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
        printf ("enter the element of %d%d position: ",i,j);
        scanf("%d",&ar[i][j]);
        }
    }
    printf("The matrix which is entered by you is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
        printf ("%d  ",ar[i][j]);
        }
        printf("\n");
    }
    printf("Transpose Matrix is:\n");
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d  ",ar[j][i]);
        }
        printf("\n");
    }
}
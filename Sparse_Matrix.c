#include<stdio.h>
int main()
{
    int ar[100][100],r,c,i,j,flag=0;
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
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(ar[i][j]==0)
            {
                flag++;
            }
        }
    }
    if(flag>(r*c)/2)
        printf("Entered Matrix is a SPARSE MATRIX");
    else
        printf("Entered Matrix is not a SPARSE MATRIX");
}
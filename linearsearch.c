#include<stdio.h>
void linsearch (int ar[], int n);
int main ()
{
  int ar[100], n, i, a;
  printf ("Enter the range:");
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {

      scanf ("%d", &ar[i]);
    }
  linsearch (ar, n);
}

void linsearch (int ar[], int n)
{
  int num, i, flag = 0;
  printf ("Enter the element to find ");
  scanf ("%d", &num);
  for (i = 0; i < n; i++)
    {
      if (ar[i] == num)
	{
	  printf ("The element is found in %d position", i + 1);
	  flag = 1;
	  break;
	}



    }
  if (flag == 0)

    printf ("The element is not found");
}

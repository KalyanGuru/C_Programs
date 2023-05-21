#include<stdio.h>
TH(int n, char s, char a, char d)
{
	if(n==0)
	 return;
	TH(n-1,s,d,a);
	printf("disk %d moved from %c to %c\n",n,s,d);
	TH(n-1,a,s,d);
}
int main()
{
	int n;
	printf("Enter how many disk you want ");
	scanf("%d",&n);
	TH(n,'s','a','d');
	return 0;
}

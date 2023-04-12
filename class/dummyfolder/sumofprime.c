#include<stdio.h>
#include "myheader.h"

int sum(int n);
int main()
{
	
	int n,i;
	printf("\nEnter a number:");
	scanf("%d",&n);

	int flag=0;
	for(i=2;i<=n/2;i++)
	{
		if(sum(i)==1 && sum(n-i)==1)
		{
			printf("\n %d %d and %d",n,i,n-i);
			flag=1;
		}

	}
	if(flag==0)
	{
		printf("\n no possibility"); 
	}

	return 0;
}

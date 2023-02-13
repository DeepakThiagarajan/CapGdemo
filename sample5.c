#include <stdio.h>

int main()
{
	int a=200;
	int b;int amt;
	  
	printf("Welcome to **EB");
	printf("\n Enter your units:");

	scanf("%d",&b);

	if(b>a && b<=400)
	{
		amt = b*2.25;
	}
	else if(b>400 && b<=600)
	{
		amt = b*9.00;		
	}
	else if(b>600 && b<=800)
	{
		amt = b*9.00;
	}
	else if(b>800 && b<=1000)
	{
		amt = b*10.0;
	}
	else if(b>1000)
	{
		amt =b*11;
	}
	else
	{
		printf("\n You have consumed with 200 units\n");
	}
	printf("\n Your consumed units:%d\tYour calculated amount:%d\n",b,amt);
	printf("\t\tHave a Happy Day\n");

	return 0;
}


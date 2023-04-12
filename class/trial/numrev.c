#include<stdio.h>

int main()
{
	int x,temp,num=0;

	printf("\n Enter any number to reverse:");
	scanf("%d",&x);

	while(x>0)
	{
		temp=x%10;
		num=num*10+temp;
		x=x/10;
	}

	printf("\n Reversed number is:%d",num);

	    	
}

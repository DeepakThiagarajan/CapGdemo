#include <stdio.h>

int main()
{

	int num=11,i,count;

	for(i=2;i<num/2;i++)
	{
	 	if(num%i==0)
		{
			printf("It is not a prime number");
			count=1;
			break;
		} 
	}
	if(count==0)
	{
	printf("It is a primenumber");
	}
}

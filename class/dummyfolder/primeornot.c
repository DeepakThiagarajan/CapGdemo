#include<stdio.h>


int main()
{
	int isPrime(int);

	int gnum; 
	int flag=0;
	
	printf("\nEnter an number:");
	scanf("%d",&gnum);

	flag = isPrime(gnum);

	if(flag == 0)
		printf("\n Givennum: %d is a Prime number\n",gnum);
	else
		printf("\n Givennum: %d is not Prime number\n",gnum);
	return 0;
}


int isPrime(int num)
{	
	int flag=0;
	int it;
	if(num<1)
		flag == 1;
 	
	if(flag != 1){
		for(it = 2;it<num;it++)
		{
		if(num % it == 0)
		{
			flag = 1;
			break;
	}
	
	}
}
return flag;

}

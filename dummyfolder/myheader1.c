#include <stdio.h>

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
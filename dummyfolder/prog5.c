# include<stdio.h>
#include "myheader.h"
#define pSize 100

int isPrime(int);

int main()
{
	int gNum;
	int pArr[pSize];
	int count=0,  flag=0; 
	int i,j;

	printf("\nEnter number:");
	scanf("%d",&gNum);
	
	for(i=2,count=0;i<gNum;i++)
	{
		flag=isPrime(i);
		if(flag==0)
		{
			pArr[count++]=i;
		}

	}

	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			if((pArr[i]+pArr[j])==gNum)
			{
				printf("\n%d + %d = %d",pArr[i],pArr[j],gNum);
			}
		}
	}

	printf("\n\n");
	return 0;





	return 0;

}
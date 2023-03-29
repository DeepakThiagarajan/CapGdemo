#include<stdio.h>
#include<stdlib.h>

int summation(char,int *,int);
int n;
char gender;
int i,sum=0;
int *marks;

int main()
{

	printf("\nEnter the number of students:");
	scanf("%d",&n);
	printf("Enter M or F:\n");
	scanf(" %c",&gender);

	marks=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		printf("Enter the marks :\n");
		scanf("%d",marks+i);
	}
		
	sum=summation(gender,marks,n);
	if(sum != 0)
	{
		printf("GENDER TOTAL\n");
		printf("%c\t%d",gender,sum);
	}
	printf("\n\n");

return 0;
}

int  summation(char gender,int *marks,int n)
{	


	if(gender == 'M')
	{
		for(i=0;i<n;i=i+2)
		{
			sum=sum+marks[i];
		}
	}
	else if(gender == 'F')
	{
		for(i=1;i<n;i=i+2)
		{	
			sum=sum+marks[i];
		}
	}
	else
	{
		printf("WARNING ...enter M or F\n");
		sum = 0;
	}
	
return sum;
}	

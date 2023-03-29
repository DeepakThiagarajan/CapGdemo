#include<stdio.h>
#include<stdlib.h>

int main()
{
	int res,a,b,ch=0;
	printf("Enter 2 values:\n");
	scanf("%d %d",&a,&b);
	printf("Select 1-add 2-sub 3-mul 4-div\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			res=a+b;
			printf("\n Addition of 2 numbers is %d",res);
			break;
		case 2:
			res= a-b;	
			printf("\n Subtraction of 2 numbers is %d",res);
			break;
		case 3:
			res = a*b;
			printf("\n Multiplication of 2 numbers is %d",res);
			break;
		case 4:
			res = a/b;
			printf("\n Division of 2 numbers is %d",res);
			break;
		default:
			printf("Invalid Choice!!\n");
			break;
	}
	printf("\n\n");
	return 0;
} 

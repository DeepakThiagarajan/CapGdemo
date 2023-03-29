#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,res,ch=0;
	printf("Enter 2 values:\n");
	scanf("%d %d",&a,&b);
	printf("Enter 1-square 2-rectangle 3-circle\n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			res = a*a;
			printf("\n Area of Square is %d",res);
			break;
		case 2:
			res = a*b; 
			printf("\n Area of Rectangle is %d",res);
			break;
		case 3:
			res = 3.14 * a * a;
			printf("\n Area of Circle is %d",res);
			break;
		default:
			printf("Invalid Choice !!\n");
			break;
	}
	printf("\n");
	return 0;
}

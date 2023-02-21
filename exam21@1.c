#include <stdio.h>
#include <stdlib.h>

int sum(int,int);
int prod(int,int);
char disp();

int main()
{
	int op1,op2;
	char op;
	int result=0;

	printf("\nEnter two operands values:\n");
	scanf("%d%d",&op1,&op2);
	
	/*printf("\nEnter the operation to be carried out:");
	printf("\nEnter,\n+. Addition\n*. Product\nChoice: ");
	scanf(" ");
	scanf("%c",&op);
	*/
	
	op=disp();
	switch(op)
	{
		case '+':
			result=sum(op1,op2);
			printf("\nAddition of 2 numbers =%d",result);
			break;
			
		case '*':
			result=prod(op1,op2);
			printf("\nProduct of 2 numbers =%d",result);
			break;
		default:
			printf("\nWrong operator entered\n");
	}

	printf("\n\n");

	return(EXIT_SUCCESS);
}

int sum(int op1,int op2)
{
	return(op1+op2);
}

int prod(int op1,int op2)
{
	return(op1*op2);
}

char disp()
{
	char ch;

	printf("\nEnter the operation to be carried out:");
	printf("\nEnter,\n+. Addition\n*. Product\nChoice: ");
	scanf(" ");
	scanf("%c",&ch);
	return ch;
}

#include "myHeader.h"
#include <sum.h>
#include <multi.h>
#include <disp.h>

int main()
{
	int op1,op2;
	char op;
	int result =0;	
	#ifdef DEBUG
		printf("\nEnter two operands values:\n");
		scanf("%d%d",&op1,&op2);
	#else
		printf("\nEnter one operand values:\n");
		scanf("%d",&op1);
		op2=op1;
	#endif

	
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


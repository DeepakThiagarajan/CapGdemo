#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct employee
{
	int id;
	long phno;
	char name[20];
};
typedef struct employee emp;

void disp1(emp);

int main(int argc,char **argv)
{
	emp emp1,emp2;
	
	printf("\nEmployee details are :");

	printf("\nEmployee1 Details");

	emp1.id=atoi(argv[1]);
	emp1.phno=atol(argv[2]);
	strcpy(emp1.name,argv[3]);
	
	disp1(emp1);

	printf("\nEmployee2 Details");
	
	emp2.id=atoi(argv[4]);
	emp2.phno=atol(argv[5]);
	strcpy(emp2.name,argv[6]);
	
	disp1(emp2);
	
	printf("\n\n");
	exit(EXIT_SUCCESS);

}

void disp1(emp e1)
{
	printf("\nEmpid:");
	printf("%d",e1.id);

	printf("\nEmpphone:");
	printf("%ld",e1.phno);

	
	printf("\nEmpname:");
	printf("%s",e1.name);
}

#include<stdio.h>
#include<stdlib.h>
#include<myHeader.h>

int main()
{
	int n=0,suid=0,ch;
	n=inputEmployee();
	EMP *empl = (EMP *) malloc ( n * sizeof(EMP));
	
	printf("\n Enter 1.Sort \t 2.Search for id \t 3.exit");
	scanf("%d",&ch);
	fileToStruct(emp1,n);
	switch(ch)
	{
		case 1:
			bubbleSorting(empl,n);
			break;
		case 2:
			printf("\nEnter employee ID to search: ");
			scanf("%d",&suid);
			searchEmployee(empl,n,suid);
			break;
		case 3:
			printf("Exiting!!");
			break;
		default:
			printf("Enter valid case");
			break;
	}
	return EXIT_SUCCESS;
}

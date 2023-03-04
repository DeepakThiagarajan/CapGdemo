#include<stdio.h>
#include<string.h>
#include<persons.h>

int getPDetails(PERSON *p)
{
	int pid;

	printf("\nEnter,");
	printf("\nName: ");
	scanf("%s",p->name);

	printf("\nUID: ");
	scanf("%d",&p->uid);

	printf("\nPassword: ");
	scanf("%s",p->password);

	printf("\nPhone: ");
	scanf("%d",&p->phno);

	printf("\nGender(M/F/O): ");
	scanf(" ");
	scanf("%c",&p->gender);

	printf("\nEmail ID: ");
	scanf("%s",p->email);

	printf("\nAge: ");
	scanf("%d",&p->age);

	printf("\nAddress: ");
	scanf("%s",p->address);
	
	pid = 101;
	return pid;
}

void printPDetails(PERSON *p)
{
	printf("\n----User Details are --- \n");
	
	printf("\nName: ");
	printf("%s",p->name);

	printf("\nUID: ");
	printf("%d",p->uid);

	printf("\nPassword: ");
	printf("%s",p->password);

	printf("\nPhone: ");
	printf("%d",p->phno);

	printf("\nGender(M/F/O): ");
	
	printf("%c",p->gender);

	printf("\nEmail ID: ");
	printf("%s",p->email);

	printf("\nAge: ");
	printf("%d",p->age);

	printf("\nAddress: ");
	printf("%s",p->address);
	
}

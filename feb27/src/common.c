#include <common.h>

int dispMain()
{
	int ch;
	printf("\nSelect,");
	printf("\n1.SignUp\n2.SignIn\n3.Exit\nChoice:");
	scanf("%d",&ch);

	return ch;
}

int signUp(PERSON *p)
{
	int pid = getPDetails(p);
	
	return pid;
}
//int signIn(PERSON *p, login *l);

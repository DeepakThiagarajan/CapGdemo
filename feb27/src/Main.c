#include<common.h>
#include<persons.h>
#include<ticket.h>
#include<login.h>

int main()
{
	PERSON p;
	int pid=0;
	switch(dispMain())
	{
		case 1:
			pid=signUp(&p);
			printPDetails(&p);
			printf("\nPID : %d",pid);
			break;
		case 2:
			//signIn();
			break;
		case 3:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("\nWrong Choice:");
	}
	printf("\n\n");
	return 0;
}


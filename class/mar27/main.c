#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{	
	int ch;
	printf("\n Enter choice (1 for cal or 2 for area):\n");
	scanf("%d",&ch);
	printf(" Menu Driven code \n");
//	if(fork()>0)
//	{
//		wait(0);
//	}
//	else
//	{
		switch(ch)
		{
			case 1:
				if(fork()>0)
				{				
					printf("Calling Calci Program\n");
					wait(0);
					printf("Ended calci!!\n");
				}
				else
				{
					sleep(2);
					execl("/home2/trainee46/base/CapGdemo/mar27/sCal","/home2/trainee46/base/CapGdemo/mar27/sCal",(char *)0);
				}
				break;
			case 2:
				if(fork()>0)
				{
					printf("Calling Area Program\n");
					wait(0);
					printf("Ended Area!!\n");
				}
				else
				{
					sleep(3);
					execl("/home2/trainee46/base/CapGdemo/mar27/sArea","/home2/trainee46/base/CapGdemo/sArea",(char *)0);
				}
				break;
			default:
				printf("\nInvalid choice !!\n");
				break;
		}
//	}
	printf("\n\n");
	return 0;
}
				

	

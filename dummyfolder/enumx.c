#include <stdio.h>
#include <stdlib.h>

int main()
{
	enum Week{MON=5,TUE,WED,THU,FRI,SAT};
	enum bool{false =0,true};
	enum Week day1;

	day1=WED;
	enum bool flag=true;

	printf("\nday1 - %d",day1);
	printf("\nflag - %d", flag);

	printf("\n\n");

	return(EXIT_SUCCESS);
}

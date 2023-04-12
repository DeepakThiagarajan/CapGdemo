#include <stdio.h>
int main()
{
	int n;
	printf("\n This program is to print any of the delhi mumbai chennai Mumbai as output\n");
	printf("\nEnter a number between 1 to 4:");
        scanf("\n%d",&n);
	
	switch(n)
	{
		case 1:

			printf("delhi");
			break;
		case 2:

			printf("mumbai");
			break;
		case 3:

			printf("chennai");
			break;
		case 4:
			
			printf("Mumbai");
			break;
		default:
			printf("\nThank you");
			break;
	}
return 0;
}

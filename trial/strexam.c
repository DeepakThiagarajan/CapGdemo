#include <stdio.h>

int main()
{
	char name[50];

	scanf("%[^\n]s",name);
	//fgets(name,49, stdin);

	printf("\n name: %s\n",name);

	return 0;

}

#include<stdio.h>
#include<string.h>

int main()
{
	char s1[20];
	char s2[20];
	int result=0;

	printf("\nEnter the values of s1 and s2:\n");
	scanf("%s%s",s1,s2);
	
	result=strcmp(s1,s2);

	printf("\nResult= %d",result);

	printf("\n\n");

	return 0;
}


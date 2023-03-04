#include<stdio.h>
#include<ctype.h>
#include<string.h>
/*
void toUpper(char[]);

int main()
{
	char s1[20];

	printf("\nEnter the string:\n");
	scanf("%s",s1);

	toUpper(s1);
	printf("\nAfter converting: %s\n",s1);

	printf("\n\n");
	return 0;
}

void toUpper(char s1[]){
	int i;
	for(i=0;s1[i];i++)
	{
		if(s1[i]>='a' && s1[i]<='z')
			s1[i]=s1[i]-'a'+'A';
	}
}
*/
int main()
{
	char sName[20]="bhima shANKAR @1234";
	int i;

	for(i=0;i<strlen(sName);i++)
	{
		sName[i] = toupper(sName[i]);

	}
	printf("\n Converted String: %s",sName);

	printf("\n\n");
	return 0;
}

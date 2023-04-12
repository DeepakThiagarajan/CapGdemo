#include<stdio.h>

int main()
{
	char sent[100];

	printf("\nEnter a sentence: ");
	//scanf("%[^n]s\n",name);
	fgets(sent,99,stdin);

	oneWord(sent);
	return 0;
}
void oneWord(char sent[])
{
	int i;
	for(i=0;sent[i]!='\0';i++)
	{
		printf("%c",sent[i]);

		if(sent[i]==' ')
		{
			printf("\n");
		}
	}
}
void longWord(char sent[])
{
	char str[max_str];
	char long_str
}
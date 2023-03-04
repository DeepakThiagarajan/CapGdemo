#include <stdio.h>
#include<string.h>

int main()
{
	char str[20]="HelloWorld";
	int count[200]={0};
	int i;

	for(i=0;i<strlen(str);i++)
	{
		count[str[i]]++;
	}

	printf("Character frequency:\n");
	for(i=0;i<200;i++){
		if(count[i]>0)
		{
			printf("%c: %d\n",i,count[i]);
		}
	}
	return 0;
}

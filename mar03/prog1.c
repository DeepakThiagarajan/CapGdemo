#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	//char s[]="this is a C class";
	char s[]="|1001|Airtel|1002|101|This is a message";
	int count=0;
	char *token;
	/*
	token = strtok(s," ");
	printf("token1: %s",token);
	
	token = strtok(NULL," ");
	printf("token2: %s",token);
	
	token = strtok(NULL," ");
	printf("token3: %s",token);
	
	token = strtok(NULL," ");
	printf("token4: %s",token);
	
	token = strtok(NULL," ");
	printf("token5: %s",token);
	
	token = strtok(NULL," ");
	printf("token6: %s",token);
	*/
	token = strtok(s,"|");
	while(token != NULL)
	{	
		printf("\nToken %d: %s",count+1,token);
		token = strtok(NULL,"|");
		count++;
	}
	printf("\nNo of words in string are %d",count);		
	printf("\n\n");


	return 0;
}

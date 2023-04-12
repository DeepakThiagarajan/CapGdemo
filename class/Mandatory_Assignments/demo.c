#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int main()
{
	FILE *fptr = fopen("text.txt","r");
	if(fptr == NULL)
	{
		perror("cant open");
		exit(1);
	}
	char line[100];
	while(fgets(line,sizeof(line),fptr))
{
	printf("%s",line);
}	

	return 0;
}
*/
/*
int main()
{
	char str[100];
	int len=0;
	char rev[100];
	int index=0;

	printf("Enter a string:");
	gets(str);

//	printf("string is: \n%s",str);

	while(str[len] != '\0')
	{
		len++;
	}
//	printf("len is: \n%d",len);

	for(int i=len-1;i>-1;i--)
	{
		rev[index]=str[i];
		index++;
	}
	printf("reversed : %s\n",rev);
}
*/

/*
int main()
{
	char str[20];
	int len=0;
	
	printf("\nEnter string:");
	scanf("%s",str);
	
	while(str[len] != '\0')
		len++;
	printf("\nlen of str: %d \n",len);

	return 0;
}
*/

/*
int main()
{
	int num,temp,rev=0;
	printf("Enter a number: ");
	scanf("%d",&num);

	while( num != 0)
	{
		temp = num % 10;
		rev = (rev*10)+temp;
		num = num /10;
	}
	printf("rev: %d\n",rev);

	return 0;
}
*/
/*
int main()
{
	int num,temp1,temp2=0;
	printf("enter a number min 2 digits: ");
	scanf("%d",&num);

	while(num != 0)
	{
		temp1 = num % 10;
		temp2 = temp2 + temp1;
		num = num /10;
	}

	printf("sum: %d\n",temp2);
	
	return 0;
}
*/

int main()
{
	FILE *fptr = fopen("text.txt","r");
	if( fptr == NULL)
	{
		perror("cant open file");
		exit(1);
	}

	char line[100];

	while(fgets(line,sizeof(line),fptr))
	{
		char *token;
		token=strtok(line," ");
		
		while(token != NULL)
		{
			printf("%s",token);
			token=strtok(NULL," ");
		
		}

		printf("\n\n");
	}
}
		

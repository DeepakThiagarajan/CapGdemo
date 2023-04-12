#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define lsize 1024
char **split_words(char *,int *);

int main()
{
	char *str;
	char **words;
	int cwords=0;
	str=(char *)malloc(lsize*sizeof(char));
	
	fgets(str,lsize,stdin);
	//str[strlen(str)-1]='\0';
	
	strcpy(str,strtok(str,"\n"));
	puts(str);
	
	words=split_words(str,&cwords);

	for(int it=0;it<cwords;it++)
		printf("\n%s",words[it]);
	
	printf("\nAfter Sorting\n");

	sortwords(str,&cwords);

	for(int it=0;it<cwords;it++)
		printf("\n%s",words[it]);

	printf("\n\n");
	return 0;
}

char **split_words(char *str,int *ptr)
{
	char **splits=NULL;
	char *tokens = strtok(str, ",");
	int spaces=0;
	int count=0;

	while(tokens)
	{
		count++;
		splits=realloc(splits,sizeof(char *) * ++spaces);
		if(!splits)
			return splits;
		
		splits[spaces - 1]= tokens;
		tokens= strtok(NULL, ",");
		
	}
	*ptr=count;
	return splits;

}
char **sortwords(char **words,int c)
{
	int i,j;
	char *temp;
	for(i=0;i<c;i++)
	{
		for(j=i;j<c;j++)
		{
			memset(temp,'\0',lsize);
			if(strcmp(words[i],words[j])>0)
			{
				strcpy(temp,words[i]);
				strcpy(words[i],words[j]);
				strcpy(words[j],temp);
			}
		}
	}
	return words;
}

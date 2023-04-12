#include<stdio.h>
#include<string.h>

void sortStr(char []);

int main()
{
	char str[20] = "have a happy day";
	
	sortStr(str);
	printf("\nSorted String: %s",str);

	printf("\n\n");

	return 0;
}
void sortStr(char str[])
{
	int i,j;
	char temp;
	
	for(i=0;i<(strlen(str))-1;i++)
	{
		for(j=i+1;j<strlen(str);j++)
		{
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
}

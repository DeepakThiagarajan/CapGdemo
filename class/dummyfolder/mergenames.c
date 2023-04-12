#include<stdio.h>
#include<string.h>

int main()
{
	char a[100],b[100];
	char c[200];

	printf("\nEnter first name:");
	scanf("%s",a);

	printf("\nEnter second name:");
	scanf("%s",b);

	int i=0,j=0;

	for(i=0;i<strlen(a)||i<strlen(b);i++)
	{
		if(i<strlen(a))
		{
			c[j]=a[i];
			j++;
		}
		if(i<strlen(b))
		{
			c[j]=b[i];
			j++;
		}
	}
	printf("%s",c);

	return 0;
}

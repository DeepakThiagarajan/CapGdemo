#include<stdio.h>
#include<string.h>

int main()
{
	char sName[20]="Deepak";
	char dName[20]={'\0',};

	memset(dName,'C',10);

	strcpy(dName,sName);

	printf("\ndName =%s",dName);

//	memset(dName,'\0',20);

	strncpy(dName,"AAAAA",3);

	printf("\ndName= %s",dName);
	printf("\n\n");
	
	return 0;
}

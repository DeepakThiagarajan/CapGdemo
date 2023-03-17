#include<stdio.h>
#include<string.h>

union data
{
	int a;
	float b;
	char c[20];

}data1;

struct Data
{
	int a;
	float b;
	char c[20];
}Data1;

int main()
{
	//struct Data Data1;
	//union data data1;
	
	printf("\n%ld",sizeof(Data1));
	Data1.a=10;
	Data1.b=2.25;
	strcpy(Data1.c,"Welcome");
	printf("\nData1.a : %d",Data1.a);
	printf("\nData1.b : %f",Data1.b);
	printf("\nData1.c : %s",Data1.c);

	printf("\n%ld",sizeof(data1));
	data1.a=10;
	data1.b=2.25;
	strcpy(data1.c,"Welcome");

	printf("\ndata1.a : %d",data1.a);
	printf("\ndata1.b : %f",data1.b);
	printf("\ndata1.c : %s",data1.c);
	printf("\n\n");

	return 0;
}

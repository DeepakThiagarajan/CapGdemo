#include<stdio.h>
#include<stdlib.h>
#include<disp.h>

char disp()
{
	char ch;
	printf("Enter opertaion to carry:");
	printf("\nEnter +.Addition\n*.Product\nChoice: ");
	scanf(" ");
	scanf("%c",&ch);
	return ch;
}

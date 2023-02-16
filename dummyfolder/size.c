#include <stdio.h>

extern int MAX_SIZE;

int main()
{
	int arr[MAX_SIZE];
	int i;

	for(i=0;i<MAX_SIZE;i++)
		scanf("%d",&arr[i]);
	
	printf("\nElements\n");

	for(i=0;i<MAX_SIZE;i++)
		printf("%d ",arr[i]);
	
	printf("\n\n");
	return 0;
}
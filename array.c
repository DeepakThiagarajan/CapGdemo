#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int main()
{
	int n,end,i,temp;
	int *arr;

	printf("Enter the size of array:");
	scanf("%d",&n);
	end =n;
	arr=(int *)malloc(n*sizeof(int));

	printf("Enter Array Elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array Elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nArray after reverse:\n");

	for(i=0;i<n/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[end-1];
		arr[end-1]=temp;
		end--;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
	
	return 0;
}

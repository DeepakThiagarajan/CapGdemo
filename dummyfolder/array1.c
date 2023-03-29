#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j;
	int *arr;
	int temp;
	int flag=0;
	printf("Enter the array size:");
	scanf("%d",&n);

	arr=(int *)malloc(n*sizeof(int));
	printf("Enter the array elements\n");	
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}


	for(i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
	
			if(arr[i]>arr[j])
			{	
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(j=arr[0];j<arr[n-1];j++)
	{
		for(i=0;i<n;i++)
		{	
			if(arr[i]==j)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("\nElement Missing: %d",j);
		}
		flag=0;
	}

	printf("\n");	
	return 0;
}
		

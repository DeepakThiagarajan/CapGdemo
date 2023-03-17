#include<stdio.h>
#include<string.h>
#define row 1024
#define col 1024
void sortn(char **,int);


int main()
{
	char arr[row][col];
	int i,n;:
	printf("\nEnter number of names:");
	scanf("%d",&n);

 	for(i=0;i<n;i++)
	{
		printf("\nEnter the names %d:",i+1);
		scanf(" ");
		fgets(arr[i],1023,stdin);
		

	}
	sortn(arr[n][col],n);

	printf("\nAfter sorting");
	for(i=0;i<n;i++)
		printf("\n%s",arr[i]);

	return 0;
}

void sortn(char arr[n][col],int n)
{
	int i,j;
	char temp[1024];

	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(strcmp(arr[i],arr[j])>0)
			{
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}
		}
	}

}

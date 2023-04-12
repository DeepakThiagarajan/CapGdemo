#include<stdio.h>
#include<stdlib.h>

void insert(int value);
void insertAt(int value,int index);
void delete(int value);
void traverse();
void bubbleSort();
void linerSearch(int value);
void update(int value,int index);

int main()
{
	int choice,value,index;
	printf("1.Insert\n2.Insert AT\n3.Delete\n4.Traverse\n5.Bubble Sort\n6.Liner Search\n7.Update\n8.Exit\n");
	printf("\nEnter the choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("Enter the values to insert:");
			scanf("%d",&value);
			insert(value);
			break;
		case 2:
			printf("Enter the value to insert:");
			scanf("%d",&value);
			printf("Enter the position to insert:");
			scanf("%d",&index);
			insertAt(value,index);
			break;
		case 3:
			printf("Enter the value to deleted:");
			scanf("%d",&value);
			delete(value);
			break;
		default:
			printf("Invalid choice...\n");
			break;
	}
	return 0;
}

void insert(int value)
{
	

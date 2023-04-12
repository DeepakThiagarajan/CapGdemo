#include <stdio.h>

int main()
{
	float radius,area;
	const float pi=3.14159;

	printf("\nEnter the units of length of circle:");
	scanf("%f",&radius);

	area=pi*radius*radius;

	if(radius<0)
		printf("\n Error:Negative values not permitted");
	if(radius>0)
		printf("\n The area of a circle of radius %f units is %f",radius,area);

	return 0;
}
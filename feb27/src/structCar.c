#include <stdio.h>
#include<string.h>

int main()
{
	struct car
	{
		int carno;
		char  chassisno[15];
		char modelname[20];
		char color[10];
		float price;

	}car;

	car.carno = 4232;
	strcpy(car.chassisno,"DL792012930");
	strcpy(car.modelname,"MARUTHI SWIFT XL");
	strcpy(car.color,"NAVY BLUE");
	car.price = 450000.30;

	printf("\nCarno: %d", car.carno);
	printf("\nCar Chassis: %s", car.chassisno);
	printf("\nModel Name: %s", car.modelname);
	printf("\nCar Color: %s", car.color);
	printf("\nOnRoad Price: %f", car.price);

	printf("\n\n");
}

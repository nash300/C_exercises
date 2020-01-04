/*
This program reads radius of a circle 
and calcualates the area of that circle (A)
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>
int main()
{
	double radius, area, Pi = 3.14159;

	printf("This program calculates the area of a circle.\n");
	printf("Radius of a circle? ");
	radius = getReal();
	area = Pi * pow(radius, 2);
	printf("The area of the circle is %g\n", area);

	system("pause");
	return 0;
}
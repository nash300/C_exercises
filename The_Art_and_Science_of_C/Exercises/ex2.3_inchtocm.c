#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
	double cm;
	int feet, inch, totallinches;
	printf("This program converts feet and inches to cm.\n");
	printf("Number of feet? ");
	feet = getReal();
	printf("Number of iches? ");
	inch = getReal();
	totallinches = feet * 12 + inch;
	cm = totallinches * 2.54;

	printf("Cosserponding length is %g cm.\n", cm);

	system("pause");
	return 0;
}
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
	double totallinches, inch, cm;
	int feet;
	printf("this prog converts cm to feet and inches.\n");
	printf("length in cm? : ");
	cm = getReal();
	totallinches = cm / 2.54;
	feet = totallinches / 12;
	inch = totallinches - feet * 12;
	printf("%g cm = %d ft and %g inc\n", cm, feet, inch);

	system("pause");
	return 0;
}
/* file: leapyear.c
------------------------------------
* This program determines whether a year is a leap year.
*/
#include <stdio.h>
#include "genlib.h"


int main()
{
	int year;
	bool isLeapYear; // This data type is defined in genlib.h, which also defines constants TRUE and FALSE.

	printf("This program determines whether a year is a leap year.\n");
	printf("What year? \n");
	year = getInteger();
	isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if (isLeapYear) {
		printf("%d is a leap year.\n", year);
	}
	else {
		printf("%d is not a leap year.\n", year);
	}
	system("pause");
	return 0;
}

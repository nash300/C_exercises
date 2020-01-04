/* file: signtest.c
------------------------------------
* This program reads an integer and determines whether that number is positive, negative or zero.
*/
#include <stdio.h>
#include "genlib.h"


int main()
{
	int n;
	
	printf("Program to classify a number by its sign.\n");
	printf("Number? ");
	n = getInteger();

	if (n > 0) {
		printf("That number is positive.\n");
	}
	else if (n == 0) {
		printf("That number is zero.\n");
	}
	else {
		printf("That number is negative.\n");
	}
	system("pause");
	return 0;
}

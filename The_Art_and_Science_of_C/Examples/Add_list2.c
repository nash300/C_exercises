/*
This program adds a list of numbers.
Entering 0 indicates end of the input.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>
int main()
{
	int value, total = 0;

	printf("This program adds a list of numbers.\n");
	printf("Signal end of list with 0.\n");
	printf(" ? ");
	value = getInteger();
	while (value != 0) {
		total += value;
		printf(" ? ");
		value = getInteger();
	}

	//Using the break statement

	/*while (TRUE){
		printf(" ? ");
		value = getInteger();
		if (value == 0) break;
		total += value;
	}*/
	printf("total nummbers: %d\n", total);
	system("pause");
	return 0;
}
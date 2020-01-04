/*
This program adds a list of numbers.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>
int main()
{
	int value, i, n, total = 0;

	printf("This program adds a list of numbers.\n");
	printf("How many numbers are in the list? ");
	n = getInteger();
	for (i = 0; i < n; i++)
	{
		printf(" ? ");
		value = getInteger();
		total += value;
	}
	printf("total nummbers: %d\n", total);
	system("pause");
	return 0;
}
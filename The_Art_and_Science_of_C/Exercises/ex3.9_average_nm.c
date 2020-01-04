/* file: ex3.9.c
------------------------------------
* This program reads a list of integers and displays the average.
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"



int main()
{
	int value, total = 0, numbers = 0;
	double average;
	
	printf("This program averages a list of integers.\n");
	printf("Enter -1 to signal the end of the list.\n");

	while(TRUE)
	{
		printf("? ");
		value = getInteger();
		if (value == -1) break;
		total += value;
		numbers++;
	}
	average = (double)total / numbers;
	printf("The average is %.2f\n", average);
	system("pause");
	return 0;
}
/* file: ex4.3_sumodd.c
-------------------------
* This program reads integer n and calculates the sum of the first n odd integers (1+3+5..).
*/
#include <stdio.h>
#include "genlib.h"



int main()
{
	int n, number, summed, sum = 0;

	printf("Program to sum positive odd integers (1+3+5...).\n");
	printf("How many? ");
	n = getInteger();
	summed = 0;
	number = 1;
	while (summed < n) {
		if (number % 2 != 0) {
			sum += number;
			summed++;
		}
		number++;
	}
	printf("The sum of the first %d odd integers is %d.\n",n, sum);
	
	system("pause");
	return 0;
}

/* file: ex3.10_squares.c
------------------------------------
* This program prints out squares and cubes of numbers 1 to 10.
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"



int main()
{
	int i, max = 10, square, cube;

	printf("Number   Square   Cube\n");
	for (i = 1; i <= max; i++)
	{
		square = i * i;
		cube = i * i * i;
		printf("%5d    %5d   %5d\n", i, square, cube);
	}
	system("pause");
	return 0;
}

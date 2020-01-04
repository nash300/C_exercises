/* file: timestab.c
-------------------------
* This program prints out 10x10 multiplication table.
*/
#include <stdio.h>
#include "genlib.h"

/*
* Constants 
-----------
* LOWERLIMIT -- starting value for the table
* UPPERLIMIT -- final value for the table
*/
#define LOWERLIMIT 1
#define UPPERLIMIT 10


int main()
{
	int i, j;
	for (i = LOWERLIMIT; i <= UPPERLIMIT; i++) {
		for (j = LOWERLIMIT; j <= UPPERLIMIT; j++) {
			printf(" %4d", i * j);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}

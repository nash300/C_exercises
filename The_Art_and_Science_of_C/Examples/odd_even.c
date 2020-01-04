/* file: odd_even.c
------------------------------------
* This program reads an integer and determines whether that number is odd or even.
*/
#include <stdio.h>
#include "genlib.h"


int main()
{
	int n;
	
	printf("This program determines whether a number is odd or even.\n");
	printf("Number? ");
	n = getInteger();
	if (n % 2 == 0) {
		printf("Number %d is even.\n", n);
	}
	else {
		printf("Number %d is odd.\n", n);
	}
	system("pause");
	return 0;
}

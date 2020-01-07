/* file: factorial.c
-------------------------
* This program prints out the factorials of the numbers between the limits LOWERLIMIT and UPPERLIMIT, inclusive.
*/
#include <stdio.h>
#include "genlib.h"


/*
* Constants
*  ----------
* LOWERLIMIT -- starting value for factorial table
* UPPERLIMIT -- finale value for factorial table
*/

#define LOWERLIMIT   0
#define UPPERLIMIT   7

/* Function prototypes */

int Factorial(int n);

int main()
{
	int i;

	for (i = LOWERLIMIT; i <= UPPERLIMIT; i++) {
		printf("%d! = %5d\n", i, Factorial(i));
	}
	
	getchar();
	return 0;
}

/*
* Function: Factorial
* -------------------------------
* This function returns the factorial of the argument n.
*/

int Factorial(int n) {
	int product, i;
	product = 1;
	for (i = 1; i <= n; i++) {
		product *= i;
	}
	return (product);
}
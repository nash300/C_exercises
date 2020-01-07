/* file: c2ftable.c
-------------------------
* This program generates a table of Celsius to Fahrenheit conversions.
*/
#include <stdio.h>
#include "genlib.h"


/*
* Constants
*  ----------
* LOWERLIMIT -- starting value for temperature table
* UPPERLIMIT -- finale value for tempratue table
* STEPSIZE   -- step size between table entries
*/

#define LOWERLIMIT   0
#define UPPERLIMIT 100
#define STEPSIZE     5

/* Function prototypes */

double CelciusToFahrenheit(double c);

int main()
{
	int c;

	printf("Celcius to Fahrenheit table.\n");
	printf("  C   F\n");
	for (c = LOWERLIMIT; c <= UPPERLIMIT; c += STEPSIZE) {
		printf("%3d  %3g\n", c, CelciusToFahrenheit(c));
	}
	
	getInteger();
	return 0;
}

/*
* Function: CelciusToFahrenheit
* -------------------------------
* This function returns the Fahrenheit equivalent of the Celcius temperature c.
*/

double CelciusToFahrenheit(double c) {
	return  (9.0 / 5.0 * c + 32);
}
/* file: digitsum.c
------------------------------------
* This program reads an integer and displayes the sum of its digits.
*/
#include <stdio.h>
#include "genlib.h"


int main()
{
	int n, dsum;
	
	printf("This program sums the digits in an integer.\n");
	printf("Enter a positive integer: ");
	n = getInteger();
	dsum = 0;
	while (n > 0) {
		dsum += n % 10;
		n /= 10;
	}
	printf("The sum of the digits is %d\n", dsum);
	system("pause");
	return 0;
}

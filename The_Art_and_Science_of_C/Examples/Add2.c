#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
	int n1, n2, total;

	printf("This program adds two numbers.\n");
	printf("First number: ");
	n1 = getInteger();
	printf("Second number: ");
	n2 = getInteger();
	total = n1 + n2;
	printf("The total is: %d\n", total);

	system("pause");
	return 0;
}
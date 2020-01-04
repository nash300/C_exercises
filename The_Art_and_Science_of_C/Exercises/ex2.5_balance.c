/*
This program reads an account balance and displays the new balance
accourding to given annual interest rate expressed as a persentage.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
	double year1, year2, interest, balance;

	printf("Interest calculation program.\n");
	printf("Starting balance? ");
	balance = getReal();
	printf("Annual interest rate percentage? ");
	interest = getReal();
	year1 = balance + balance * (interest / 100);
	year2 = year1 + year1 * (interest / 100);

	printf("Balance efter 1 year: %g\n", year1);
	printf("Balance efter 2 years: %g\n", year2);

	system("pause");
	return 0;
}
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
	double newbalance, interest, balance;
	//int balance;

	printf("Interest calculation program.\n");
	printf("Starting balance? ");
	balance = getReal();
	printf("Annual interest rate percentage? ");
	interest = getReal();
	newbalance = balance + balance * (interest / 100);

	printf("Balance efter 1 year: %g\n", newbalance);

	system("pause");
	return 0;
}
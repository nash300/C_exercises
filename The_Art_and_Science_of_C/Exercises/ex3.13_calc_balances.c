/* file: ex3.11_balance.c
------------------------------------
* This program reads an account balance and prints out new balances for each year (user enters the number of years)
* accourding to given annual interest rate expressed as a persentage.
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"



int main()
{
	double interest, balance, newBalance;
	int i, years;

	printf("Interest calculation program.\n");
	printf("Starting balance? ");
	balance = getReal();
	printf("Annual interest rate percentage? ");
	interest = getReal();
	printf("Balance after how many years? ");
	years = getInteger();

	printf("\nYear    Balance    New balance\n");

	for (i = 1; i <= years; i++)
	{
		newBalance = balance + balance * (interest / 100);
		printf("%4d    %7.2f    %10.2f\n", i, balance, newBalance);
		balance = newBalance;
	}
	system("pause");
	return 0;
}

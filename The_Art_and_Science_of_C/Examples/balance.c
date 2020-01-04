/*
* File: balance.c
*
* This program is for balancing a checkbook.
* Enter checks and deposits throughout the month (checks are entered as negative numbers).
* Enter 0 to end the inputs.
* To change the charge assesed for bounced checks, change the constant of BouncedCheckFee.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define BouncedCheckFee 10.00


int main()
{
	double entry, balance;

	printf("This program helps you balance your checkbook.\n");
	printf("Enter each check and deposit during the month.\n");
	printf("To indicate a check, use a minus sign.\n");
	printf("Signal the end of the month with a 0 value.\n");
	printf("Enter the initial balance: ");
	balance = getInteger();
	while (TRUE)
	{
		printf("Enter check (-) or deposit: ");
		entry = getReal();
		if (entry == 0) break;
		balance += entry;
		if (entry < 0 && balance < 0)
		{
			printf("This check bounces. $%.2f fee deducted.\n", BouncedCheckFee);
			balance -= BouncedCheckFee;
		}
		printf("Current balance = %.2f\n", balance);
	}
	printf("Final balance = %g\n", balance);
	system("pause");
	return 0;
}
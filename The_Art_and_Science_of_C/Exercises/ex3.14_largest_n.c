/* file: ex3.14_largest_n.c
------------------------------------
* This program reads a list of integers and prints out the largest of them
*/
#include <stdio.h>
#include "genlib.h"


int main()
{
	int number, largest = 0;

	printf("This program finds the largest integer in the list.\n");
	printf("Enter 0 to signal the end of the list.\n");
	while (TRUE)
	{
		printf("? ");
		number = getInteger();
		if (number == 0) break;
		if (number > largest)
		{
			largest = number;
		}
	}
	printf("The largest value is %d\n", largest);
	system("pause");
	return 0;
}

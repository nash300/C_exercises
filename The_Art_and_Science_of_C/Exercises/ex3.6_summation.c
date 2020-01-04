/* file: ex_3.6.c
------------------------------------
* This program computes the sum of the numbers between 1 and 100 and displays the result.
*/
#include <stdio.h>


int main()
{
	int i, max = 100, total = 0;

	for (i = 1; i <= max; i++)
	{
		total += i;
	}
	printf("The sum of the numbers between 1 and 100 is %d\n", total);
	system("pause");
	return 0;
}
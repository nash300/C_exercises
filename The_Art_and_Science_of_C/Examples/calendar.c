/* file: factorial.c
-------------------------
* This program is used to generate a calendar for a year
* entered by the user.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


/*
* Constants
*  ----------
* Days of the weeks are represented by the integers 0-6.
* Month of the year are identified by the integers 1-12.
*/

#define Sunday    0
#define Monday    1
#define Tuesday   2
#define Wednesday 3
#define Thursday  4
#define Friday    5
#define Saturday  6

/* Function prototypes */

void giveInstructions(void);
int getYearFromUser(void);
void printCalendar(int year);
void printCalendarMonth(int month, int year);
void indentFirstLine(int weekday);
int monthDays(int month, int year);
int firstDayOfMonth(int month, int year);
string monthName(int month);
bool isLeapYear(int year);

/* Main program */

int main()
{
	int year;

	giveInstructions();
	year = getYearFromUser();
	printCalendar(year);
	getchar();
	return 0;
}

/*
* Function: giveInstructions
* ---------------------------
* Prints out instructions to the user
*/

void giveInstructions(void)
{
	printf("This program displays a calendat for a full year.\n");
	printf("The year must not be before 1900.\n");
}

/*
* Function: getYearFromUser
* ------------------------
* Reads in a year from user and returns that value.
* If the user enters a year before 1900, the function gives another chance.
*/

int getYearFromUser(void)
{
	int year;

	while (TRUE) {
		printf("Which year? ");
		year = getInteger();
		if (year >= 1900) return (year);
		printf("The year must be at least 1900.\n");
	}
}

/*
* Function: printCalendar
* ------------------------
* This prosedure prints a calendar for an entire year.
*/

void printCalendar(int year)
{
	int month;

	for (month = 1; month <= 12; month++) {
		printCalendarMonth(month, year);
		printf("\n");
	}
}

/*
* Function: printCalendarMonth
* ------------------------
* This prosedure prints a calendar for the given month and year.
*/

void printCalendarMonth(int month, int year)
{
	int weekday, nDays, day;

	printf("    %s %d\n", monthName(month), year);
	printf(" Su Mo Tu We Th Fr Sa\n");
	nDays = monthDays(month, year);
	weekday = firstDayOfMonth(month, year);
	indentFirstLine(weekday);
	for (day = 1; day <= nDays; day++) {
		printf(" %2d", day);
		if (weekday == Saturday) printf("\n");
		weekday = (weekday + 1) % 7;
	}
	if (weekday != Sunday) printf("\n");
}

/* Function: indentFirstLine 
* -------------------------
* This procedure indents the first line of the calendar by printing enough blank spaces
* to get to the position on the line corresponding to weekday.
*/

void indentFirstLine(int weekday)
{
	int i;
	for (i = 0; i < weekday; i++) {
		printf("   ");
	}
}

/*
* Function: monthDays
* -------------------------
* monthDays returns the number if days in the indicated month abd year. 
* The year is required to handle leap years.
*/

int monthDays(int month, int year)
{
	switch (month) {
	case 2:
		if (isLeapYear(year)) return (29);
		return (28);
	case 4: case 6: case 9: case 11:
		return (30);
	default:
		return (31);
	}
}

/*
* Function: firstDayOfMonth
* ------------------------
* This function returns the day of the week on which the indicated month begins.
* This program simply counts forward from January 1, 1900, which was a Monday.
*/

int firstDayOfMonth(int month, int year)
{
	int weekday, i;

	weekday = Monday;
	for (i = 1900; i < year; i++) {
		weekday = (weekday + 365) % 7;
		if (isLeapYear(i)) weekday = (weekday + 1) % 7;
	}
	for (i = 1; i < month; i++) {
		weekday = (weekday + monthDays(i, year)) % 7;
	}
	return (weekday);
}

/*
* Function: monthName
* -------------------
* Converts a numeric month in the range 1-12 in to the string name for that month.
*/

string monthName(int month)
{
	switch (month) {
	case  1: return ("January");
	case  2: return ("Februry");
	case  3: return ("March");
	case  4: return ("April");
	case  5: return ("May");
	case  6: return ("June");
	case  7: return ("July");
	case  8: return ("August");
	case  9: return ("September");
	case 10: return ("October");
	case 11: return ("November");
	case 12: return ("December");
	default: return ("Illegal month");
	}
}

/*
* Function: isLeapYear
* --------------------
* This function returns TRUE if year is a leap year.
*/

bool isLeapYear(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
#pragma once
/*
* File: calendar.h
* -------------------------------------------
* Provides toools for coding calendar program
*/

#ifndef _calendar_h
#define _calendar_h


/* Include files necessary for the headerfile */
#include <stdio.h>


/*
* Constants
* ---------
* Defines days of the week as integers 0 to 6
* Defines the startyear as 1900
*/
#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define STARTYEAR 1900


/*
* Typedefinitions
* ---------
* Description ...
*/


/* Function prototypes */

/************************************************************************************
* Function: printCalendarMonth
* Usage: printCalendarMonth(month, year);
* -----------------------------------------------------------------------------------
* Prints a calendar for a given month and year, passed to the function.  
************************************************************************************/
void printCalendarMonth(int month, int year);

/************************************************************************************
* Function: monthName
* Usage: char *aMonthName = monthName(aMonthNumber);
* -----------------------------------------------------------------------------------
* Returns the name of the month as a string for a given month, passed to the function  
* as a number between 1 and 12.
************************************************************************************/
char * monthName(int month);

/************************************************************************************
* Function: indentFirstLine
* Usage: indentFirstLine(aWeekDayNumber);
* -----------------------------------------------------------------------------------
* This function indents the first line of the calendar by printing enough blank 
* spaces to get the position on the line corresponding to weekday, passed as a 
* value between 0 and 6.
************************************************************************************/
void indentFirstLine(int weekDay);

/************************************************************************************
* Function: isLeapYear
* Usage: int aBooleanValue = isLeapYear(aYear);
* -----------------------------------------------------------------------------------
* This function returns 1 (TRUE) if the year passed to the function is a leapyear. 
* Otherwise the function returns 0 (FALSE).
************************************************************************************/
int isLeapYear(int year);

/************************************************************************************
* Function: monthDays
* Usage: int daysInMonth = monthDays(aMonthNumber, aYear);
* -----------------------------------------------------------------------------------
* This function returns the number of days a certain month in a certain year has. 
* Month is passed as a number between 1 and 12, and year is passed as a number larger
* than STARTYEAR.
************************************************************************************/
int monthDays(int month, int year);

/************************************************************************************
* Function: firstDayOfMonth
* Usage: int aWeekDayNumber = firstDayOfMonth(aMonthNumber, aYear);
* -----------------------------------------------------------------------------------
* This function returns the number of the day in the week for the first day in a 
* month a certain year. Month is passed as a number between 1 and 12, and year is 
* passed as a number larger than STARTYEAR.
************************************************************************************/
int firstDayOfMonth(int month, int year);

#endif
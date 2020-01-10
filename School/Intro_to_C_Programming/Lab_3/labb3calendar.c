/* 
* file: lab3calendar.c
* --------------------
* Programmet har tv� olika meny-system (huvud meny och under meny) som man kan navigera mellan.
* Huvud menyn �r f�r att h�mta dag f�r ett viss datum eller helgdag och skriva ut m�nadskalender f�r givet m�nadsnummer.
* Under menyn hanterar helgdagar som man vill h�mta.
*/

#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

#define TRUE 1 //Anv�nds f�r while loop

/* Funktionsdeklarationer*/

int getYearFromUser(void);
int getMonthFromUser(void);
int getDayFromUser(void);
int underMeny(void);
void printWeekDay(void);
char* weekday(int day);
void printMonth(void);
void getChrismasDay(void);
void getNewYearDay(void);
void getMidsummerDay(void);


/* Main funktion */

int main(void)
{
	system("chcp 1252");
	system("cls");


	int menyVal1;

	do { 
		//Skriver ut huvud menyn.
		printf(" Huvud meny\n\n");
		printf(" **********\n\n");
		printf(" 1. H�mta dag f�r ett visst datum\n 2. H�mta dag f�r helgdag\n");
		printf(" 3. Skriv ut en m�nadskalender\n 0. Avsluta\n\n");
		printf(" Vilket alternativ v�ljer du? ");
		scanf_s("%d", &menyVal1);
		system("cls");

		switch (menyVal1) {
			case 1: printWeekDay(); //Skriver ut veckodag f�r datum anv�ndaren anger.
				break;
			case 2: underMeny(); //Skriver ut undermenyn.
				break;
			case 3: printMonth(); //Skriver ut m�nadskalendar f�r givet �r och m�nadsnummer.
				break;
			case 0:
				break;
			default: printf("\n Ogiltigt nummer!\n\n");
				break;
		}

	} while (menyVal1 != 0);

	return 0;
}

/************************************************************************************/

/* Funktionsdefinitioner */

// Funktion: underMeny
int underMeny(void)
{
	int menyVal2;

	do {
		//Skriver ut undermenyn
		printf(" H�mta dag f�r helgdag\n\n");
		printf(" *********************\n\n");
		printf(" 1. Juldag\n 2. Ny�rsdag\n");
		printf(" 3. Midsommardag\n 0. Tillbaka till huvudmenyn\n\n");
		printf(" Vilket alternativ v�ljer du? ");
		scanf_s("%d", &menyVal2);
		system("cls");

		switch (menyVal2) {
		case 1: getChrismasDay(); //Skriver ut juldagen f�r givet �r.
			break;
		case 2: getNewYearDay(); //Skriver ut ny�rsdagen f�r givet �r.
			break;
		case 3: getMidsummerDay(); //Skriver ut midsommar dagen f�r givet �r.
			break;
		case 0: 
			break;  // G�r tillbaka tll huvud menyn.
		default: printf("\n Ogiltigt nummer!\n\n");
		}
	} while (menyVal2 != 0);

	return 0;
}

/************************************************************************************/

// Funktion: printMonth
void printMonth(void)
{
	int year, month;

	year = getYearFromUser();
	month = getMonthFromUser();
	printCalendarMonth(month, year);
	printf("\n\n");
}

/************************************************************************************/

//Funktion: getYearFromUser
int getYearFromUser(void)
{
	int year;

	while (TRUE) {
		printf(" Ange �rtal (senare �n 1900): ");
		scanf_s("%d", &year);
		if (year >= 1900) return (year);
		printf("\n Ogiltigt nummer!\n\n");
	}
}

/************************************************************************************/

//Funktion: getMonthFromUser
int getMonthFromUser(void)
{
	int month;
	while (TRUE) {
		printf(" Ange m�nadsnumret (mellan 1-12): ");
		scanf_s("%d", &month);
		if (month >= 1 && month <= 12) return (month);
		printf("\n Ogiltigt nummer!\n\n");
	}

}

/************************************************************************************/

//Funktion: getDayFromUser
int getDayFromUser(void)
{
	int day;
	while (TRUE) {
		printf(" Ange dagnumret f�r m�naden: ");
		scanf_s("%d", &day);
		if (day >= 1 && day <= 31) return (day);
		printf("\n Ogiltigt nummer!\n\n");
	}
}

/************************************************************************************/

// Funktion: printWeekDay 
void printWeekDay(void)
{
	int day, month, year, date;

	date = getDayFromUser();
	month = getMonthFromUser();
	year = getYearFromUser();
	day = (firstDayOfMonth(month, year) + date - 1) % 7;
	printf("\n * Det �r en %s *\n\n", weekday(day));
}

/************************************************************************************/
// Funktion: weekday
char* weekday(int day)
{
	switch (day) {
	case 0: return "s�ndag";
		break;
	case 1: return "m�ndag";
		break;
	case 2: return "tisdag";
		break;
	case 3: return "onsdag";
		break;
	case 4: return "torsdag";
		break;
	case 5: return "fredag";
		break;
	case 6: return "l�rdag";
		break;
	default:
		printf("\n Ogiltigt nummer!\n\n");
	}
	return 0;
}

/************************************************************************************/

// Funktion: getChrismasDay
void getChrismasDay(void)
{
	int year, month, date, day;

	year = getYearFromUser();
	month = 12;
	date = 25;
	day = (firstDayOfMonth(month, year) + date - 1) % 7;
	printf("\n * Det �r en %s *\n\n", weekday(day));
}

/************************************************************************************/

// Funktion: getNewYearDay
void getNewYearDay(void)
{
	int year, month, day;

	year = getYearFromUser();
	month = 1;
	day = (firstDayOfMonth(month, year)) % 7;
	printf("\n * Det �r en %s *\n\n", weekday(day));
}

/************************************************************************************/

// Funktion: getMidsummerDay
void getMidsummerDay(void)
{
	int year, month, day;

	year = getYearFromUser();
	month = 6;
	day = firstDayOfMonth(month, year);
	switch (day) {
	case 0: printf("\n Det �r 21/6\n\n");
		break;
	case 1: printf("\n Det �r 20/6\n\n");
		break;
	case 2: printf("\n Det �r 26/6\n\n");
		break;
	case 3: printf("\n Det �r 25/6\n\n");
		break;
	case 4: printf("\n Det �r 24/6\n\n");
		break;
	case 5: printf("\n Det �r 23/6\n\n");
		break;
	case 6: printf("\n Det �r 22/6\n\n");
		break;
	default:
		printf("\n Ogiltigt datum!\n\n");
	}
}
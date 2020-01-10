/* 
* file: lab3calendar.c
* --------------------
* Programmet har två olika meny-system (huvud meny och under meny) som man kan navigera mellan.
* Huvud menyn är för att hämta dag för ett viss datum eller helgdag och skriva ut månadskalender för givet månadsnummer.
* Under menyn hanterar helgdagar som man vill hämta.
*/

#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

#define TRUE 1 //Används för while loop

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
		printf(" 1. Hämta dag för ett visst datum\n 2. Hämta dag för helgdag\n");
		printf(" 3. Skriv ut en månadskalender\n 0. Avsluta\n\n");
		printf(" Vilket alternativ väljer du? ");
		scanf_s("%d", &menyVal1);
		system("cls");

		switch (menyVal1) {
			case 1: printWeekDay(); //Skriver ut veckodag för datum användaren anger.
				break;
			case 2: underMeny(); //Skriver ut undermenyn.
				break;
			case 3: printMonth(); //Skriver ut månadskalendar för givet år och månadsnummer.
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
		printf(" Hämta dag för helgdag\n\n");
		printf(" *********************\n\n");
		printf(" 1. Juldag\n 2. Nyårsdag\n");
		printf(" 3. Midsommardag\n 0. Tillbaka till huvudmenyn\n\n");
		printf(" Vilket alternativ väljer du? ");
		scanf_s("%d", &menyVal2);
		system("cls");

		switch (menyVal2) {
		case 1: getChrismasDay(); //Skriver ut juldagen för givet år.
			break;
		case 2: getNewYearDay(); //Skriver ut nyårsdagen för givet år.
			break;
		case 3: getMidsummerDay(); //Skriver ut midsommar dagen för givet år.
			break;
		case 0: 
			break;  // Går tillbaka tll huvud menyn.
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
		printf(" Ange årtal (senare än 1900): ");
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
		printf(" Ange månadsnumret (mellan 1-12): ");
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
		printf(" Ange dagnumret för månaden: ");
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
	printf("\n * Det är en %s *\n\n", weekday(day));
}

/************************************************************************************/
// Funktion: weekday
char* weekday(int day)
{
	switch (day) {
	case 0: return "söndag";
		break;
	case 1: return "måndag";
		break;
	case 2: return "tisdag";
		break;
	case 3: return "onsdag";
		break;
	case 4: return "torsdag";
		break;
	case 5: return "fredag";
		break;
	case 6: return "lördag";
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
	printf("\n * Det är en %s *\n\n", weekday(day));
}

/************************************************************************************/

// Funktion: getNewYearDay
void getNewYearDay(void)
{
	int year, month, day;

	year = getYearFromUser();
	month = 1;
	day = (firstDayOfMonth(month, year)) % 7;
	printf("\n * Det är en %s *\n\n", weekday(day));
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
	case 0: printf("\n Det är 21/6\n\n");
		break;
	case 1: printf("\n Det är 20/6\n\n");
		break;
	case 2: printf("\n Det är 26/6\n\n");
		break;
	case 3: printf("\n Det är 25/6\n\n");
		break;
	case 4: printf("\n Det är 24/6\n\n");
		break;
	case 5: printf("\n Det är 23/6\n\n");
		break;
	case 6: printf("\n Det är 22/6\n\n");
		break;
	default:
		printf("\n Ogiltigt datum!\n\n");
	}
}
#include "pch.h"
#include <iostream>
#include <stdio.h>


int is_leap(int year)
{
	//sprawdzenie czy rok jest przestępny czy nie
	int ilosc_latz = year - 1970;
	int ilosc_latp = year - 1970;
	int licz_zwykle = 0; //liczy ilość lat przestępnych
	int licz_przestepne = 0; //liczy ilość lat zwykłych
	int year_type = 0; //typ roku- przestępny (0) lub zwykły (1); przyda się w wyświetlaniu kalendarza na luty

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		for (int i = 1972; i <= year; i += 4)
		{
			//printf("Rok przestepny");

			licz_przestepne++;

		}
		ilosc_latp = licz_przestepne;
		ilosc_latz = year - 1970 - licz_przestepne;
		year_type = 0;
		printf("\nRok jest przestepny. \n\n");
	}
	else
	{
		for (int i = 1970; i <= year; i++)
		{
			//printf("Rok zwykly");

			licz_zwykle++;

		}
		ilosc_latz = (licz_zwykle * 3) / 4;
		ilosc_latp = year - 1970 - ilosc_latz;
		year_type = 1;
		printf("\nRok nie jest przestepny. \n\n");
	}
	return 0;
}

int day_of_week(int day)
{
	//dzień tygodnia
	switch (day % 7)
	{
	case 1:
		printf("Dzisiaj jest wtorek\n");
		break;

	case 2:
		printf("Dzisiaj jest sroda\n");
		break;

	case 3:
		printf("Dzisiaj jest czwartek\n");
		break;

	case 4:
		printf("Dzisiaj jest piatek\n");
		break;

	case 5:
		printf("Dzisiaj jest sobota\n");
		break;

	case 6:
		printf("Dzisiaj jest niedziela\n");
		break;

	case 0:
		printf("Dzisiaj jest poniedzialek\n");
		break;
	}
	return 0;
}

int count_days(int day, int month, int ilosc_latz, int ilosc_latp, int days_since)
{
	//dokładna ilośc dni od 01.01.1970 (doliczone dni za wszysktie miesiące i dni w podanym na wejściu roku)
	days_since = (ilosc_latz * 365) + (ilosc_latp * 366);
	int more_days = 0;
	switch (month)
	{
	case 1:
		more_days = day - 1 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 2:
		more_days = day + 31 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case  3:
		more_days = day + 31 + 28 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 4:
		more_days = day + 31 + 28 + 31 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 5:
		more_days = day + 31 + 28 + 31 + 30 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 6:
		more_days = day + 31 + 28 + 31 + 30 + 31 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 7:
		more_days = day + 31 + 28 + 31 + 30 + 31 + 30 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 8:
		more_days = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 9:
		more_days = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 10:
		more_days = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 11:
		more_days = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;

	case 12:
		more_days = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + days_since;
		printf("Ilosc dni od 01.01.1970 to %d \n", more_days);
		break;
	}

	//printf("%d", more_days);
	return 0;
}

int calendar(int year, int month, int days_since, int year_type)
{
	//wyświetlenie kalendarza
	printf("\nKalendarz na miesiac %d.%d: \n\n", year, month);
	printf("Pn   Wt   Sr   Cz   Pt   Sb   Nd\n");

	//miesiące z liczbą dni = 31
	//wszystkie zapisy if(day%7==0 itd)  można uprościć tworząc zmienną przechowującą resztę ALE NAJPIERW NIECH TO ZACZNIE DZIAŁAĆ --> niech dni w pierwszym tygodniu wyświetlają się dobrze. 16.10.2010 prawie działa
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (days_since % 7 == 0)
		{
			for (int i = 1; i <= 31; i++)
			{
				if (i == 1)
					printf(" %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 0)
					printf("\n");
			}
		}

		if (days_since % 7 == 1)
		{
			for (int i = 1; i <= 31; i++)
			{
				if (i == 1)
					printf("     %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 6)
					printf("\n");
			}
		}

		if (days_since % 7 == 2)
		{
			for (int i = 1; i <= 31; i++)
			{
				if (i == 1)
					printf("         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 5)
					printf("\n");
			}
		}

		if (days_since % 7 == 3)
		{
			for (int i = 1; i <= 31; i++)
			{
				if (i == 1)
					printf("             %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 4)
					printf("\n");
			}
		}

		if (days_since % 7 == 4)
		{
			for (int i = 1; i <= 31; i++)
			{
				if (i == 1)
					printf("                 %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 3)
					printf("\n");
			}
		}

		if (days_since % 7 == 5)
		{
			for (int i = 1; i <= 31; i++)
			{
				if (i == 1)
					printf("                     %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 2)
					printf("\n");
			}
		}

		if (days_since % 7 == 6)
		{
			for (int i = 1; i <= 31; i++)
			{
				if (i == 1)
					printf("                         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 1)
					printf("\n");
			}
		}

	}

	//miesiące z liczbą dni = 30
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (days_since % 7 == 0)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1)
					printf(" %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 0)
					printf("\n");
			}
		}

		if (days_since % 7 == 1)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1)
					printf("     %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 6)
					printf("\n");
			}
		}

		if (days_since % 7 == 2)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1)
					printf("         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 5)
					printf("\n");
			}
		}

		if (days_since % 7 == 3)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1)
					printf("             %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 4)
					printf("\n");
			}
		}

		if (days_since % 7 == 4)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1)
					printf("                 %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 3)
					printf("\n");
			}
		}

		if (days_since % 7 == 5)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1)
					printf("                     %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 2)
					printf("\n");
			}
		}

		if (days_since % 7 == 6)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1)
					printf("                         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 1)
					printf("\n");
			}
		}
	}

	//luty w roku przestępnym
	if (month == 2 && year_type == 0)
	{
		if (days_since % 7 == 0)
		{
			for (int i = 1; i <= 29; i++)
			{
				if (i == 1)
					printf(" %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 0)
					printf("\n");
			}
		}

		if (days_since % 7 == 1)
		{
			for (int i = 1; i <= 29; i++)
			{
				if (i == 1)
					printf("     %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 6)
					printf("\n");
			}
		}

		if (days_since % 7 == 2)
		{
			for (int i = 1; i <= 29; i++)
			{
				if (i == 1)
					printf("         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 5)
					printf("\n");
			}
		}

		if (days_since % 7 == 3)
		{
			for (int i = 1; i <= 29; i++)
			{
				if (i == 1)
					printf("             %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 4)
					printf("\n");
			}
		}

		if (days_since % 7 == 4)
		{
			for (int i = 1; i <= 29; i++)
			{
				if (i == 1)
					printf("                 %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 3)
					printf("\n");
			}
		}

		if (days_since % 7 == 5)
		{
			for (int i = 1; i <= 29; i++)
			{
				if (i == 1)
					printf("                     %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 2)
					printf("\n");
			}
		}

		if (days_since % 7 == 6)
		{
			for (int i = 1; i <= 29; i++)
			{
				if (i == 1)
					printf("                         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 1)
					printf("\n");
			}
		}
	}

	//luty w roku zwykłym
	if (month == 2 && year_type == 1)
	{
		if (days_since % 7 == 0)
		{
			for (int i = 1; i <= 28; i++)
			{
				if (i == 1)
					printf(" %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 0)
					printf("\n");
			}
		}

		if (days_since % 7 == 1)
		{
			for (int i = 1; i <= 28; i++)
			{
				if (i == 1)
					printf("     %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 6)
					printf("\n");
			}
		}

		if (days_since % 7 == 2)
		{
			for (int i = 1; i <= 28; i++)
			{
				if (i == 1)
					printf("         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 5)
					printf("\n");
			}
		}

		if (days_since % 7 == 3)
		{
			for (int i = 1; i <= 28; i++)
			{
				if (i == 1)
					printf("             %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 4)
					printf("\n");
			}
		}

		if (days_since % 7 == 4)
		{
			for (int i = 1; i <= 28; i++)
			{
				if (i == 1)
					printf("                 %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 3)
					printf("\n");
			}
		}

		if (days_since % 7 == 5)
		{
			for (int i = 1; i <= 28; i++)
			{
				if (i == 1)
					printf("                     %d  ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 2)
					printf("\n");
			}
		}

		if (days_since % 7 == 6)
		{
			for (int i = 1; i <= 28; i++)
			{
				if (i == 1)
					printf("                         %d   ", i);
				if (i > 1 && i < 10)
					printf(" %d   ", i);
				if (i >= 10)
					printf("%d   ", i);
				if (i % 7 == 1)
					printf("\n");
			}
		}
	}

	return 0;
}


int main()
{
	int day;
	int month;
	int year;
	int days_since = 0; //dni od 01.01.1970 (bez ilości dni w roku podanym)
	int licz_zwykle = 0; //liczy ilość lat przestępnych
	int licz_przestepne = 0; //liczy ilość lat zwykłych
	int year_type = 0; //typ roku- przestępny (0) lub zwykły (1); przyda się w wyświetlaniu kalendarza na luty	
	int more_days = 0;


	printf("Podaj dzien, miesiac, rok \n");
	scanf_s("%d", &day);
	scanf_s("%d", &month);
	scanf_s("%d", &year);

	is_leap(year);
	int ilosc_latz = year - 1970;
	int ilosc_latp = year - 1970;

	day_of_week(day);

	count_days(day, month, ilosc_latz, ilosc_latz, days_since);

	printf("%d", more_days);

	calendar(year, month, days_since, year_type);




}


#ifndef BIBLIOTHEK_H_INCLUDED
#define BIBLIOTHEK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


// Funktionsprototyp
void gebe_text_aus(int zahl);

int is_leapyear(int jahr);

int get_days_for_months(int jahr, int monat);

int exists_date(int jahr, int monat, int tag);

int day_of_the_year(int tag, int monat, int jahr);

int get_weekday(int jahr, int monat, int tag);

int calender_week(int jahr, int monat, int tag);


#endif // BIBLIOTHEK_H_INCLUDED

#ifndef BIBLIOTHEK_H_INCLUDED
#define BIBLIOTHEK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct datum
{
    int jahr;
    int monat;
    int tag;
};


int is_leapyear(int jahr);

int get_days_for_months(struct datum);

int exists_date(struct datum);

int day_of_the_year(struct datum);

int get_weekday(struct datum);

int calender_week(struct datum);


#endif // BIBLIOTHEK_H_INCLUDED

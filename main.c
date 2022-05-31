
#include "bibliothek.h"



int main()
{

    struct datum datum1;
    struct datum datum2;
    char (*weekday[7])[14];
    weekday[0]="Sonntag";
    weekday[1]="Montag ";
    weekday[2]="Dienstag";
    weekday[3]="Mittwoch";
    weekday[4]="Donnerstag";
    weekday[5]="Freitag";
    weekday[6]="Samstag";


    printf("Dies ist ein Rechner für die Zahl des Tages!\n");
    do
    {
        printf("Bitte Jahr angeben:\n");
        scanf("%i",&datum1.jahr);
        printf("Bitte Monat angeben:\n");
        scanf("%i",&datum1.monat);
        printf("Bitte Tag angeben:\n");
        scanf("%i",&datum1.tag);
    }
    while (exists_date(datum1) == 0);

    printf("Das angegebene Tag ist der %i des jahres %i \n",day_of_the_year(datum1),datum1.jahr);
    printf("Wochentag %s \n", weekday[get_weekday(datum1)]);

    if(calender_week(datum1)<1)
    {
        datum2.jahr = datum1.jahr-1;
        datum2.monat = 12;
        datum2.tag =31;

        printf("Der Tag liegt in Kalenderwoche %i des Jahres %i\n",calender_week(datum2),datum2.jahr);
    }
    else if(calender_week(datum1)>55)
    {
        printf("Der Tag liegt in Kalenderwoche %i des Jahres %i\n",1,datum1.jahr+1);
    }
    else
    {
        printf("Der Tag liegt in Kalenderwoche %i des Jahres %i\n",calender_week(datum1),datum1.jahr);
    }

    return 0;

}


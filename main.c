
#include "bibliothek.h"



int main()
{

    int jahr, monat, tag;
    char (*weekday[7])[14];
    weekday[0]="Sonntag";
    weekday[1]="Montag ";
    weekday[2]="Dienstag";
    weekday[3]="Mittwoch";
    weekday[4]="Donnerstag";
    weekday[5]="Freitag";
    weekday[6]="Samstag";


    printf("Dies ist ein Rechner für die Zahl des Tages!\n");
    do{
    printf("Bitte Jahr angeben:\n");
    scanf("%i",&jahr);
    printf("Bitte Monat angeben:\n");
    scanf("%i",&monat);
    printf("Bitte Tag angeben:\n");
    scanf("%i",&tag);}
    while (exists_date(jahr, monat, tag) == 0);

    printf("Das angegebene Tag ist der %i des jahres %i \n",day_of_the_year(tag,monat,jahr),jahr);
    printf("Wochentag %s \n", weekday[get_weekday(jahr,monat,tag)]);

    if(calender_week(jahr,monat,tag)<1)
    {
    printf("Der Tag liegt in Kalenderwoche %i des Jahres %i\n",calender_week(jahr-1,12,31),jahr-1);
    }
    else if(calender_week(jahr,monat,tag)>55)
    {
    printf("Der Tag liegt in Kalenderwoche %i des Jahres %i\n",1,jahr+1);
    }
    else
    {
    printf("Der Tag liegt in Kalenderwoche %i des Jahres %i\n",calender_week(jahr,monat,tag),jahr);
    }

    return 0;

}


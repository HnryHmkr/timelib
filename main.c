#include <stdio.h>
#include <stdlib.h>


    /*
    Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
    ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
    */
    int is_leapyear(int jahr)
    {

    int rest, schalt;
    if (jahr < 1582)
    {
    schalt = -1;
    }
    else
    {
        rest = jahr % 4;
    if (rest == 0)
    {
        rest = jahr % 100;
        if (rest == 0)
        {
           rest = jahr % 400;
            if(rest != 0)
                {
                   schalt = 0;
                }
            else
            {
              schalt = 1;
            }
        }
        else
        {
            schalt = 1;
        }
    }
    else
    {
    schalt=0;
    }
    }

    return schalt;
    }

    /*
    Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
    Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
    */
    int get_days_for_months(int jahr, int monat)
    {
      int anzahl[13]= {31,28,31,30,31,30,31,31,30,31,30,31,29};
        if (is_leapyear(jahr) != -1 && monat < 13 && monat > 0)
        {
            if(monat == 2 && is_leapyear(jahr) == 1 )
            {
                return anzahl[12];
            }
            else
            {
                return anzahl[monat-1];
            }
        }
        else {return -1;}
    }
    /*
    Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
    wie alle Daten nach dem 31.12.2400.
    */

    int exists_date(int jahr, int monat, int tag)
    {
        if(tag > get_days_for_months(jahr, monat)||
           get_days_for_months(jahr, monat) == -1  )
        {
            return 0;
        }
        else if (jahr > 2400)
        {
            return 0;
        }
        else
        {
        return 1;
        }
    }


    /*
    Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
    und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
    Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
    */
    int day_of_the_year(int tag, int monat, int jahr)
    {
        int day_of_year = 0;
        for (int i = 1; i< monat; i++)
        {
            day_of_year += get_days_for_months(jahr, i);
        }
        day_of_year +=tag;

        return day_of_year;
    }

int main()
{
   int jahr, monat, tag;
    printf("Dies ist ein Rechner für die Zahl des Tages!\n");
    do{
    printf("Bitte Jahr angeben:\n");
    scanf("%i",&jahr);
    printf("Bitte Monat angeben:\n");
    scanf("%i",&monat);
    printf("Bitte Tag angeben:\n");
    scanf("%i",&tag);}
    while (exists_date(jahr, monat, tag) == 0);

    printf("Das angegebene Tag ist der %i des jahres %i",day_of_the_year(tag,monat,jahr),jahr);


    return 0;

}


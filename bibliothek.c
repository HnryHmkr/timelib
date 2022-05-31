#include <stdio.h>
#include "bibliothek.h"

void gebe_text_aus(int zahl)
{
    printf("Hello world!\n");
}

/*
   Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
   ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
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
Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden ber�cksichtigt.
*/
int get_days_for_months(struct datum date)
{
    int anzahl[13]= {31,28,31,30,31,30,31,31,30,31,30,31,29};
    if (is_leapyear(date.jahr) != -1 && date.monat < 13 && date.monat > 0)
    {
        if(date.monat == 2 && is_leapyear(date.jahr) == 1 )
        {
            return anzahl[12];
        }
        else
        {
            return anzahl[date.monat-1];
        }
    }
    else
    {
        return -1;
    }
}


/*
Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist. Daten vor dem 1.1.1582 sind ung�ltig, genauso
wie alle Daten nach dem 31.12.2400.
*/

int exists_date(struct datum date)
{
    if(date.tag > get_days_for_months(date)||
            get_days_for_months(date) == -1  )
    {
        return 0;
    }
    else if (date.jahr > 2400)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*
Die Funktion berechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung ber�cksichtigt. Ist das �bergebene Datum ung�ltig, betr�gt der R�ckgabewert -1.
*/
int day_of_the_year(struct datum date)
{
    int day_of_year = 0;
    struct datum dates;
    dates=date;
    for (int i = 1; i< date.monat; i++)
    {
        dates.monat=i;
        day_of_year += get_days_for_months(dates);
    }
    day_of_year +=date.tag;

    return day_of_year;
}


/*
get_weekday berechnet mit dem �bergabenwerten des Jahres, Monats und Tages,
wobei 0 f�r Sonntag, 1 f�r Montag usw. zur�ckgegeben wird.
*/
int get_weekday(struct datum date)
{
    int d, m, y, c, w=0;
    double t = 0;

    if(exists_date(date) == 1)
    {
        d= date.tag;
        m= date.monat-2;
        y= date.jahr %100;
        if (date.monat == 1 || date.monat == 2)
        {
            c=(date.jahr-1)/100;
            m=date.monat+10;
            y-=1;
        }
        else
        {
            c=date.jahr/100;
        }
        t= d+(2.6*m-0.2)+y+(y/4)+(c/4)-2*c;
        w=t;
        w=w%7;
        return w;
    }
}


/*
calender_week gibt Dank der �bergabewerten Jahr, Monat, Tag die Kalenderwoche zur�ck.
wenn das Datum einer Kalenderwoche zugeh�rt, die noch zum letzten jahr geh�rt wird 0 zur�ckgegeben.
*/
int calender_week(struct datum date)
{
    int week,t=0;
    struct datum date2;
    date2.jahr =date.jahr;
    date2.monat =1;
    date2.tag =1;

    if (get_weekday(date2)<1)
    {
        t=t+1;
    }
    else if(get_weekday(date2) <4)
    {
        t=t-get_weekday(date2);
    }
    else
    {
        t+=get_weekday(date2);
    }


    t+= day_of_the_year(date);
    if(t>6)
    {
        week= t/7;
    }
    if (date.monat == 1 && date.tag < 4)
    {

        if(get_weekday(date)>3||get_weekday(date)==0)
        {
            week=0;
        }
    }

    if(date.monat==12 && date.tag ==30 || date.tag==31)
    {
        date2.monat=12;
        date2.tag=31;

        if(get_weekday(date2)<3)
        {
            week=100;
        }
    }

    return week;
}

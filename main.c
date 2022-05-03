#include <stdio.h>
#include <stdlib.h>

int main()
{
   int jahr, monat, tag, rest, schalt;
    printf("Dies ist ein Rechner für die Zahl des Tages!\n");
    printf("Bitte Jahr angeben:\n");
    scanf("%i",&jahr);


    int anzahl[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
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

    if (schalt == 1)
    {
        anzahl[1] =29;
    }

    do{
    printf("Bitte Monat angeben:\n");
    scanf("%i",&monat);}
    while(monat<=0 || monat>12 );

    do{
    printf("Bitte Tag angeben:\n");
    scanf("%i",&tag);}
    while(tag> anzahl[monat-1] || tag<=0);

    int ergebnis = 0;

    for (int i = 0; i< monat-1; i++)
    {
        ergebnis+=anzahl[i];
    }
    ergebnis+=tag;

    printf("\n Der angegebene Tag ist der %i Tag des Jahres %i\n", ergebnis, jahr);


    return 0;
}


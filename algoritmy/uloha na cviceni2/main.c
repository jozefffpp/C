#include <stdio.h>
#include <stdlib.h>
/*Úloha
Program preèíta zo štandardného vstupu text a na štandardnı vıstup vypíše pre kadı riadok vstupného súboru èíslo
riadku a poèet slov, ktoré sa v òom nachádzajú. Slová sú oddelené medzerou alebo novım riadkom. Úlohu riešte bez
pouitia reazcov (pola znakov).

Ukáka vstupu:
Stoji, stoji mohyla.
Na mohyle zla chvila,
na mohyle trnie, chrastie
a v tom trni, chrasti rastie,
rastie, kvety rozvija
jedna zlta lalija.

Ukáka vıstupu:
riadok 1: pocet slov: 3
riadok 2: pocet slov: 4
riadok 3: pocet slov: 4
riadok 4: pocet slov: 6
riadok 5: pocet slov: 3
riadok 6: pocet slov: 3*/


int main()
{
    int riadok=1, slova=0;
    char c='\n', cpred;
    do{
        cpred = c;
        c = getchar();
        if((c == ' ' && cpred != ' ' && cpred != '\n') ||
           (c == '\n' && cpred != '\n' && cpred != ' ')){
            slova++;
           }
        if(c == '\n'){
            printf("%d. riadok\tslov: %d\n", riadok, slova);
            riadok++;
            slova = 0;
        }
    }while(c != '*');

    return 0;
}

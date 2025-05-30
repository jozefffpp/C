#include <stdio.h>
#include <stdlib.h>
/*�loha
Program pre��ta zo �tandardn�ho vstupu text a na �tandardn� v�stup vyp�e pre ka�d� riadok vstupn�ho s�boru ��slo
riadku a po�et slov, ktor� sa v �om nach�dzaj�. Slov� s� oddelen� medzerou alebo nov�m riadkom. �lohu rie�te bez
pou�itia re�azcov (pola znakov).

Uk�ka vstupu:
Stoji, stoji mohyla.
Na mohyle zla chvila,
na mohyle trnie, chrastie
a v tom trni, chrasti rastie,
rastie, kvety rozvija
jedna zlta lalija.

Uk�ka v�stupu:
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

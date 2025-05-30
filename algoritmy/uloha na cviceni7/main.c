#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Úloha 5
    Program bude èíta riadky zo štandardného vstupu a kım nenaèíta riadok so slovom
    “koniec“. Pre kadı riadok program vypíše, èi naèítanı reazec je palindróm
    (slovo, veta, èíslo, všeobecne akáko¾vek postupnos symbolov, ktorá
    má tú vlastnos, e ju mono èíta v ¾ubovo¾nom smere, èie sprava do¾ava alebo
    z¾ava doprava a má vdy rovnakı
    vıznam).

    Ukáka vstupu:
    Jelenovi pivo nelej
    Ak taram ako kamaratka
    Kuna nanuk
    Toto nie je palindrom
    koniec


    Ukáka vıstupu:
    Jelenovi pivo nelej ANO
    Ak taram ako kamaratka ANO
    Kuna nanuk ANO
    Toto nie je palindrom NIE
*/


/*
    ciklus po \n
    vsetko na tolower
    unget posledny znak
    kontrola znaku 1-posledny, 2-n-2

    koniec;

    strcmp- porovnanie retazcov= vrati 0/ cislo
    strstrpodretazec v retazci
    porovnavanie znakov
    */

int main()
{
    int i, len, j;
    char riadok[50], obratene[50];

    printf("zadaj text: \n");

    while(strcmp(riadok, "koniec")){

            //nacitanie riadku
            fgets(riadok, 50, stdin);

            //ak string nie je "koniec" spusti program
            if(strcmp(riadok, "koniec")){
                len = strlen(riadok);

                printf("%s", riadok);//pri vstupe cez stdin odstranit, cez konzolu necha

                // zbavenie stringu bielych miest
                for( i = 0, j = 0; i < len; i++){
                    riadok[i-j] = riadok[i];
                    if(riadok[i] == ' '){
                        j++;
                    }
                    if(riadok[i] == '\n'){
                        riadok[i-j] = '\0';
                    }
                }

                //dlzka stringu
                len = strlen(riadok);

                //na male pismo a obratenie do obrateneho pola
                for(i=0; i<=len; i++){
                    riadok[len-i-1] = tolower(riadok[len-i-1]);
                    obratene[i] = riadok[len-i-1];
                }

                //porovnanie, ci je alebo nie je rovnaky vstupny a obrateny string
                if(!strcmp(riadok, obratene)){
                    printf(" ANO \n");
                }
                else{
                    printf(" NIE \n");
                }
            }
            //koniec pri nacitani "koniec"
            else{
                break;
            }
    }


    return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    ATOM *zac, *kur;

    zac = NULL; //vytvori prazdny zoznam

    pridaj_na_zaciatok(&zac, 123); //123
    pridaj_na_zaciatok(&zac, 456); //456 123
    pridaj_na_zaciatok(&zac, 789); //789 456 123
    kur = najdi(zac, 456); //789 -> 456 123
    pridaj_za_kurzor(kur, 256); //789 456 256 123

    //vypisanie zoznamu
    kur = zac;
    while(kur != NULL) {
        printf("%d\n", kur->cislo);
        kur = kur->dalsi;
    }

    //zrusenie zoznamu
    while(zac->dalsi != NULL) {
        odober_za_kurzorom(zac);
    }
    free((void*) zac);

    return 0;
}
//------------------------------------------
//pridaj na zaciatok
void pridaj_na_zaciatok(ATOM **zac, int c)
{
    ATOM *pom;
    pom = (ATOM*) malloc(sizeof(ATOM));
    pom->cislo = c;
    pom->dalsi = *zac;
    *zac = pom;
}
//------------------------------------------
//pridaj za kurzor
void pridaj_za_kurzor(ATOM *kur, int c)
{
    ATOM *pom;
    pom = (ATOM*) malloc(sizeof(ATOM));
    pom->cislo = c;
    pom->dalsi = kur->dalsi;
    kur->dalsi = pom;
}
//------------------------------------------
//odober za kurzorom
int odober_za_kurzorom(ATOM *kur)
{
    int c;
    if(kur != NULL) {
        ATOM *pom;
        pom = kur->dalsi;
        kur->dalsi = pom->dalsi;
        c = pom->cislo;
        free((void*) pom);
    } else { //prvok neexistuje
        c = -1;
    }
    return(c);
}
//------------------------------------------
//najdi prvok
ATOM* najdi(ATOM *zac, int c)
{
    ATOM *pom;
    pom = zac;
    while(pom != NULL) {
        if(c == pom->cislo) { //nasiel
           return(pom);
        } else { //nenasiel - ideme dalej
            pom = pom->dalsi; //posun na dalsi prvok
        }
    }
    return(NULL); //ak sa nenasiel
}

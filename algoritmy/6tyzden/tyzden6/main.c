#include <stdio.h>
#include <stdlib.h>
#include "komplex.h"



int main()
{
    KOMPEX a, b;
    printf("Zadaj komplexne cislo: ");
    scanf("%f %fi", &a.real, &a.imag);
    printf("Zadaj komplexne cislo: ");
    scanf("%f %fi", &b.real, &b.imag);

    KOMPEX vysledok;
    vysledok = scitaj(a,b);
    printf("vysledok je %f + i\n", vysledok.real, vysledok.imag);

    vysledok = odcitaj(a,b);
    printf("vysledok je %f + %fi\n", vysledok.real, vysledok.imag);



    return 0;
}


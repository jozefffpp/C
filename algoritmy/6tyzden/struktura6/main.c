/* Programovanie v C - Miroslav Melichercik */
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#ifdef __LINUX__
	#include <stdio_ext.h>
#endif

int main()
{
    CLOVEK p[MAX];
    int pocet=0;
    while(1) {
        menu(); //vypis menu
#ifdef __LINUX__
        __fpurge(stdin); //zmaz vstupny buffer
#else
        fflush(stdin); //zmaz vstupny buffer
#endif
        switch(getchar()) {
            case 'p' : pridaj(p, &pocet); break;
            case 'v' : vypis(p, pocet); break;
            case 'u' : uloz(p, pocet); break;
            case 'n' : nacitaj(p, &pocet); break;
            case 'k' : exit(0); break;
            default : printf("Zly znak!\n");
        }
    }
    return 0;
}
//--------------------------------------
void menu()
{
    printf( "\nPolozky menu:\n"
            "p - pridaj\n"
            "v - vypis\n"
            "u - uloz\n"
            "k - koniec\n"
            "n - nacitaj zo suboru\n"
            "\nZadaj volbu: ");
}
//--------------------------------------
void pridaj(CLOVEK p[MAX], int *pocet)
{
    printf("Zadaj meno: ");
    scanf("%s", p[*pocet].meno);
    printf("Zadaj priezv: ");
    scanf("%s", p[*pocet].priezv);
    printf("Zadaj vek: ");
    scanf("%d", &p[*pocet].vek);

    (*pocet)++;
//  system("cls");
    system("clear");

}
//--------------------------------------
void vypis(CLOVEK p[MAX], int pocet)
{
    int i;
    for(i=0; i<pocet; i++) {
        putchar('\n');
        printf("Meno:\t%s\n", p[i].meno);
        printf("Priezv:\t%s\n", p[i].priezv);
        printf("Vek:\t%d\n", p[i].vek);
    }
}
//--------------------------------------
void uloz(CLOVEK p[MAX], int pocet)
{
//format CSV (kazdy riadok je jeden zaznam s polozkami oddelenymi ciarkou)
//priklad riadku "Jozko,Mrkvicka,25\n"
    int i;
    FILE *f;
    f = fopen("data.txt", "w");
    for(i=0; i<pocet; i++) {
        fprintf(f,"%s,%s,%d\n", p[i].meno, p[i].priezv, p[i].vek);
    }
    fclose(f);
}
//--------------------------------------
void nacitaj(CLOVEK p[MAX], int *pocet)
{
//format CSV (kazdy riadok je jeden zaznam s polozkami oddelenymi ciarkou)
//priklad riadku "Jozko,Mrkvicka,25\n"
    int i;
    FILE *f;
    //*pocet =0; pre zmazanie pola
    f = fopen("data.txt", "r");
    while( fscanf(f,"%[^,],%[^,],%d\n", p[*pocet].meno, p[*pocet].priezv, &p[*pocet].vek) != EOF){
    (*pocet)++;

    }
    fclose(f);
}
//--------------------------------------


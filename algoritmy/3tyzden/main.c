#include <stdio.h>
#include <stdlib.h>

//int main()
//{
    //prepis
        /*Program otvorн textovэ sъbor s nбzvom vstup.txt, z ktorйho bude
        нtaќ postupne v cykle vљetky znaky a vypнљe ich na љtandardnэ vэstup.
        Vstupnэ sъbor je potrebnй uloћiќ do adresбra projektu. Upravte program
        tak, aby bol text na vэstupe napнsanэ len veѕkэmi pнsmenami (malй
        pнsmenб zmenн na veѕkй, ostatnй znaky vypнљe nezmenenй). Okrem toho
         zistite a vypнљte sprбvu o tom, koѕko veѕkэch pнsmen, malэch pнsmen a
         инslic sa nachбdzalo v pфvodnom texte.
          FILE *f;
        int c;
        f = fopen("vstup.txt", "r");
        while((c = getc(f)) != EOF) {
            putchar(c);
        }
        fclose(f);*/

            FILE *f;
            int c, velke=0, male=0, cislice=0;
            f = fopen("vstup.txt", "r");
            while((c = getc(f)) != EOF) {
                if(c >= 'A' && c<= 'Z'){
                    velke++;
                }
                else if(c >= '0' && c <= '9'){
                    cislice++;
                }
                else if(c >= 'a' && c <= 'z'){
                        male++;
                        c -= 'a' - 'A';
                    }
                    putchar(c);
            }
            printf("\nvelke\t%d\nmale\t%d\ncislice\t%d\n", velke, male, cislice);
            fclose(f);


    //postupnost
   /* Program načíta zo štandardného vstupu 3 celé čísla a0, d, n,
   ktoré predstavujú nultý člen aritmetickej postupnosti, diferenciu a
    počet členov postupnosti, ktoré sa majú vypočítať a vypísať. Upravte
     program tak, že vstupné hodnoty načíta zo súboru, ktorý bude vyzerať
     nasledovne: 34@@@@11 pričom prvé číslo (34) predstavuje hodnotu a0,
     počet zavináčov (4) predstavuje hodnotu n a posledné číslo (11)
     predstavuje hodnotu d. Program musí fungovať aj pre iný vstupný súbor
     zadaný v uvedenom tvare.

    int a0, d, n;
    printf("Zadaj a0, d, n\n");
    scanf("%d %d %d", &a0, &d, &n);
    printf("a0=%d d=%d n=%d\n", a0, d, n);
    int an=a0, i;
    for(i=1; i<=n; i++) {
        an += d;
        printf("a%d = %d\n", i, an);
    }
    */


            int a0, d, n=0;
            FILE *f;
            char c;
            f = fopen("postupnost.txt", "r");
            fscanf(f, "%d", &a0);
            while((c = getc(f)) <'0' || c >'9') {
                n++;
            }
            ungetc(c, f);
            fscanf(f, "%d", &d);
            printf("a0 = %d\td = %d\tn = %d\n", a0, d, n);
            int an=a0, i;
            for(i=1; i<=n; i++) {
                an += d;
                printf("a%d = %d\n", i, an);
            }
    fclose(f);
    return 0;
}








/*Program načíta pomocou zadefinovanej funkcie nacitaj zo zadaného súboru
 maticu reálnych čísel o veľkosti 3x3 a následne ju vypíše na obrazovku. V
 programe zadefinujte novú funkciu zapis, ktorá do súboru s názvom vystup.txt
 zapíše načítanú maticu prenásobenú konštantou 2 (každý prvok matice vynásobí
číslom 2). Nezabudnite vytvoriť funkčný prototyp pre novú funkciu, inak by
program nemusel pracovať správne. Vstupný súbor bude zadaný na nasledujúcom
tvare:

1. 2. 3.
4. 5. 6.
7. 8. 9.*/


#define MAX 3

//funkcny prototyp
int nacitaj(float matica[MAX][MAX], char *nazov);
int zapis(float matica[MAX][MAX]);

//funkcia main
int main()
{
    float mat[MAX][MAX];
    char nazov_suboru[20];

    printf("Zadaj nazov suboru pre nacitanie matice: ");
    scanf("%s", nazov_suboru);

    //zavolanie funkcie
    nacitaj(mat, nazov_suboru);


    //vypis matice
    int i, j;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            printf("%.3f ",  mat[i][j]);
        }
        putchar('\n');
    }
    printf("\n");

    zapis(mat);

     for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            printf("%.3f ",  mat[i][j]);
        }
        putchar('\n');
        }

    return 0;
}


int zapis(float matica[MAX][MAX])
{

FILE *fw;
fw = fopen("vystup.txt", "w");
int i, j;
for(i=0; i<MAX; i++) {
    for(j=0; j<MAX; j++) {
        matica[i][j] = matica[i][j] *2;
        fprintf(fw, "%.1f   ", matica[i][j]);
    }
    fprintf(fw, "\n");
}
fclose(fw);

return(0);
}


//funkcia nacitaj - nacita maticu zo suboru
int nacitaj(float matica[MAX][MAX], char *nazov)
{
    //otvorenie suboru
    FILE *f;
    if((f = fopen(nazov, "r")) == NULL) {
        fprintf(stderr, "Subor sa nepodarilo otvorit!\n");
        exit(1);
    }
    //nacitanie matice
    int i, j;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            fscanf(f, "%f", &matica[i][j]);
        }
    }
    //zatvorenie suboru
    fclose(f);
    return(0);
}

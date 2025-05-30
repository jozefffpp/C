/* Programovanie v C - Miroslav Melichercik

Program na��ta do premennej cel� ��slo a potom ho z nej vyp�e. N�sledne urob�
to ist� pomocou ukazovate�a (pointra) ukazuj�ceho na pou�it� premenn�.
 Upravte program tak, aby vyp�sal adresu, na ktorej je ulo�en� premenn�
 a a premenn� b. Na z�ver vyp�te hodnotu, ktor� sa nach�dza v premennej
  b. Ak�ho typu je t�to hodnota? Pok�ste sa ur�i� (bez pou�itia po��ta�a)
  , �o bude v�stupom nasleduj�ceho pr�kazu:
printf("%d", *(&a));
Svoju odpove� overte v programe.

    pointer*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *b;
    //pomocou klasickej premennej a
    printf("Zadaj cislo: ");
    scanf("%d", &a);
    printf("%d\n", a);
    //pomocou pointera b
    b = &a;
    printf("Zadaj cislo: ");
    scanf("%d", b);
    printf("b %d\n", *b);
    printf("a %d\n", a);

    printf("adresa a: %p \n adresa b: %p\n", &a, &b);
    printf("obsah b: %p\n", b);

    printf("%d", *(&a));

    return 0;
}


/* Programovanie v C - Miroslav Melichercik
Upravte program z �lohy Matica z 3. t��d�a tak, �e rozmery mat�c nebud�
zadan� fixne pomocou definovan�ho makra, ale bud� na��tan� z textov�ho
 s�boru. Tento bude na prvom riadku obsahova� 2 cel� kladn� ��sla oddelen�
 medzerou, ktor� bud� predstavova� po�et riadkov a st�pcov matice a n�sledne
  na �al��ch riadkoch bude nasledova� samotn� matica, napr�klad:

3 4
1 2 3 4
5 6 7 8
9 10 11 12

Maticu na��tajte do dvojrozmern�ho po�a, ktor� alokujete dynamicky pomocou
funkcie malloc.

matica */


#include <stdio.h>
#include <stdlib.h>


//funkcny prototyp
float** nacitaj(char *nazov, int *rr, int *ss);

//funkcia main
int main()
{
    float** mat;
    char nazov_suboru[20];
    int r,s; //pocet riadkov a stlpcov

    printf("Zadaj nazov suboru pre nacitanie matice: ");
    scanf("%s", nazov_suboru);

    //zavolanie funkcie
    mat = nacitaj(nazov_suboru, &r, &s);

    //vypis matice
    int i, j;
    for(i=0; i<r; i++) {
        for(j=0; j<s; j++) {
            printf("%.3f ",  mat[i][j]);
        }
        putchar('\n');
    }

    //odalokovanie pamete
    for(i=0; i<r; i++){
        free((void*) mat[i]);
    }
    free((void*) mat[i]);
    return 0;
}

//funkcia nacitaj - nacita maticu zo suboru
float** nacitaj(char *nazov, int *rr, int *ss)
{
    int i, j;
    //otvorenie suboru
    FILE *f;
    if((f = fopen(nazov, "r")) == NULL) {
        fprintf(stderr, "Subor sa nepodarilo otvorit!\n");
        exit(1);
    }
    //nacitanie rozmerov matice
    int rrr, sss;
    fscanf(f, "%d %d", &rrr, &sss);

    //alokacia pamete dinamicky
    float** pom;
    pom = (float**)malloc(sizeof(float*) * rrr);
    for(i=0; i<rrr; i++){
        pom[i] = (float*) malloc(sizeof(float) * sss);
    }

    //nacitanie matice
    for(i=0; i<rrr; i++) {
        for(j=0; j<sss; j++) {
            fscanf(f, "%f", &pom[i][j]);
        }
    }
    //zatvorenie suboru
    fclose(f);
    //vratenie hodnot
    *rr = rrr; //cez parameter volany odkazom
    *ss = sss; // -||-
    return(pom); //cez navratovu hodnotu fc
}



#include <stdio.h>
#include <stdlib.h>

int obsad(char[], int s, int p, int m, int miesto);

int main()
{

    int s, p, m; // pocet stoliciek, psov, maciek
    printf("Zadaj pocet stoliciek: ");
    scanf("%d", &s);

    printf("Zadaj pocet psov: ");
    scanf("%d", &p);

    printf("Zadaj pocet maciek: ");
    scanf("%d", &m);

    char c[s]; //cakaren
    obsad(c, s, p, m, 0);

    return 0;
}

int obsad(char c[], int s, int p, int m, int miesto){

    if(miesto < s){ //mozom obsadzovat stolicku
        if(p > 0 && (miesto == 0 || c[miesto-1] != 'M')){ //skusim posadit psa
            c[miesto] = 'P';    //posadim psa
            obsad(c, s, p-1, m, miesto +1);
        }
        if(m > 0 && (miesto == 0 || c[miesto-1] != 'P')){ //skusim posadit macku
            c[miesto] = 'M';    //posadim macku
            obsad(c, s, p, m-1, miesto +1);
        }
        c[miesto] = '.';
        obsad(c, s, p, m, miesto +1);
    }else {// pouzite vsetky stolicky
        if(p == 0 && m == 0){ //seci sedia
            int i;
            for(i = 0; i<s; i++){
                putchar(c[i]);

            }
            putchar('\n');
        }
    }
return (0);
}

//test po kapitolu 13 - hlavickove subory, oddeleny preklad v heroltovi(kniha)
















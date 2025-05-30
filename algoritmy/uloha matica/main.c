/*
Upravte program z úlohy Matica z 3. tıdòa tak, e rozmery matíc nebudú
zadané fixne pomocou definovaného makra, ale budú naèítané z textového
 súboru. Tento bude na prvom riadku obsahova 2 celé kladné èísla oddelené
 medzerou, ktoré budú predstavova poèet riadkov a ståpcov matice a následne
  na ïalších riadkoch bude nasledova samotná matica, napríklad:

3 4
1 2 3 4
5 6 7 8
9 10 11 12

Maticu naèítajte do dvojrozmerného po¾a, ktoré alokujete dynamicky pomocou
funkcie malloc.
*/


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














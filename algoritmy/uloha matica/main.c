/*
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














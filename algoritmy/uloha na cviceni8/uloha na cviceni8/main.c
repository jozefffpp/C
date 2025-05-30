#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    int n, d;   //pocet schodov a vyska kroku
    int *h, *s, *p; //vyska schodov, prefixsucet, pocet sposobov

    nacitaj_vstup(&n, &d, &h);

    s = (int*) malloc(sizeof(int) * (n+1));
    p = (int*) malloc(sizeof(int) * (n+1));
    prefixsucet(h, s, n);
    int v = pocet_sposobov(h, s, p, n, d);
    printf("%d\n", v);
    zrus_alokacie(h, s, p);

    return 0;
}
//---------------------------------------------------------
int nacitaj_vstup(int *p_n, int *p_d, int **p_h)
{
    int pom_n, pom_d;
    scanf("%d %d", &pom_n, &pom_d);
    int *pom_h = (int*) malloc(sizeof(int) * (pom_n+1));  //0 1..n
    int i;
    for(i=1; i<=pom_n; i++) {   //nacitame pole
        scanf("%d", &pom_h[i]);
    }
    //priradenie hodnot do parametrom = vracanie hodnot
    *p_n = pom_n;
    *p_d = pom_d;
    *p_h = pom_h;
    return(0);  //funkcia skoncila bez chyby
}
//---------------------------------------------------------
void prefixsucet(int *h, int *s, int n)
{
    s[0] = 0;
    int i;
    for(i=0; i<=n; i++) {
        s[i] = h[i] + s[i-1];
    }
}
//---------------------------------------------------------
int pocet_sposobov(int *h, int *s, int *p, int n, int d)
{
    p[0] = 1;
    int i, j;
    for(i=1; i<=n; i++) {   //ide po schodoch 1..n
        p[i] = 0;
        j = i-1;    //zacni skusat od predosleho schodu smerom dole
        while((j>=0) && (s[i]-s[j] <= d)) { //ak na schod dociahnes
            p[i] += p[j];   //zapocitaj pocet sposobov
            j--;
        }
    }
    return(p[n]);   //pocet sposobov pre n-ty (posledny) schod
}
//---------------------------------------------------------
void zrus_alokacie(int *h, int *s, int *p)
{
    free((void*) h);
    free((void*) s);
    free((void*) p);
}
//---------------------------------------------------------

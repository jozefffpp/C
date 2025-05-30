#include <stdio.h>
#include <stdlib.h>
/*
typedef enum{
    ucitel,
    vychovavatel,
    veduci,
    technik
}ZARADENIE

typedef struct {
    char meno[20];
    int rok_narodenia;
    int hruba_mzda;
    ZARADENIE* zaradenie;
} ZAMESTNANEC
*/

/*
//#define n = (...)

int najdiMax(int *pole){
    int pom, index;
    pom = pole[0];
    index = 0;

    for(int i = 0; i<pole; i++){
        if(pom < pole[i]){
            pom = pole[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int *pole;

    pole = (int*) malloc(sizeof(int) * n);
    najdiMax(pole);

    printf("%d\n", index);
    return 0;
}*/


int ntyclen(int n){
    int a0 = 1;
    int a1 = 1;
    int an;

    int clenN;
    for(int i = 0; i<n; i++){
        an = 2*n*ntyclen(n-1);
    }


    return clenN;
}








int main()
{
    int *pole;

    pole = (int*) malloc(sizeof(int) * n);
    najdiMax(pole);

    printf("%d\n", index);
    return 0;
}
























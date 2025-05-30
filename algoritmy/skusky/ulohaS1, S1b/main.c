#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    int len, N, pocet = 0, NC;
    char retazec[101];

    scanf("%d %d", &N, &NC);     // dlzka hladanych retazcov a pocet roznych znakov
                                //pouzitych v retazci
    scanf("%s", retazec);      //nacitanie retazca
    len = strlen(retazec);    //dlzka retazca

    pocet = najdi(len, retazec, (len-N+1), N);
    printf("pocet podretazcov: %d\n", pocet);

    return 0;
}











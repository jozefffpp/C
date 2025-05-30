#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(){
    int N, NC, pocet;    // deklaracia dlzky podretazca, pocet pismen,
                        //vysledny pocet opakujucich sa
    char retazec[101];

    scanf("%d %d", &N, &NC);  // dlzka hladanych retazcov a pocet
                            //roznych znakov
                            //pouzitych v retazci
    scanf("%s", retazec);  //nacitanie retazca

    pocet = spocitaj(retazec, N); //volanie funkcie na zistenie poctu
                                 //opakujucich sa podretazcov
    printf("%d\n", pocet);      // vytlacenie vysledku na stdout

    return 0;                 //navratova hodnota funkcie
}

//-------------------------------------------------------------------
int spocitaj(char retazec[], int N){

    int opakujuce = 0, len, counti;    //deklaracia premennych

    len = strlen(retazec);           //zistenie dlzky retazca
    counti = (len-N+1);             // zistenie pokadiel prechadzam polom

    char podret[len-N+1][N+1];    //deklaracia hladaneho retazca
    char *ptr;

    for(int i=0; i<counti; i++){

        strncpy(podret[i], &retazec[i], N);      //najdi podretazec ak existuje kopia
        ptr = strstr(&retazec[i+1], podret[i]); //najdi dalsi vyskyt podreatzca
        while(ptr){                            //ak ich je viac tak znova

            ptr = strstr(ptr+1, podret[i]);
            opakujuce++;                     // pripocitaj k vysledku
        }
    }
    return opakujuce;
}











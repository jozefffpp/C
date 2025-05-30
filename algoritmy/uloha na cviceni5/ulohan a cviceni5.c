#include <stdio.h>
#include <stdlib.h>

int obsad(char[], int s, int p, int m, int miesto)

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
        if(p > 0 && (miesto == 0 || c[miesto-1] != 'M'){ //skusim posadit psa
            c[miesto] = 'P';    //posadim psa
            obsad(c, s, p-1, m, miesto +1);
        }
        if(m > 0 && (miesto == 0 || c[miesto-1] != 'P'){ //skusim posadit macku
            c[miesto] = 'M';    //posadim macku
            obsad(c, s, p, m-1, miesto +1);
        }
        c[miesto] == ".";
        obsad(c, s, p, m, miesto +1);
    }else {// pouzite vsetky stolicky
        if(p == 0 && m == 0){ //seci sedia
            int i;
            for(i = 0; i<s; i++){
                putchar(c[i]);
            }
            putchar("\n");
        }
    }
returt 0;
}

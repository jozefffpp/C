#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    int n, nc, opakujuce;
    char s[MAX];
    scanf("%d %d", &n, &nc);
    scanf("%s", s);

    opakujuce = podretazce(n, nc, s);

    printf("%d", opakujuce);

    return 0;
}

//--------------------------------------
int podretazce(int n, int nc, char s[]){

    int opakujuce, i, j, spolu, dlzka;
    char pod1[n+1], pod2[n+1];

    opakujuce = 0;
    spolu = 0;
    dlzka = strlen(s);

    for(i = 0; i <= dlzka-n; i++) {
        spolu = 0;
        strncpy(pod1, &s[i], n);
        for(j = i+1; j <= dlzka-n; j++) {
            strncpy(pod2, &s[j], n);
        if(strcmp(pod1, pod2) == 0) {
            opakujuce++;
            }
        }
    }
    return opakujuce;
}

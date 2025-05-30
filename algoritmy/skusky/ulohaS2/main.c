#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//--------------------------------------------------------------------------------------
int main()
{
    int l, c, w, dlzka, r, m=0;

    //nacitanie poctov
    scanf("%d %d %d", &l, &c, &w);
    char smerovka[l][c], slova[w][ (l>c)? l:c ];

    //nacitanie osemsmerovky
    getchar();
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            scanf("%c", &smerovka[i][j]);
        }
        getchar();
    }

    //nacitanie slov na hladanie
    for(int i=0; i<w; i++){
        scanf("%s", slova[i]);
    }

    //pre kazde slovo idem cez celu osemsmerovku
    for(int i=0; i<w; i++){
        dlzka = strlen(slova[i]);

        //prechadzanie osemsmerovky
        for(int j=0; j<l; j++){
            for(int k=0; k<c; k++){

                //hladanie prveho pismena zo slova
                if(smerovka[j][k] == slova[i][0]){
                    m =0;

                    //hladanie v A smere
                    if(c >= (k + dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j][k+r] == slova[i][r]){
                                m++;
                            }
                            else{
                                m =0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d A\n", j, k);
                        }
                        m =0;
                    }

                     //hladanie v B smere
                    if(l >= (j+dlzka) && c >= (k+dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j+r][k+r] == slova[i][r]){
                                m++;
                            }
                            else{
                                m = 0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d B\n", j, k);
                        }
                        m =0;
                    }

                    //hladanie v C smere
                    if(l >= (j+dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j+r][k] == slova[i][r]){
                                m++;
                            }
                            else{
                                m = 0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d C\n", j, k);
                        }
                        m =0;
                    }

                    //hladanie v D smere
                    if(l >= (j+dlzka) && -1 <= (k-dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j+r][k-r] == slova[i][r]){
                                m++;
                            }
                            else{
                                m = 0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d D\n", j, k);
                        }
                        m =0;
                    }

                    //hladanie v E smere
                    if(-1 <= (k-dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j][k-r] == slova[i][r]){
                             m++;
                            }
                            else{
                                m = 0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d E\n", j, k);
                        }
                        m =0;
                    }

                    //hladanie v F smere
                    if(-1 <= (j-dlzka) && -1 <= (k-dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j-r][k-r] == slova[i][r]){
                               m++;
                            }
                            else{
                                m = 0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d F\n", j, k);
                        }
                        m =0;
                    }

                    //hladanie v G smere
                    if(-1 <= (j-dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j-r][k] == slova[i][r]){
                               m++;
                            }
                            else{
                                m = 0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d G\n", j, k);
                        }
                        m =0;
                    }

                    //hladanie v H smere
                    if(-1 <= (j-dlzka) && c >= (k+dlzka)){
                        for(r=0; r<dlzka; r++){
                            if(smerovka[j-r][k+r] == slova[i][r]){
                               m++;
                            }
                            else{
                                m = 0;
                            }
                        }
                        if(m == dlzka){
                            printf("%d %d H\n", j, k);
                        }
                        m =0;
                    }
                }
            }
        }
    }
    return 0;
}

void ahoj(){

}


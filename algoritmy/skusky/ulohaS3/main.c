#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(){

    int r, s, x, y;
    x=y=0;

    //nacitanie rozmerov
    scanf("%d %d", &r, &s);
    char plan[r][s];

    //nacitanie labyrintu
    getchar();
    for(int i=0; i<r; i++){
        for(int j=0; j<s; j++){
            scanf("%c", &plan[i][j]);
        }
        getchar();
    }

    voda(r, s, plan, x, y);

    return 0;
}
//-------------------------------------------------------------------------------
//zistenie, ci sa da prist na nadvorie
int nadvorie(int r, int s, char plan[r][s], int x, int y, int m){

    // pri vstupe urcim smer mojich krokov
    if(m == 0){
        if(plan[y+1][x] == 'V'){
            plan[y-1][x] = '^';
            y--;
        }
        if(plan[y-1][x] == 'V'){
            plan[y+1][x] = 'V';
            y++;
        }
        if(plan[y][x-1] == 'V'){
            plan[y][x+1] = '>';
            x++;
        }
        if(plan[y][x+1] == 'V'){
            plan[y][x-1] = '<';
            x--;
        }
        m++;
    }

    //ak som v strede nadvoria, som tam
    if((plan[y][x+1] != '.' && plan[y][x-1] != '.' &&
       plan[y-1][x] != '.' && plan[y+1][x] != '.' ) && (plan[y][x+1] != '#' && plan[y][x-1] != '#' &&
       plan[y-1][x] != '#' && plan[y+1][x] != '#' )){
        printf("ANO");
        return 0;
       }

    //odbacanie s prioritou vlavo, ak idem hore
    if(plan[y][x] == '^'){
        if(plan[y][x-1] == '.'){
            plan[y][x-1] = '<';
            nadvorie(r, s, plan, x-1, y, m);
            return 0;
        }
        if(plan[y-1][x] == '.'){
            plan[y-1][x] = '^';
            nadvorie(r, s, plan, x, y-1, m);
            return 0;
        }
        if(plan[y][x+1] == '.'){
            plan[y][x+1] = '>';
            nadvorie(r, s, plan, x+1, y, m);
            return 0;
        }
        else{
            printf("NIE");
            return 0;
        }
    }

    //odbacanie s prioritou vlavo, ak idem vlavo
    if(plan[y][x] == '<'){
        if(plan[y+1][x] == '.'){
            plan[y+1][x] = 'V';
            nadvorie(r, s, plan, x, y+1, m);
            return 0;
        }
        if(plan[y][x-1] == '.'){
            plan[y][x-1] = '<';
            nadvorie(r, s, plan, x-1, y, m);
            return 0;
        }
        if(plan[y-1][x] == '.'){
            plan[y-1][x] = '^';
            nadvorie(r, s, plan, x, y-1, m);
            return 0;
        }
        else{
            printf("NIE");
            return 0;
        }
    }

    //odbacanie s prioritou vlavo, ak idem dolu
    if(plan[y][x] == 'V'){
        if(plan[y][x+1] == '.'){
            plan[y][x+1] = '>';
            nadvorie(r, s, plan, x+1, y, m);
            return 0;
        }
        if(plan[y+1][x] == '.'){
            plan[y+1][x] = 'V';
            nadvorie(r, s, plan, x, y+1, m);
            return 0;
        }
        if(plan[y][x-1] == '.'){
            plan[y][x-1] = '<';
            nadvorie(r, s, plan, x-1, y, m);
            return 0;
        }
        else{
            printf("NIE");
            return 0;
        }
    }

    //odbacanie s prioritou vlavo, ak idem vpravo
    if(plan[y][x] == '>'){
        if(plan[y-1][x] == '.'){
            plan[y-1][x] = '^';
            nadvorie(r, s, plan, x, y-1, m);
            return 0;
        }
        if(plan[y][x+1] == '.'){
            plan[y][x+1] = '>';
            nadvorie(r, s, plan, x+1, y, m);
            return 0;
        }
        if(plan[y+1][x] == '.'){
            plan[y+1][x] = 'V';
            nadvorie(r, s, plan, x, y+1, m);
            return 0;
        }
        else{
            printf("NIE");
            return 0;
        }
    }
    return 0;
}

//--------------------------------------------------------------------------
// hladanie vchodu pomocou "rozliatie vody" teda miesto, kde sa vleje dnu
int voda(int r, int s, char plan[r][s], int x, int y){
    int m=0;

    //zmena . na V
    if(plan[y][x] == '.'){
       plan[y][x] = 'V';
    }

    //hladanie vstupu hore, dolu
    if(y>0){
        if(plan[y-1][x] == '#' && y<r-1){
            if(plan[y+1][x] == '#'){
//             printf("vchod je: %d %d", y, x);
              nadvorie(r, s, plan, x, y, m);
              return 0;
            }
        }
    }
    if(y< s-1){
        if(plan[y+1][x] == '#' && y>0){
            if(plan[y-1][x] == '#'){
//             printf("vchod je: %d %d", y, x);
              nadvorie(r, s, plan, x, y, m);
              return 0;
            }
        }
    }

    //hladanie vstupu zlava, vpravo
    if(x>0){
        if(plan[y][x-1] == '#' && x<s-1){
            if(plan[y][x+1] == '#'){
//             printf("vchod je: %d %d", y, x);
              nadvorie(r, s, plan, x, y, m);
              return 0;
            }
        }
    }
    if(x<s-1){
        if(plan[y][x+1] == '#' && x>0){
            if(plan[y][x-1] == '#'){
//             printf("vchod je: %d %d", y, x);
              nadvorie(r, s, plan, x, y, m);
              return 0;
            }
        }
    }

    //postup V ak nie som na vrchu planu
    if(y>0){
        if(plan[y-1][x] == '.'){
            voda(r, s, plan, x, y-1);
        }
    }
    //postup V ak nie som na spotku planu
    if(y<s){
        if(plan[y+1][x] == '.'){
            voda(r, s, plan, x, y+1);
        }
    }
    //postup V ak nie som na lavo planu
    if(x>0){
        if(plan[y][x-1] == '.'){
            voda(r, s, plan, x-1, y);
        }
    }
    //postup V ak nie som na pravo planu
    if(x<s-1){
        if(plan[y][x+1] == '.'){
            voda(r, s, plan, x+1, y);
        }
    }
    return 0;
}

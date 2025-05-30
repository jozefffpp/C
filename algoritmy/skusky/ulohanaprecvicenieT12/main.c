#include <stdio.h>
#include <stdlib.h>
#define DOLE 'V'
#define VPRAVO '>'
#define VLAVO '<'

int validne(char moznosti[], int pocet_miest){

    for(int i = 0; i < pocet_miest; i++){
        if(i == 0 && moznosti[i] == VLAVO){
            return 0;
        }
        if(i == pocet_miest-1 && moznosti[i] == VPRAVO){
            return 0;
        }
        if(i != pocet_miest-1){
            if(moznosti[i] == VPRAVO && moznosti[i+1] == VLAVO){
                return 0;
            }
            if(moznosti[i] == VLAVO && moznosti[i+1] == VPRAVO){
                return 0;
            }
            if(i != 0){
                if(moznosti[i] == DOLE && moznosti[i-1] == VPRAVO && moznosti[i+1] == VLAVO){
                    return 0;
                }
                if(moznosti[i] == DOLE && moznosti[i-1] == VLAVO && moznosti[i+1] == VPRAVO){
                    return 0;
                }
            }
        }
    }
    return 1;
}

//---------------------------------------------------------------------
int nastavenie(char moznosti[], int moja_pozicia, int pocet_miest){

    char znaky[3]= {DOLE, VPRAVO, VLAVO};
    int spravne = 0;

    for(int i = 0; i < 3; i++){
        moznosti[moja_pozicia] = znaky[i];

        if(moja_pozicia < pocet_miest-1){
            spravne += nastavenie(moznosti, moja_pozicia+1, pocet_miest);
        }else{
            if(validne(moznosti, pocet_miest)){
                spravne++;
            }
        }
    }
    return spravne;
}

//--------------------------------------------------------------------
int main(){

    int pocet_miest;
    scanf("%d", &pocet_miest);

    char moznosti[pocet_miest+1]; //pole moznosti

    int spravne = nastavenie(moznosti, 0, pocet_miest);

    printf("%d\n", spravne);

    return 0;
}

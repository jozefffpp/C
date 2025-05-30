#include <stdio.h>
#include <stdlib.h>


int main()
{   //zadam pocet miest
    int m;
    scanf("%d", &m);
    if(m > 100){
        printf("Zadany pocet miest je vacsi ako 100!!!");
        return 0;
    }
    float e[m], k[m-1];
    int i;
    float cena = 0;
    //zadam kazdemu mestu cenu vystavby elektrarne
    for(i=0; i<m; i++){
        scanf("%f", &e[i]);
    }
    //zadam cenu kablov m-1
    for(i=0; i<m-1; i++){
        scanf("%f", &k[i]);
    }
    //porovnám cenu vystavby elektrarne susedných miest s cenou káblu medzi nimi
    for(i=0; i<m; i++){
        if(k[i] < e[i] + e[i+1]){   //ak je kabel lacnejsi tak ho kupim
            cena += k[i];
        }else{                  //ak nie je tak kupime elektrarne
            cena += e[i] + e[i+1];
            if(k[i+1] > e[i+1] + e[i+2]){   //ak je k[i+1] drahsi ako dalsie dve elektrarne tak odcitam cenu uz postavenej elektrárne
                cena -= e[i+1];
            }
        }

    }
    printf("cena je: %.2f", cena);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
int main(){

    int n, i, j, k;

    scanf("%d", &n);

    float m[n], c[n-1];

    for(i=0; i<n; i++){
        scanf("%f", &m[i]);
    }

    for(i=0; i<n-1; i++){
        scanf("%f", &c[i]);
    }

    float v = 0.0;
    int pom = 0;

    for(i=0; i<n; i++){

        if(!pom){
            if(m[i] + m[i+1] < c[i]){
                v += m[i];
                v += m[i+1];
                pom = 1;
            }else{
                v += c[i];
                pom = 0;
            }
        }else{
            if(m[i+1] < c[i]){
                v += m[i+1];
                pom = 1;
            }else{
                v += c[i];
                pom = 0;
            }
        }
    }
    printf("\n%f\n", v);

    return 0;
}
*/

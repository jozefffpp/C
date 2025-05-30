#include <stdio.h>
#include <stdlib.h>

int main()
{
    //sustavy
        /*Program naèíta jedno celé desiatkové èíslo a vypíše ho v osmièkovej
        a šestnástkovej sústave. Upravte program tak, aby naèítal èíslo v
        šestnástkovej sústave a následne ho vypísal v desiatkovej sústave.

        int i;
        printf("Zadaj cele desiatkove cislo: ");
        scanf("%d", &i);
        printf("V 8ckovej je: %o\n", i);
        printf("V 16ckovej je: %x\n", i);
        */

            int i;
            printf("Zadaj cele sestnatskove cislo: ");
            scanf("%x", &i);
            printf("V 10rkovej je: %d\n", i);


    //minimum
        /*Program naèíta zo vstupu dve celé èísla a vypíše menšie z nich
        (za predpokladu, že sú rôzne). Upravte program tak, že namiesto
        vetvenie pomocou if...else použijete ternárny operátor podmieneného
         výrazu.

        int a, b;
        printf("Zadaj dve cisla: ");
        scanf("%d %d", &a, &b);

        if(a < b){
            printf("Mensie je %d\n", a);
            }
        else{
            printf("Mensie je %d\n", b);
        }*/

            int a, b;
            printf("Zadaj dve cisla: ");
            scanf("%d %d", &a, &b);

            printf("Mensie je %d\n", (a<b) ? a: b);


    //pismena

        /*Program naèíta jeden znak (treba zada velme písmeno).
        Toto písmeno následne prevedie na malé a vypíše ho na štandardný
        výstup. Upravte program tak, že bude opakovane naèítava a následne
        vypisova znaky do vtedy, kým nebude naèítaný znak '*'. Okrem toho
         vypisovaní všetky ve¾ké písmená zmení na malé.

        char c;
        printf("Zadaj znak: ");
        c = getchar();
        c += 'a' - 'A';
        printf("Znak %c ma ASCII hodnotu %d\n", c, c);
         */

            char c;
            while(printf("Zadaj znak: "),(c = getchar()) != '*'){
            if(c == '\n'){continue;}
            if(c < 'z' && c >'a'){
                printf("Znak %c ma ASCII hodnotu %d\n", c, c);
            }else{
                c += 'a' - 'A';
                printf("Znak %c ma ASCII hodnotu %d\n", c, c);
                }
            }


    //faktorial
        /*Program naèíta celé kladné èíslo a vypoèíta a vypíše hodnotu
        faktoriálu tohto èísla. Pred spustením programu zistite, aký výsledok
        program dá pre vstupnú hodnotu 0 a záporné èíslo. Potom program
        upravte tak, že cyklus s pevným poètom opakovaní (for) nahradíte
        yklom s podmienkou na zaèiatku (while).

        int n, f, i;
        printf("Zadaj cele cislo: ");
        scanf("%d", &n);
        f = 1;
        for(i=1; i<=n; i++) {
            f *= i;
        }
        printf("%d! = %d\n", n, f);
        */
            int n, f, i;
            printf("Zadaj cele cislo: ");
            scanf("%d", &n);
            f = 1;
            i = 1;
            while(i <= n){
                f *= i;
                i++;
            }
            printf("%d! = %d\n", n, f);






    return 0;
}

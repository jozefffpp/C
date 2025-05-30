#include <stdio.h>
#include <stdlib.h>

int main()
{
    //sustavy
        /*Program na��ta jedno cel� desiatkov� ��slo a vyp�e ho v osmi�kovej
        a �estn�stkovej s�stave. Upravte program tak, aby na��tal ��slo v
        �estn�stkovej s�stave a n�sledne ho vyp�sal v desiatkovej s�stave.

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
        /*Program na��ta zo vstupu dve cel� ��sla a vyp�e men�ie z nich
        (za predpokladu, �e s� r�zne). Upravte program tak, �e namiesto
        vetvenie pomocou if...else pou�ijete tern�rny oper�tor podmienen�ho
         v�razu.

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

        /*Program na��ta jeden znak (treba zada� velme p�smeno).
        Toto p�smeno n�sledne prevedie na mal� a vyp�e ho na �tandardn�
        v�stup. Upravte program tak, �e bude opakovane na��tava� a n�sledne
        vypisova� znaky do vtedy, k�m nebude na��tan� znak '*'. Okrem toho
         vypisovan� v�etky ve�k� p�smen� zmen� na mal�.

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
        /*Program na��ta cel� kladn� ��slo a vypo��ta a vyp�e hodnotu
        faktori�lu tohto ��sla. Pred spusten�m programu zistite, ak� v�sledok
        program d� pre vstupn� hodnotu 0 a z�porn� ��slo. Potom program
        upravte tak, �e cyklus s pevn�m po�tom opakovan� (for) nahrad�te
        yklom s podmienkou na za�iatku (while).

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

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //hello world

    printf("Hello world!\n");
    return 0;


    //Program vypíše na obrazovku pozdrav.
    // Program upravte tak, aby vypísal pozdrav v inom jazyku.
        printf("Bonjour le monde!\n");

    //sucet


    int a, b, c;
    a = 2;
    b = 3;
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);


    /*Program vypoèíta a vypíše súèet dvoch celıch èísel. Upravte program tak,
    aby dve vstupnéèísla naèítal z klávesnice pomocou príkazov printf
     a scanf.*/

       // int a, b, c;
        printf("zadaj a: ");
        scanf("%d", &a);
        printf("zadaj b: ");
        scanf("%d", &b);
        c = a + b;
        printf("%d + %d = %d\n", a, b, c);


    // obdlznik
    /*
    Program naèíta z klávesnice dåky strán obdånika a vypoèíta a
    vypíše jeho obsah. Upravte program tak, aby vypoèítal obsah kruhu so
    zadanım polomerom. Pozor, vısledok môe by reálne èíslo.
    Vısledok vypíšte s presnosou na 2 desatinné miesta.


    int a, b;
    printf("Zadaj dlzku strany a: ");
    scanf("%d", &a);
    printf("Zadaj dlzku strany b: ");
    scanf("%d", &b);
    printf("Obsah je: %d\n", a * b);
    */

#include <math.h>

        float r;
        printf("Zadaj r kruhu: ");
        scanf("%f", &r);
        printf("Obsah je: %f\n", M_PI *( r*r) );


    //delenie
    /*Program vydelí dve celé èísla naèítane z klávesnice a vısledok vypíše.
     Upravte program tak, aby bola vykonaná operácie delenia
     a reálnej aritmetike (vısledok bol desatinné èíslo). Pouite operáciu
      pretypovania.

        printf("Zadaj dve cisla\n");
        int i,j;
        double v;
        scanf("%d %d", &i, &j);
        v = i / j;
        printf("%.20f", v);
        */

            printf("Zadaj dve cisla\n");
            int i,j;
            double v;
            scanf("%d %d", &i, &j);
            v = (float)i / (float)j;
            printf("%.20f", v);


    //operatory
    /*Program demonštruje vykonávanie rôznych operátorov. Pred
    spustením programu sa pokúste urèi, aké hodnoty bude program vypisova.

        int i=4, j=3;
        printf("i=%d\tj=%d\n", i, j);
        j += i;
        printf("i=%d\tj=%d\n", i, j);
        j /= --i;
        printf("i=%d\tj=%d\n", i, j);
        j *= i-2;
        printf("i=%d\tj=%d\n", i, j);
        */

    /*Program vypíše ve¾kosti premennıch rôzneho druhu.*/
    printf("int\t%lu B\n", sizeof(int));
    printf("short\t%lu B\n", sizeof(short));
    printf("long\t%lu B\n", sizeof(long));
    printf("signed short\t%lu B\n", sizeof(signed short));
    printf("unsigned short\t%lu B\n", sizeof(unsigned short));
    printf("char\t%lu B\n", sizeof(char));
    printf("float\t%lu B\n", sizeof(float));
    printf("double\t%lu B\n", sizeof(double));
    return 0;
}


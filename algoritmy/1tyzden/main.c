#include <stdio.h>
#include <stdlib.h>

int main()
{
    //hello world

    printf("Hello world!\n");
    return 0;


    //Program vyp�e na obrazovku pozdrav.
    // Program upravte tak, aby vyp�sal pozdrav v inom jazyku.
        printf("Bonjour le monde!\n");

    //sucet


    int a, b, c;
    a = 2;
    b = 3;
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);


    /*Program vypo��ta a vyp�e s��et dvoch cel�ch ��sel. Upravte program tak,
    aby dve vstupn���sla na��tal z kl�vesnice pomocou pr�kazov printf
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
    Program na��ta z kl�vesnice d�ky str�n obd�nika a vypo��ta a
    vyp�e jeho obsah. Upravte program tak, aby vypo��tal obsah kruhu so
    zadan�m polomerom. Pozor, v�sledok m��e by� re�lne ��slo.
    V�sledok vyp�te s presnos�ou na 2 desatinn� miesta.


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
    /*Program vydel� dve cel� ��sla na��tane z kl�vesnice a v�sledok vyp�e.
     Upravte program tak, aby bola vykonan� oper�cie delenia
     a re�lnej aritmetike (v�sledok bol desatinn� ��slo). Pou�ite oper�ciu
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
    /*Program demon�truje vykon�vanie r�znych oper�torov. Pred
    spusten�m programu sa pok�ste ur�i�, ak� hodnoty bude program vypisova�.

        int i=4, j=3;
        printf("i=%d\tj=%d\n", i, j);
        j += i;
        printf("i=%d\tj=%d\n", i, j);
        j /= --i;
        printf("i=%d\tj=%d\n", i, j);
        j *= i-2;
        printf("i=%d\tj=%d\n", i, j);
        */

    /*Program vyp�e ve�kosti premenn�ch r�zneho druhu.*/
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


/* Programovanie v C - Miroslav Melichercik */

/*Program na��ta polomer kruhu a vypo��ta jeho obsah. Kon�tanta PI a druh�
mocnina je definovan� pomocou makra. Pok�ste sa ur�i�, ako bude vyzera� dan�
zdrojov� k�d po spracovan� preprocesorom, obzvl᚝ sa zamerajte na riadok S =
 PI * na_druhu(r); Svoju odpove� si overte spusten�m prekladu programu s
 prep�na�om -E, ktor� ukon�� preklad programu po vykonan� preprocesingu.
  V�stup preprocesora je m��ete n�js� v adres�ri projektu a podadres�ri obj
  , Debug s n�zvom main.o. Tento s�bor je potrebn� odovzda� cez lms moodle.*/


#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define na_druhu(x) ((x)*(x))

int main()
{
    printf("Zadaj polomer: ");
    float r, S;
    scanf("%f", &r);
    //toto je priklad pouzitia makier
    S = PI * na_druhu(r);
    printf("S = %f\n", S);
    return 0;
}



/*Program demon�truje pou�itie podmienen�ho prekladu na z�klade toho, �i je
 zadefinovan� ur�it� makro (SK, DE, ...). Zadefinujte pr�slu�n� makr� tak,
 aby ste mohli skompilova� vybran� jazykov� mut�ciu programu. Vysk��ajte
 program postupne skompilova� pre v�etky 3 jazyky. Vysk��ajte makro
 zadefinova� pomocou pr�kazu preprocesora, napr. #define SK, ako aj pomocou
  parametra pri preklade programu, napr. -DSK.*/


/* Programovanie v C - Miroslav Melichercik */


#include <stdio.h>
#include <stdlib.h>

#define DE
int main()
{
#ifdef SK
    printf("Ahoj svet!\n");
#elif defined DE
    printf("Hallo Welt\n");
#else
    printf("Hello world!\n");
#endif
    return 0;
}







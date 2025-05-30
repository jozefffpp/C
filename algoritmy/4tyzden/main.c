/* Programovanie v C - Miroslav Melichercik */

/*Program naèíta polomer kruhu a vypoèíta jeho obsah. Konštanta PI a druhá
mocnina je definovaná pomocou makra. Pokúste sa urèi, ako bude vyzera danı
zdrojovı kód po spracovaní preprocesorom, obzvláš sa zamerajte na riadok S =
 PI * na_druhu(r); Svoju odpoveï si overte spustením prekladu programu s
 prepínaèom -E, ktorı ukonèí preklad programu po vykonaní preprocesingu.
  Vıstup preprocesora je môete nájs v adresári projektu a podadresári obj
  , Debug s názvom main.o. Tento súbor je potrebné odovzda cez lms moodle.*/


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



/*Program demonštruje pouitie podmieneného prekladu na základe toho, èi je
 zadefinované urèité makro (SK, DE, ...). Zadefinujte príslušné makrá tak,
 aby ste mohli skompilova vybranú jazykovú mutáciu programu. Vyskúšajte
 program postupne skompilova pre všetky 3 jazyky. Vyskúšajte makro
 zadefinova pomocou príkazu preprocesora, napr. #define SK, ako aj pomocou
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







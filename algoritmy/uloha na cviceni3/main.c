/*
 * Nazov: uloha 4
 * Autor: Miroslav Melichercik
 * Rok:   2020/2021
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char nazov[30];
  printf("Zadaj nazov suboru: ");
  scanf("%s", nazov);

  FILE *vstup, *vystup;
  vstup = fopen(nazov, "r");
  vystup = fopen("komentare.txt", "w");

  int c;
  int rkom = 0, vkom = 0;
  while((c = getc(vstup)) != EOF) {
    if(c == '/') { //mozno zacina komentar
      int c2;
      c2 = getc(vstup); //pozriem dalsi znak v subore
      if(c2 == '/') { //urcite zacina // komentar
        rkom = 1;
      }
      if(c2 == '*') { //urcite zacina /* komentar
        vkom = 1;
      }
      ungetc(c2, vstup);
    }

    if(rkom && c == '\n') { //konci // komentar
      rkom = 0;
    }

    if(c == '*') {  //mozno konci */ komentar
      int c2;
      c2 = getc(vstup);
      if(c2 == '/') { //urcite konci */ komentar
        vkom = 0;
        putc(c, vystup);
        putc(c2, vystup);
        putchar(' ');
        putchar(' ');
        continue; //aby pokracoval na dalsi znak zo suboru
      } else {
        ungetc(c2, vstup);
      }
    }

    if(c == '\n') { // \n zapis do oboch vystupov
      putchar('\n');
      putc('\n', vystup);
    } else {  // ine znaky pis len do jedneho vystupu
      if(rkom || vkom) {  //ak vypisujem komentar
        putchar(' ');
        putc(c, vystup);
      } else {    //ak nevypisujem komentar
        putchar(c);
        putc(' ', vystup);
      }
    }
  }

  fclose(vstup);
  fclose(vystup);

  return 0;
}


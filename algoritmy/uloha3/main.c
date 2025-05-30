#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fr, *fw;
    int bol_koniec = 1;

    fr = fopen("vstup.txt", "r");
    fw = fopen("vystup.txt", "w");

    char c;

    while((c=getc(fr)) != EOF){
        if(c == '.' || c == '?' || c == '!'){
            bol_koniec = 1;
        }
        if(bol_koniec && c >= 'a' && c<= 'z'){
            c -= 'a' - 'A';
            bol_koniec = 0;
        }
        if(bol_koniec && c >= 'A' && c<= 'Z'){
            bol_koniec = 0;
        }
            putc(c, fw);
    }

    fclose(fr);
    fclose(fw);

    return 0;
}

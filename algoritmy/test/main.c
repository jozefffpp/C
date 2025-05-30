#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j, i;
    j=0;
    i=0;
    FILE *f;
    char c;
    f = fopen("cisla.txt", "r");

    while((c=getc(f)) != EOF){

    if((c >= '0') && (c <='9')){
        i = i + atoi(c);
    }
    }

    printf("%d", i);

    fclose(f);



  /*  if(isdigit(c)){
        ungetc(c, f);
        fscanf(f, "%d", &pom)
        sum += pom;

        s="35"
        i = atoi(s);
        sscanf(s, "%d", &i);
    }*/
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
/*
int cislo();

int main()
{
    int j, i;
    j=0;
    i=0;

    j = cislo();
    printf("%d", i);

    return 0;
}

int cislo(){
    int i;
    scanf("%d", i);

return i;
}
*/

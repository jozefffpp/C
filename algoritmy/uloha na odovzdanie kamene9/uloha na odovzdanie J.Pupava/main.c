#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, najmensie,index, kamene[20], i, den = 1;
    FILE *fr;

    fr = fopen("kamene.txt", "r");
    fscanf(fr, "%d", &n);

    for(i=0; i<n; i++){
         fscanf(fr, "%d", &kamene[i]);
    }
    najmensie = kamene[0];
    index = 0;
    for(i=0; i<n; i++){
        if(kamene[i] < najmensie){
            index = i;
            najmensie = kamene[i];
        }
        else if(kamene[i] == najmensie){
            if((kamene[index-1] + kamene[index+1]) > (kamene[i-1] + kamene[i+1])){
                index = i;
                najmensie = kamene[i];
            }
        }
    }

    if(kamene[index-1] < kamene[index+1]){
        index = kamene[index-1];
    }
    else{
        index = kamene[index+1];
    }

    printf("posledny den je : %d \n", index);

    fclose(fr);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[4]= {4, 2, 3, 1};
    int i, j, key;
    for (i=1; i<4; i++){
        key = A[i];
        j= i-1;
        while(j>0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }

    printf("Hello world!\n");
    return 0;
}

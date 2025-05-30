#include <stdio.h>
#include <stdlib.h>

int main()
{
    {
        unsigned int a;
        a = ~0;
        printf("uint %u\n",a );
    }
    {
        unsigned short a;
        a = ~0;
        printf("ushort %u\n",a );
    }
    {
        signed int a;
        a = ~0;
        printf("signed %d\n",a );
    }
    {
        unsigned int x;
        printf("zadaj cele kladne cislo: \n",x );
        scanf("%u", &x);
        if (x & 1){
            printf("cislo %u je neparne\n", x);
        }
        else{
            printf("cislo %u je parne\n", x);
        }
    }
    {
        unsigned x, n, i;
        printf("zadaj cele kladne cislo: \n",x );
        scanf("%u", &x);
        printf("zadaj posun: \n",n );
        scanf("%u", &n);

        unsigned maska;
        maska = ~0;
        maska >>= 1;
        maska = ~maska;

        for(i=0; i<n; i++){
            int bola1 = x&1;
            x>>=1; // x = x>>1;
            if(bola1){
                x |= maska;
            }
            printf("%u\t%u\n", i +1, x);
            dodvojkovej(x);
        }
    }

    return 0;
}
void dodvojkovej(unsigned x){
    unsigned maska;
    maska = ~0;
    maska >>= 1;
    maska = ~maska;

    while(maska){
        putchar(x&maska ? '1': '0');
        maska >>=1;
    }
    putchar('\n');
}

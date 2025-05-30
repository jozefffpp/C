int najdi(int len, char retazec[], int counti, int N){

    int pocet= 0, opakovacka = 0;
    char podret[len-N+1][N+1];
    char *ptr;

    for(int i=0; i<counti; i++){
        strncpy(podret[i], &retazec[i], N); //najdi podretazec ak existuje kopia
        ptr = strstr(&retazec[i+1], podret[i]);
        while(ptr){
            pocet--;
            ptr = strstr(ptr+1, podret[i]);
            opakovacka++;
        }
        pocet += 1;
    }
    printf("opakuje sa: %d\n", opakovacka);
    return pocet;
}
int najdi(int len, char retazec[], int counti, int N);

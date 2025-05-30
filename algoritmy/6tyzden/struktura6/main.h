#define MAX 100

typedef struct {
    char meno[20];
    char priezv[30];
    int vek;
} CLOVEK;

void menu();
void pridaj(CLOVEK p[MAX], int *pocet);
void vypis(CLOVEK p[MAX], int pocet);
void uloz(CLOVEK p[MAX], int pocet);
void nacitaj(CLOVEK p[MAX], int *pocet);

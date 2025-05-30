//nove udajove typy
typedef struct atom {
    //data
    int cislo;
    //prepojenie
    struct atom *dalsi;
} ATOM;

//funkcne prototypy
void pridaj_na_zaciatok(ATOM **zac, int c);
void pridaj_za_kurzor(ATOM *kur, int c);
int odober_za_kurzorom(ATOM *kur);
ATOM* najdi(ATOM *zac, int c);

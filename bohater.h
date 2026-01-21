#ifndef BOHATER_H
#define BOHATER_H

#define MAX_IMIE 100
#define MAX_TEKST 50





typedef struct {
    char imie[MAX_IMIE];  
    char rasa[MAX_TEKST];
    char klasa[MAX_TEKST];
    int poziom;
    int reputacja;
    char status[MAX_TEKST];  
} bohater;





//bohaterowie
void dodaj_bohatera(bohater **lista, int *liczba);
void wyswietl_bohaterow(bohater *lista, int liczba);
int znajdz_bohatera(bohater *lista, int liczba, const char *imie);
void edytuj_bohatera(bohater *lista, int liczba);
void usun_bohatera(bohater **lista, int *liczba);



//sortowsanie
void sortuj_po_imieniu(bohater *lista, int liczba);
void sortuj_po_poziomie(bohater *lista, int liczba);


//pliki
void zapisz_do_pliku(bohater *lista, int liczba);
void wczytaj_z_pliku(bohater **lista, int *liczba);




#endif

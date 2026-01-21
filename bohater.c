#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bohater.h"

int znajdz_bohatera(bohater *lista, int liczba, const char *imie) {

    for (int i = 0; i < liczba; i++) {

        if (strcmp(lista[i].imie, imie) == 0)
            return i;

    }
    return -1;
}

void dodaj_bohatera(bohater **lista , int *liczba) {

    bohater b;


    printf("imie bohatera : ");
    fgets(b.imie, MAX_IMIE , stdin);

    b.imie[strcspn(b.imie , "\n")] = 0;



    if (znajdz_bohatera(*lista , *liczba, b.imie) != -1) {
        printf("bohater o takim imieniu juz istnieje!\n");
        return;
    }

    printf("rasa: ");
    fgets(b.rasa, MAX_TEKST, stdin);

    b.rasa[strcspn(b.rasa, "\n")] = 0;

    printf("klasa: ");
    fgets(b.klasa, MAX_TEKST, stdin);

    b.klasa[strcspn(b.klasa, "\n")] = 0;

    //sparawdzanie poziomu
    do {

        printf("poziom (>=1): ");
        scanf("%d", &b.poziom);
        getchar();
        if (b.poziom < 1) printf("blad : poziom musi byc >= 1\n");

    } while (b.poziom < 1);

    //sprawdzanie reputacji
    do {

        printf("reputacja (0-100): ");
        scanf("%d", &b.reputacja);
        getchar();
        if (b.reputacja < 0 || b.reputacja > 100) 
            printf("blad: reputacja musi byc w zakresie 0-100\n");

    } while (b.reputacja < 0 || b.reputacja > 100);

    //sprawdzanie statusu
    char *statusy[] = {"aktywny", "na misji", "ranny", "zaginiony", "zawieszony"};
    int ok;
    do {

        printf("status (aktywny, na misji, ranny, zaginiony, zawieszony): ");
        fgets(b.status, MAX_TEKST, stdin);
        b.status[strcspn(b.status, "\n")] = 0;

        ok = 0;
        for (int i = 0 ; i < 5 ; i++) {

            if (strcmp(b.status, statusy[i]) == 0) {
                ok = 1;
                break;
            }


        }
        if (!ok) printf(" blad : podano niepoprawny status  \n");
    } while (!ok);

    *lista = realloc(*lista, (*liczba + 1) * sizeof(bohater));
    (*lista)[*liczba] = b;
    (*liczba)++;

    printf("dodano bohatera.\n");
}

void wyswietl_bohaterow(bohater *lista, int liczba) {
    if (liczba == 0) {

        printf("brak bohaterow.\n");
        return;

    }

    printf("\n%-15s %-12s %-12s %-7s %-10s %-12s\n",
           "imie", "rasa", "klasa", "poziom", "reputacja", "status");

    printf("-------------------------------------------------------------------\n");

    for (int i = 0 ; i < liczba ; i++ ) {


        printf("%-15s %-12s %-12s %-7d %-10d %-12s\n",
               lista[i].imie,
               lista[i].rasa,
               lista[i].klasa,
               lista[i].poziom,
               lista[i].reputacja,
               lista[i].status);

    }
}

void edytuj_bohatera(bohater *lista, int liczba ) {
    char imie[MAX_IMIE];

    printf("podaj imie bohatera do edycji: ");
    fgets(imie , MAX_IMIE, stdin);
    imie[strcspn(imie , "\n")] = 0;

    int idx = znajdz_bohatera(lista, liczba, imie);
    if (idx == -1) {

        printf("nie znaleziono bohatera.  \n");
        return;

    }









    printf("nowa rasa : ");
    fgets(lista[idx].rasa, MAX_TEKST, stdin);

    lista[idx].rasa[strcspn(lista[idx].rasa, "\n")] = 0;

    printf("nowa klasa: ");
    fgets(lista[idx].klasa, MAX_TEKST, stdin);
    lista[idx].klasa[strcspn(lista[idx].klasa, "\n")] = 0;

    //poziom
    do {

        printf("nowy poziom (>=1): ");
        scanf("%d", &lista[idx].poziom);
        getchar();
        if (lista[idx].poziom < 1) printf("blad: poziom musi byc >= 1\n");

    } while (lista[idx].poziom < 1);

    //reputacja
    do {
        printf("nowa reputacja (0-100): ");
        scanf("%d", &lista[idx].reputacja);
        getchar();
        if (lista[idx].reputacja < 0 || lista[idx].reputacja > 100)
            printf("blad: reputacja musi byc w zakresie 0-100\n");
    } while (lista[idx].reputacja < 0 || lista[idx].reputacja > 100);

    //status

    char *statusy[] = {"aktywny", "na misji", "ranny", "zaginiony", "zawieszony"};
    int ok;
    do {

        printf("nowy status (aktywny, na misji, ranny, zaginiony, zawieszony): ");
        fgets(lista[idx].status, MAX_TEKST, stdin);
        lista[idx].status[strcspn(lista[idx].status, "\n")] = 0;


        ok = 0;
        for (int i = 0; i < 5; i++) {
            if (strcmp(lista[idx].status, statusy[i]) == 0) {
                
                ok = 1;
                break;


            }
        }
        if (!ok) printf("blad: podano niepoprawny status\n");

    } while (!ok);

    printf("zaktaulizowano dane bohatera.\n");
}

void usun_bohatera(bohater **lista, int *liczba) {
    char imie[MAX_IMIE];


    printf("podaj imie bohatera do usuniecia: ");
    fgets(imie, MAX_IMIE, stdin);
    imie[strcspn(imie, "\n")] = 0;



    int idx = znajdz_bohatera(*lista, *liczba, imie);
    if (idx == -1) {


        printf("nie znaleziono bohatera.\n");
        return;


    }

    if (strcmp((*lista)[idx].status, "na misji") == 0) {

        printf("nie mozna usunac bohatera na misji!\n");
        return;

    }

    for (int i = idx; i < *liczba - 1; i++) {

        (*lista)[i] = (*lista)[i + 1];
        

    }

    (*liczba)--;
    *lista = realloc(*lista, (*liczba) * sizeof(bohater));

    printf("usunieto bohatera.\n");



}







//sortowanie

void sortuj_po_imieniu(bohater *lista, int liczba) {
    if (liczba < 2) {

        printf("za malo bohaterow do sortowania \n");
        return;

    }

    bohater *kopia = malloc( liczba * sizeof(bohater) );

    for (int i = 0 ; i < liczba ; i++) kopia[i] = lista[i];



    for (int i = 0 ; i < liczba - 1 ; i++) {


        for (int j = 0; j < liczba - 1 - i; j++) {


            if (strcmp(kopia[j].imie, kopia[j + 1].imie ) > 0) {
                bohater temp = kopia[j];
                kopia[j] = kopia[j + 1];
                kopia[j + 1] = temp;



            }


        }
    }










    printf("\n----posortowane alfabetycznie(imie)---\n");
    wyswietl_bohaterow(kopia, liczba);



    free(kopia);
}



void sortuj_po_poziomie(bohater *lista, int liczba) {
    if (liczba < 2) {

        printf("za malo bohaterow do sortowania.\n");
        return;

    }

    bohater *kopia = malloc( liczba * sizeof(bohater) );
    for (int i = 0; i < liczba; i++) kopia[i] = lista[i];

    for ( int i = 0 ; i < liczba - 1 ; i++) {


        for (int j = 0 ; j < liczba - 1 - i ; j++) {
            if (kopia[j].poziom > kopia[j + 1].poziom ) {
                bohater temp = kopia[j];
                kopia[j] = kopia[j + 1];
                kopia[j + 1] = temp;


            }
        }
    }



    printf("\n---posortowane wedlug poziomu---\n");


    wyswietl_bohaterow(kopia, liczba);

    free(kopia);




}

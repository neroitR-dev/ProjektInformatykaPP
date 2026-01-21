#include <stdio.h>
#include <stdlib.h>
#include "bohater.h"









void zapisz_do_pliku(bohater *lista, int liczba) {


    FILE *plik = fopen("bohaterowie.txt", "w");
    if (!plik) {
        printf("blad zapisu do pliku.\n");
        return;
    }



    fprintf(plik, "%d\n", liczba);
    for (int i = 0; i < liczba; i++) {


        fprintf(plik, "%s;%s;%s;%d;%d;%s\n",
                lista[i].imie,
                lista[i].rasa,
                lista[i].klasa,
                lista[i].poziom,
                lista[i].reputacja,
                lista[i].status);


    }

    fclose(plik);
    printf("zapisano do pliku.\n");


}






void wczytaj_z_pliku(bohater **lista, int *liczba) {

    FILE *plik = fopen("bohaterowie.txt", "r");
    if (!plik) {
        printf("brak pliku.\n");
        return;




    }

    fscanf(plik, "%d\n", liczba);
    *lista = malloc(*liczba * sizeof(bohater));



    for (int i = 0; i < *liczba; i++) {


        fscanf(plik, "%[^;];%[^;];%[^;];%d;%d;%[^\n]\n",
               (*lista)[i].imie,
               (*lista)[i].rasa,
               (*lista)[i].klasa,
               &(*lista)[i].poziom,
               &(*lista)[i].reputacja,
               (*lista)[i].status);


    }

    fclose(plik);

    printf("wczytano z pliku\n");





}

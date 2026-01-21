#include <stdio.h>
#include <stdlib.h>

#include "bohater.h"




int main() {



    bohater *lista = NULL;

    int liczba = 0;
    int wybor;

    do {


        printf("\n--- rejestr gildii poszukiwaczy przygod --- \n");
        printf("1. dodaj bohatera \n");
        printf("2. edytuj bohatera \n");
        printf("3. usun bohatera \n");
        printf("4. wyswietl wszystkich \n");
        printf("5. zapisz do pliku \n");
        printf("6. wczytaj z pliku \n");
        printf("7. sortuj alfabetycznie (imie) \n");
        printf("8. sortuj wedlug poziomu \n");
        printf("0. wyjscie\n");
        printf("wybor: ");


        scanf("%d", &wybor);
        getchar();


        switch (wybor) {

            case 1: dodaj_bohatera(&lista, &liczba); break;
            case 2: edytuj_bohatera(lista, liczba); break;
            case 3: usun_bohatera(&lista, &liczba); break;
            case 4: wyswietl_bohaterow(lista, liczba); break;
            case 5: zapisz_do_pliku(lista, liczba); break;
            case 6: wczytaj_z_pliku(&lista, &liczba); break;
            case 7: sortuj_po_imieniu(lista, liczba); break;
            case 8: sortuj_po_poziomie(lista, liczba); break;
            case 0: printf("koniec programu.\n"); break;
            default: printf("niepoprawny wybor.\n");
            


        }
    } while (wybor != 0);



    free(lista);

    return 0;


}

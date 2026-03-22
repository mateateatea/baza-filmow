#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic.h"
#include "io.h"
#include <windows.h>

int main(){
    SetConsoleOutputCP(65001);
    struct Film *tablica = malloc(2*sizeof(struct Film));
    int ile_filmow = 0;
    int limit = 2;
   
    tablica = wczytaj_filmy(tablica, &ile_filmow,&limit);
    
    
    while(1){
        int choice;
        printf("Witamy w bazie filmów!\n");
        printf("Wybierz opcję:\n");
        printf("1. Dodaj filmy\n");
        printf("2. Wyświetl filmy\n");
        printf("3. Usuń filmy\n");
        printf("4. Wpisz tytuł i wyświetl jego statystyki\n");
        printf("5. Sortuj\n");
        printf("6. Wyjdź\n");
        printf("Twój wybór: \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            tablica = dodaj_filmy(tablica,&ile_filmow,&limit);
            break;
        case 2:
            wyswietl_filmy(tablica,ile_filmow);
            break;
        case 3:
            tablica = usun_filmy(tablica,&ile_filmow);
            break;
        case 4:
            szukaj_filmu(tablica,ile_filmow);
            break;
        case 5:
           printf("Po jakim kryterium chcesz sortować filmy? \n");
            printf("1. Po kryterium oceny\n");
            printf("2. Alfabetycznie po tytule\n");
            printf("3. Alfabetycznie po gatunku\n");
            int x;
            scanf("%d",&x);
            switch (x)
            {
            case 1:
                sortuj(tablica,&ile_filmow,porownaj_ocene);
                wyswietl_filmy(tablica,ile_filmow);
                break;
            case 2:
                sortuj(tablica,&ile_filmow,porownaj_tytul);
                wyswietl_filmy(tablica,ile_filmow);
                break;
            case 3:
                sortuj(tablica,&ile_filmow,porownaj_gatunek);
                wyswietl_filmy(tablica,ile_filmow);
                break;
            default:
                break;
            }
            break;
        case 6:
            zapisz_filmy(tablica,ile_filmow);
            free(tablica);
            return 0;
        default:
            break;
        }
    }
    return 0;
}

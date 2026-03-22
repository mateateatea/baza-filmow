#include <stdio.h>
#include "logic.h"
#include <stdlib.h>
#include <string.h>
#include "io.h"

void wyswietl_filmy(struct Film *tablica, int ile_filmow){
    for (int i = 0;i<ile_filmow;i++){
            printf("Tytuł: %s\n", tablica[i].tytul);
            printf("Gatunek: %s\n", tablica[i].gatunek);
            printf("Ocena: %d/10\n", tablica[i].ocena);
            printf("Obejrzany: %s\n", tablica[i].obejrzany ? "tak" : "nie");
            printf("\n");
}
}

struct Film * dodaj_filmy(struct Film *tablica, int *ile_filmow, int *limit){
    while (*ile_filmow<=*limit){
            if (*ile_filmow == *limit){
                (*limit)*=2;
                struct Film *tmp = realloc(tablica, *limit * sizeof(struct Film));
                if (tmp == NULL){
                    printf("Błąd alokacji pamięci!\n");
                    free(tablica);
                    return tablica;
                }
            tablica = tmp;
            }
            printf("Wpisz film, gatunek, ocene, oraz czy go obejrzales: ");
            scanf(" %s %s %d %d",tablica[*ile_filmow].tytul,tablica[*ile_filmow].gatunek, &tablica[*ile_filmow].ocena, &tablica[*ile_filmow].obejrzany );
            (*ile_filmow)++;
            char cnt;
            printf("Czy chcesz dodac kolejny film? Wpisz 't', jeśli tak, lub 'n', jeśli nie: ");
            scanf(" %c",&cnt);
            if (cnt =='t'){
                continue;
            }else if(cnt == 'n'){
                break;
            }else{
                printf("Wpisano niepoprawną liczbę!");
                return tablica;
            }
    }
    return tablica;
}

struct Film * usun_filmy(struct Film *tablica, int *ile_filmow){
    int i;
    printf("Który film chcesz usunąć?\n");
    for (i = 0;i<*ile_filmow;i++){
        printf("%d. Tytuł: %s\n",i+1, tablica[i].tytul);
    }
    int usun;
    if (scanf("%d",&usun) == 1 && usun>0 && usun<=*ile_filmow){
        usun--;
        for (usun;usun<*ile_filmow;usun++){
        tablica[usun] = tablica[usun+1];
    }
    (*ile_filmow)--;
    }else{
        printf("Nieprawidłowy wybór!\n");
        printf("\n");
        return tablica;
    }
    return tablica;
}

void szukaj_filmu(struct Film *tablica, int ile_filmow){
    char tytul[100];
            int znalezione = 0;
            printf("Wpisz tytuł: \n");
            scanf("%s", tytul);
            for (int i = 0; i<ile_filmow;i++){
                if(strcmp(tytul, tablica[i].tytul)==0){
                    znalezione = 1;
                    printf("Gatunek: %s\n", tablica[i].gatunek);
                    printf("Ocena: %d/10\n", tablica[i].ocena);
                    printf("Obejrzany: %s\n", tablica[i].obejrzany ? "tak" : "nie");
                    printf("\n");
                }
            
            }
            if (znalezione == 0){
                printf("Nie znaleziono!\n");
                printf("\n");
            }
}

void sortuj(struct Film *tablica, int *ile_filmow, int(*compare)(struct Film *,struct Film *)){
    struct Film tmp;
    for (int i = 0;i<*ile_filmow;i++){
        for (int j = 0;j<*ile_filmow-i-1;j++){
            if (compare(&tablica[j], &tablica[j+1])){
                    tmp = tablica[j];
                    tablica[j] = tablica[j+1];
                    tablica[j+1] = tmp;
            }
        }
    }   
}

int porownaj_ocene(struct Film *a,struct Film *b){
    if (a->ocena > b->ocena){
        return 1;
    }else{
        return 0;
    }
}

int porownaj_tytul(struct Film *a, struct Film *b){
    int wynik;
    wynik =  strcmp(a->tytul,b->tytul);
    if (wynik == 1){
        return 1;
    }else{
        return 0;
    }
}

int porownaj_gatunek(struct Film *a, struct Film *b){
    int wynik; 
    wynik = strcmp(a->gatunek,b->gatunek);
    if (wynik == 1){
        return 1;
    }else{
        return 0;
    }
}
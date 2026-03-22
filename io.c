#include <stdio.h>
#include "io.h"
#include <stdlib.h>

struct Film * wczytaj_filmy(struct Film *tablica, int *ile_filmow, int *limit){
    FILE *plik = fopen("filmy.txt", "r");
    if (plik!=NULL){
        while(1){
            if (*ile_filmow == *limit){
                (*limit)*=2;
                struct Film *tmp = realloc(tablica, *limit * sizeof(struct Film));
                if (tmp == NULL){
                    free(tablica);
                    printf("Błąd alokacji pamięci! \n");
                    return(tablica);
                }
                tablica = tmp;
                
            }
            int wynik = fscanf(plik, "%s %s %d %d\n",tablica[*ile_filmow].tytul,tablica[*ile_filmow].gatunek, &tablica[*ile_filmow].ocena, &tablica[*ile_filmow].obejrzany);
            if (wynik != 4){
                break;
            } 
            (*ile_filmow)++;
        }
        fclose(plik);
    }else{
        printf("Błąd wczytania! \n");
    }
    return tablica;

}

void zapisz_filmy(struct Film *tablica, int ile_filmow){
    FILE *plik = fopen("filmy.txt", "w");
    if (plik != NULL){
            for (int i=0;i<ile_filmow;i++){
                fprintf(plik, "%s %s %d %d\n",tablica[i].tytul, tablica[i].gatunek, tablica[i].ocena, tablica[i].obejrzany);
        }
            fclose(plik);
    }else{
        printf("Błąd zapisu, lub 0 filmów!");
    }
    
}
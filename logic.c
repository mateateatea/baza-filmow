#include <stdio.h>
#include "logic.h"
#include <stdlib.h>
#include <string.h>
#include "io.h"

int wyswietl_menu(){
    int choice;
    printf("Witamy w bazie filmów!\n");
    printf("Wybierz opcję:\n");
    printf("1. Dodaj filmy\n");
    printf("2. Wyświetl filmy\n");
    printf("3. Usuń filmy\n");
    printf("4. Wpisz tytuł i wyświetl jego statystyki\n");
    printf("5. Sortuj\n");
    printf("6. Wyjdź\n");
    printf("7. Statystyki\n");
    printf("Twój wybór: \n");
    scanf("%d",&choice);
    return choice;
}

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
            getchar();
            printf("Wpisz tytuł: \n");
            fgets(tablica[*ile_filmow].tytul, 300, stdin);
            tablica[*ile_filmow].tytul[strcspn(tablica[*ile_filmow].tytul, "\n")] = '\0';
            printf("Wpisz gatuenk: \n");
            fgets(tablica[*ile_filmow].gatunek, 300, stdin);
            tablica[*ile_filmow].gatunek[strcspn(tablica[*ile_filmow].gatunek, "\n")] = '\0';
            tablica[*ile_filmow].ocena = wczytaj_int_z_zakresu(1,10,"ocenę: \n");
            tablica[*ile_filmow].obejrzany = wczytaj_int_z_zakresu(0,1,"czy obejrzany: \n");
            /*do{
                printf("Wpisz ocenę: \n");
                scanf(" %d", &tablica[*ile_filmow].ocena);
            }while(tablica[*ile_filmow].ocena<1 || tablica[*ile_filmow].ocena > 10);
            do{
                printf("Wpisz czy obejrzany: \n");
                scanf(" %d", &tablica[*ile_filmow].obejrzany);
            }while(tablica[*ile_filmow].obejrzany<0||tablica[*ile_filmow].obejrzany>1);*/
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
        for (usun;usun<*ile_filmow-1;usun++){
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
    getchar();
    fgets(tytul,100,stdin);
    tytul[strcspn(tytul,"\n")] = '\0';
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
    if (wynik > 0){
        return 1;
    }else{
        return 0;
    }
}

int porownaj_gatunek(struct Film *a, struct Film *b){
    int wynik; 
    wynik = strcmp(a->gatunek,b->gatunek);
    if (wynik > 1){
        return 1;
    }else{
        return 0;
    }
}

void statystyki(struct Film *tablica, int ile_filmow){
    printf("Wybierz którą statystykę chcesz zobaczyć: \n");
    printf("1. Średnia ocen z filmów. \n");
    printf("2. Których filmów jeszcze nie obejrzałeś. \n");
    int choice;
    int value = 0;
    float avg;
    int counter = 1;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i<ile_filmow;i++){
            value += tablica[i].ocena;
        }
        avg = (float)value / ile_filmow;
        printf("Twoja średnia wynosi: %.1lf\n", avg);
        break;
    case 2:
        printf("Nie obejrzałeś jeszcze: \n");
        for (int i = 0; i<ile_filmow;i++){
            if (tablica[i].obejrzany == 0){
                printf("%d. %s\n",counter, tablica[i].tytul);
                counter++;
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

int wczytaj_int_z_zakresu(int min, int max, char *typ){
    int number;
    do{
        printf("Wpisz %s", typ);
        scanf(" %d", &number);
    }while(number<min || number > max);
    return number;
}
#ifndef STRUCTS_H
#define STRUCTS_H

struct Film{
        char tytul[100];
        char gatunek[50];
        int ocena;
        int obejrzany;
    };

enum Opcje{
    DODAJ = 1,
    WYSWIETL = 2,
    USUN = 3,
    SZUKAJ = 4,
    SORTUJ = 5,
    WYJDZ = 7,
    STATYSTYKI = 6
};
#endif
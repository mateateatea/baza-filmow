#ifndef STRUCTS_H
#define STRUCTS_H

struct Film{
        char tytul[100];
        char gatunek[50];
        int ocena;
        int obejrzany;
    };

struct Wezel{
    struct Film film;
    struct Wezel *nastepny;
};

#endif
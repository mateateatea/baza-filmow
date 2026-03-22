#ifndef LOGIC_H
#define LOGIC_H

#include "structs.h"

void wyswietl_filmy(struct Film *tablica, int ile_filmow);
struct Film * dodaj_filmy(struct Film *tablica, int *ile_filmow, int *limit);
struct Film * usun_filmy(struct Film *tablica, int *ile_filmow);
void szukaj_filmu(struct Film *tablica, int ile_filmow);
void sortuj(struct Film *tablica, int *ile_filmow, int(*compare)(struct Film *,struct Film *));
int porownaj_ocene(struct Film *a,struct Film *b);
int porownaj_tytul(struct Film *a,struct Film *b);
int porownaj_gatunek(struct Film *a,struct Film *b);

#endif
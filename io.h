#ifndef IO_H
#define IO_H

#include "structs.h"

struct Film * wczytaj_filmy(struct Film *tablica, int *ile_filmow, int *limit);
void zapisz_filmy(struct Film *tablica, int ile_filmow);

#endif
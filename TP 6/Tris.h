#ifndef Tris_h
#define Tris_h
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Medicament {
    char nom[50];
    int code;
    int dateFabrication;
    int dateExpiration;
    float prix;
    int nbVendus;
    int stockrestant;
} Medicament;

int rechercheDichotomique(Medicament *tab, int n);
void saisir(Medicament *tab, int n);
void triBulles(Medicament *tab, int n);

#endif
#include "Tris.h"
#include <stdbool.h>
#include <stdio.h>

// correction parce que j'ai pas fait gaffe que c'était un mot et pas un tableau d'entiers

int rechercheDichotomique(Medicament *tab, int n) {
    int debut = 0, fin = n - 1, mil;
    int trouve = 0;

    char val[] = "paracetamol";

    while (debut <= fin && !trouve) {
        mil = (debut + fin) / 2;

        int cmp = strcmp(tab[mil].nom, val);

        if (cmp == 0) {
            trouve = 1;
        } else if (cmp < 0) {
            debut = mil + 1;
        } else {
            fin = mil - 1;
        }
    }

    if (trouve)
        return mil;
    else
        return -1;
}

// sous programeme de tri à bulle

void saisir(Medicament *tab, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n Medicament %d \n", i + 1);

        printf("Nom : ");
        scanf("%s", tab[i].nom);

        printf("Code : ");
        scanf("%d", &tab[i].code);

        printf("Date fabrication (AAAAMMJJ) : ");
        scanf("%d", &tab[i].dateFabrication);

        printf("Date expiration (AAAAMMJJ) : ");
        scanf("%d", &tab[i].dateExpiration);

        printf("Prix : ");
        scanf("%f", &tab[i].prix);

        printf("Nombre vendus : ");
        scanf("%d", &tab[i].nbVendus);

        printf("Stock restant : ");
        scanf("%d", &tab[i].stockrestant);
    }
}

void triBulles(Medicament *tab, int n) {
    Medicament temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j].dateExpiration > tab[j + 1].dateExpiration) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}


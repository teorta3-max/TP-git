#include "Tris.h"
#include <stdbool.h>
#include <stdio.h>

//déja codage de la fonction de recherche dichotomique

int recherche_dichotomique(int t[], int taille, int val) {
    int debut = 0;
    int fin = taille - 1;
    int mil;

    while (debut <= fin) {
        mil = (debut + fin) / 2;

        if (t[mil] == val) {
            return mil;
        } else if (val > t[mil]) {
            debut = mil + 1;
        } else {
            fin = mil - 1;
        }
    }

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


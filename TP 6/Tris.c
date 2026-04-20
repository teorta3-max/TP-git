#include "Tris.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
            if (strcmp(tab[j].nom, tab[j + 1].nom) > 0) {
            temp = tab[j];
            tab[j] = tab[j + 1];
            tab[j + 1] = temp;//petit probleme
            }
        }
    }
}

Medicament plusCher(Medicament *tab, int n) {
    Medicament max = tab[0];

    for (int i = 1; i < n; i++) {
        if (tab[i].prix > max.prix) {
            max = tab[i];
        }
    }

    return max;
}

float tauxVente(Medicament *tab, int n) {
    int totalVendus = 0;
    int totalStock = 0;

    for (int i = 0; i < n; i++) {
        totalVendus += tab[i].nbVendus;
        totalStock += tab[i].stockrestant;
    }

    return (float)totalVendus / (totalVendus + totalStock);
}

void trierListe(Node *head) {
    Node *i, *j;
    Medicament temp;

    for (i = head; i != NULL; i = i->suivant) {
        for (j = i->suivant; j != NULL; j = j->suivant) {
            if (i->data.code > j->data.code) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
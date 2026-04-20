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

int main() {
    int t[] = {1, 3, 5, 7, 9, 11};
    int taille = sizeof(t) / sizeof(t[0]);
    int val;

    printf("Saisir la valeur à rechercher : ");
    scanf("%d", &val);

    int resultat = recherche_dichotomique(t, taille, val);

    if (resultat != -1) {
        printf("La valeur %d est au rang %d\n", val, resultat);
    } else {
        printf("La valeur %d n'est pas dans le tableau\n", val);
    }

    return 0;
}
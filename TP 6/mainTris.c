#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Tris.h"

int main() {

    Medicament *tab;

    tab = (Medicament *)malloc(80 * sizeof(Medicament));

    if (tab == NULL) {
        printf("Probleme\n");
        return 1;
    }

    saisir(tab, 80);
    triBulles(tab, 80);

    printf("\nTableau trie\n");

    int pos = rechercheDichotomique(tab, 80);

    if (pos != -1) {
        printf("Le medicament paracetamol est au rang %d\n", pos);
    }else {
        printf("Medicament non trouve\n");
    }   
    free(tab);

    return 0;
    Medicament m = plusCher(tab, 80);
    printf("Le medicament le plus cher est %s avec %.2f $\n", m.nom, m.prix);

    printf("Taux de vente = %.2f\n", tauxVente(tab, 80));
}

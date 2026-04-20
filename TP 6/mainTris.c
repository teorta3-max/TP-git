#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    free(tab);

    return 0;
}

#include <stdio.h>

int main() {
    int x = 10;
    if (x == 5) {
        printf("x vaut 5\n");
    }
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// si x = 5 est une affectation et non une comparaison. Pour comparer, il faut utiliser l'opérateur '=='.

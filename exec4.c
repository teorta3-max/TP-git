#include <stdio.h>

int main() {
    int i = 0;
    while (i < 10) {
        printf("%d\n", i);
    }
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// La variable 'i' n'est jamais incrémentée dans la boucle while, ce qui entraîne une boucle infinie lors de l'exécution.
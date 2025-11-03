#include <stdio.h>

int main() {
    int x;
    int y = x + 5;  
    printf("%d\n", y);
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// La variable 'x' est utilisée sans avoir été initialisée avec une valeur, ce qui conduit à un comportement indéfini lors de l'exécution.
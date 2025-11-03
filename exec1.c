#include <stdio.h>

int main() {
    int a = 2;
    int b = 0;
    int c = a / b;  // crash / comportement indéfini
    printf("%d\n", c);
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Interdiction de division par zéro qui provoque un comportement indéfini lors de l'exécution.
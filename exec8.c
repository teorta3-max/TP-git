#include <stdio.h>

int main() {
    int t[3] = {10, 20, 30};
    int i = 0;
    printf("%d\n", t[i]); 
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier
// L'accès à l'élément t[-1] est hors des limites du tableau, ce qui peut entraîner un comportement indéfini lors de l'exécution.
#include <stdio.h>

// ici le comilateur ne dit malheureusement rien mais il devrait,
// executer pour essayer de comprendre ce qu'il se passe 
int main() {
    int tableau[5];
    int i = 12;
    for (int j = 0; j < 6; j++)
    {
        tableau[j] = 1;
    }
    printf("OK %d\n", tableau[5]);
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Il y a un dépassement de tableau dans la boucle for. Elle demande 6 éléments (j de 0 à 5) alors que le tableau n'en a que 5 (indices 0 à 4).
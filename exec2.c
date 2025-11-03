#include <stdio.h>

int main() {
    int tab[5];
    
    for (int i = 0; i < 10; i++) {
        tab[i] = i;  
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n",tab[i]);  
    }
    printf("fait\n");
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Il y a un dépassement de tableau dans la boucle for. Elle demande 10 éléments (i de 0 à 9) alors que le tableau n'en a que 5 (indices 0 à 4).
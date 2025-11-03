#include <stdio.h>

int main() {
    char nom[10];
    printf("Nom ? ");
    scanf("%s", nom); 
    printf("Bonjour %s\n", nom);
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Le tableau 'nom' est trop petit pour contenir le nom entré par l'utilisateur, ce qui peut provoquer un dépassement de tampon lors de l'exécution.
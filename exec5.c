#include <stdio.h>

int main() {
    char s[5];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'y';
    s[3] = '!';
    s[4] = '\0';  // Ajout du caractère nul pour terminer la chaîne
    printf("%s\n", s); 
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Interdiction d'utiliser des chaînes de caractères non terminées par le caractère nul '\0', ce qui peut entraîner un comportement indéfini lors de l'exécution.

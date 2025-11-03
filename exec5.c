#include <stdio.h>

int main() {
    char s[5];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'y';
    s[3] = '!';
    printf("%s\n", s); 
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Il faut des guillemets pour initialiser une chaîne de caractères.

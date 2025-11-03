#include <stdio.h>

int main() {
    printf("Hello world\n");
    return 0;
}
// Affiche l'erreur de compilation suivante :
//compil1.c: In function 'main':                                                                                                     
//compil1.c:5:5: error: expected ';' before 'return'                                                                                 
//     return 0;
//     ^~~~~~
// Il manque un point virgule à la fin de la ligne précédente.
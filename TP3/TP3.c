#include <stdio.h>

int main() {
    int taille;

    printf("Saisir une taille n (5 <= n <= 10) : ");
    scanf("%d", &taille);
    while (taille < 5 || taille > 10) {
        printf("Erreur : la taille doit etre comprise entre 5 et 10.\n");
        printf("Saisir une taille n (5 <= n <= 10) : ");
        scanf("%d", &taille);
    }
    int width = taille * taille;
    int max_height = 3 * taille - 1;
    char img[100][100];
    
    
}
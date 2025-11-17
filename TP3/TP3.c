#include <stdio.h>

// Exercice 1
int main(){
    int taille;
    printf(" saisir une taille n (5 <= n >= 10):");
    scanf("%d",&taille);
    if (taille > 10 || taille < 5){
        printf("La taille doit etre superieur ou égale à 5 et inférieur ou égal à 10");
    }
    int width = taille * taille;
    int max_height = 3 * taille - 1;
    char img[100][100];

    
}
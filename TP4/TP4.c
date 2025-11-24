#include <stdio.h>

//Étape 1 : Fonction afficherMenu

void afficherMenu() {
    printf("===== GESTION DES NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher la moyenne d'un eleve\n");
    printf("5. Afficher la moyenne generale\n");
    printf("6. Afficher la meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}
// Étape 2 : Fonction lireChoix 

int lireChoix() {
    int choix;
    scanf("%d", &choix);
    printf("Votre choix: %d\n", choix);
    return choix;
}

//Étape 3 : Fonction saisirNombreEleves 

int saisirNombreEleves() {
    int nombre;
    printf("Entrer le nombre d'eleves(1 a 30): ");
    scanf("%d", &nombre);
    while (nombre < 1 || nombre > 30) {
        printf("valeur invalide.\n");
        printf("Entrer le nombre d'eleves(1 a 30): ");
        scanf("%d", &nombre);
    }
    printf("Nombre d'eleves(1 a 30): %d\n", nombre);
    return nombre;
}

int main() {
    afficherMenu();
    lireChoix();
    saisirNombreEleves();
    return 0;
}
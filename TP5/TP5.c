#include "TP5.h"

void Menu() {
    printf("==============================\n");
    printf("Suivi de consomation\n");
    printf("==============================\n");
    printf("1. Ajouter une consomationn\n");
    printf("2. Affiche le resume du jour\n");
    printf("3. Sauvegarder et quitter\n");
    printf("Votre choix: ");
}

int lireChoix() {
    int choix;
    scanf("%d", &choix);
    return choix;
}
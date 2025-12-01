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

void initialiser(int conso[]) {
    for (int i = 0; i < 7; i++) {
        conso[i] = 0;
    }
}

void ajouterConsommation(int conso[]) {
    printf("Quelle categorie voulez vous modifier ?\n");
    printf("1. Eau 💧\n");
    printf("2. Cafe ☕\n");
    printf("3. Bonbons 🍬\n");
    printf("4. Gateau 🍰\n");
    printf("5. Legumes 🥦\n");
    printf("6. Fruits 🍎\n");
    printf("7. Proteines 🍗\n");
    printf("Votre choix:  ");
    int reponse;
    scanf("%d", &reponse);
    if (reponse < 0 || reponse > 7) {
        printf("Il n'y en a pas, ressayez.\n");
        return;
    }
    printf("Combien d'unites ajouter ?");
    int quantite;
    scanf("%d", &quantite);
    conso[reponse] += quantite;
    printf("Consommation mise a jour.");
}
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
    if (reponse < 1 || reponse > 7) {
        printf("Il n'y en a pas, ressayez.\n");
        return;
    }
    printf("Combien d'unites ajouter ? ");
    int quantite;
    scanf("%d", &quantite);
    conso[reponse - 1] += quantite;
    printf("Consommation mise a jour.\n");
}

void afficheResume(int conso[]) {
    const char* emojiBonbons[] = {"😊", "😐", "😟", "😢"};
    const char* emojiVegFruits[] = {"😢", "😐", "😊"};
    printf("========== Resume du jour ==========\n");
    printf("Eau       💧 : %d\n", conso[0]);
    printf("Cafe      ☕ : %d\n", conso[1]);
    printf("Bonbons   🍬 : %d %s\n", conso[2], emojiBonbons[humeurBonbons(conso[2])]);
    printf("Gateau    🍰 : %d\n", conso[3]);
    printf("Legumes   🥦 : %d %s\n", conso[4], emojiVegFruits[humeurLegumes(conso[4])]);
    printf("Fruits    🍎 : %d %s\n", conso[5], emojiVegFruits[humeurFruits(conso[5])]);
    printf("Proteines 🍗 : %d\n", conso[6]);
    printf("====================================\n");
}

int charger(int conso[]) {
    FILE* file = fopen("consommation.txt", "r");
    if (file == NULL){
        return 0;
    }
    for (int i = 0; i < 7; i++) {
        if (fscanf(file, "%d", &conso[i]) != 1) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

int sauvegarder(int conso[]) {
    FILE* file = fopen("consommation.txt", "w");
    if (file == NULL)
    {
        return 0;
    } 
    for (int i = 0; i < 7; i++) {
        fprintf(file, "%d ", conso[i]);
    }
    fprintf(file, "\n");
    fclose(file);
    return 1;   
}

int humeurBonbons(int nb) {
    if (nb >= 0 && nb <= 3) return 0;
    if (nb >= 4 && nb <= 7) return 1;
    if (nb >= 8 && nb <= 12) return 2;
    return 3;
}

int humeurLegumes(int nb) {
    if (nb >= 0 && nb <= 2) return 0;
    if (nb >= 3 && nb <= 5) return 1;
    return 2;
}

int humeurFruits(int nb) {
    if (nb >= 0 && nb <= 1) return 0;
    if (nb >= 2 && nb <= 3) return 1;
    return 2;
}
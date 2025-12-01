#include "TP5.h"
#include <time.h>

void Menu() {
    printf("==============================\n");
    printf("Suivi de consommation\n");
    printf("==============================\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le résumé du jour\n");
    printf("3. Afficher objectifs et score\n");
    printf("4. Sauvegarder la journée\n");
    printf("5. Afficher résumé du fichier\n");
    printf("0. Quitter\n");
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
    const char* emojiBonbons[] = {"😇", "😊", "😞", "😈"};
    const char* emojilegume[] = {"😭", "😊", "😎"};
    const char* emojifruits[] = {"🥲", "😊", "😄"};
    printf("========== Resume du jour ==========\n");
    printf("Eau       💧 : %d ", conso[0]);
    afficherBarre(conso[0], 10);
    printf("\n");
    printf("Cafe      ☕ : %d ", conso[1]);
    afficherBarre(conso[1], 5);
    printf("\n");
    printf("Bonbons   🍬 : %d %s ", conso[2], emojiBonbons[humeurBonbons(conso[2])]);
    afficherBarre(conso[2], 10);
    printf("\n");
    printf("Gateau    🍰 : %d ", conso[3]);
    afficherBarre(conso[3], 5);
    printf("\n");
    printf("Legumes   🥦 : %d %s ", conso[4], emojilegume[humeurLegumes(conso[4])]);
    afficherBarre(conso[4], 10);
    printf("\n");
    printf("Fruits    🍎 : %d %s ", conso[5], emojifruits[humeurFruits(conso[5])]);
    afficherBarre(conso[5], 10);
    printf("\n");
    printf("Proteines 🍗 : %d ", conso[6]);
    afficherBarre(conso[6], 10);
    printf("\n");
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
    if (file == NULL) {
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
    if (nb >= 0 && nb <= 3) {
        return 0;
    }
    if (nb >= 4 && nb <= 7){
        return 1;
    }
    if (nb >= 8 && nb <= 12){
        return 2;
    }
    return 3;
}

int humeurLegumes(int nb) {
    if (nb >= 0 && nb <= 5) {
        return 0;
    }
    if (nb >= 6 && nb <= 10){
        return 1;
    }
    return 2;
}

int humeurFruits(int nb) {
    if (nb >= 0 && nb <= 4) {
        return 0;
    }
    if (nb >= 5 && nb <= 10){
        return 1;
    }
    return 2;
}

void afficherBarre(int valeur, int max) {
    if (max <= 0) max = 1;
    if (valeur < 0) valeur = 0;
    if (valeur > max) valeur = max;
    int casesPleines = (valeur * 10) / max;
    for (int i = 0; i < 10; i++) {
        if (i < casesPleines) {
            printf("█");
        } else {
            printf("░");
        }
    }
}

void afficherObjectifsEtScore(int conso[], int objectifs[]) {
    char* categories[] = {"Eau", "Café", "Bonbons", "Gâteaux", "Légumes", "Fruits", "Protéines"};
    printf("\nObjectifs:\n");

    for (int i = 0; i < 7; i++) {

        if (i == 1 || i == 2 || i == 3) {
            printf("%s : %d (pas d'objectif)\n", categories[i], conso[i]);
        } 
        else {
            const char* symbole = (conso[i] >= objectifs[i]) ? "✅" : "❌";
            printf("%s : %d %s\n", categories[i], conso[i], symbole);
        }
    }

    int score = calculerScoreSante(conso, objectifs);
    printf("Score de santé: %d/100\n", score);
}

int calculerScoreSante(int conso[], int objectifs[]) {
    int score = 50;
    if (conso[0] >= objectifs[0]) score += 10;
    if (conso[4] >= objectifs[4]) score += 10;
    if (conso[5] >= objectifs[5]) score += 10; 
    if (conso[6] >= objectifs[6]) score += 10;
    if (conso[2] > 5) { 
        int malus = (conso[2] - 5) * 1;
        if (malus > 15) malus = 15;
        score -= malus;
    }
    if (conso[1] > 3) { 
        int malus = (conso[1] - 3) * 2;
        if (malus > 20) malus = 20;
        score -= malus;
    }
    if (score < 0) score = 0;
    if (score > 100) score = 100;
    return score;
}

int sauvegarderParJour(int conso[]) {
    FILE* file = fopen("consommation.txt", "a");
    if (file == NULL) {
        return 0;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(file, "%04d-%02d-%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    for (int i = 0; i < 7; i++) {
        fprintf(file, "%d ", conso[i]);
    }
    fprintf(file, "\n");
    fclose(file);
    return 1;
}

void afficherResumeFichier(int afficherTous) {
    FILE* file = fopen("consommation.txt", "r");
    if (!file) {
        printf("Aucune donnée trouvée.\n");
        return;
    }

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), file)) {
        int conso[7];
        char date[11];

        if (sscanf(ligne, "%10s %d %d %d %d %d %d %d",
                   date, &conso[0], &conso[1], &conso[2],
                   &conso[3], &conso[4], &conso[5], &conso[6]) != 8) {
            continue;
        }

        if (afficherTous || feof(file)) {
            printf("===== Résumé du %s =====\n", date);
            afficheResume(conso);
        }
    }

    fclose(file);
}
#include <stdio.h>

int main() {
    //Exercice 1
    int secondes;
    printf("Entrez un nombre de secondes : ");
    scanf("%d", &secondes);
    int heures = secondes / 3600;
    int minutes = (secondes % 3600) / 60;
    int sec = secondes % 60;
    printf("%d secondes = %d heures, %d minutes et %d secondes\n", secondes, heures, minutes, sec);

    //Exercice 2
    int C;
    int t;
    int n;
    printf("Quelle est le montant de votre pret ? ");
    scanf("%d", &C);
    printf("Quelle est le taux d'interet annuel? ");
    scanf("%d", &t);
    printf("Sur combien d'annees ? ");
    scanf("%d", &n);
    float mensualite = (C * ((t) / 12)) / (1 - (1 +t/12) * pow(-n+12));
    printf("Votre mensualite est de : %.2f\n", mensualite);
    
    //Exercice 3
    // Jeu du pendu
    char mot[20];
    char lettre;
    int essais = 8;
    printf("Entrez le mot a deviner (max 20 lettres) : ");
    scanf("%s", mot);
    char mot_cache[20];
    for (int i = 0; i < strlen(mot); i++) {
        mot_cache[i] = '_';
    }
    mot_cache[strlen(mot)] = '\0';
    while (essais > 0) {
        printf("Mot a deviner : %s\n", mot_cache);
        printf("Il vous reste %d essais. Entrez une lettre : ", essais);
        scanf(" %c", &lettre);
        int trouve = 0;
        for (int i = 0; i < strlen(mot); i++) {
            if (mot[i] == lettre) {
                mot_cache[i] = lettre;
                trouve = 1;
            }
        }
        if (!trouve) {
            essais--;
        }
        if (strcmp(mot, mot_cache) == 0) {
            printf("Felicitation ! Vous avez trouve le mot : %s\n", mot);
            break;
        }
    }
}
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
    printf("Entrez un mot a deviner (max 20 lettres) : ");
    scanf("%s", mot);
    int longueur = strlen(mot);
    char lettresDevinees[20] = {0};
    int nbLettresDevinees = 0;
    int nbErreurs = 0;
    int maxErreurs = 6;
}
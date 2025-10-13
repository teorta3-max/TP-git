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

    char motsdecouvert = "";
    char mots =  "Anticonstitutionellement";
    char lettre;
    char mort[100] = "";
    char mort[1] = "\n\n\n\n\n\n\n-------\n";
    char mort[2] = "\n |\n |\n |\n |\n |\n |\n-------\n" ;
    char mort[3] = " -------\n |      |\n |\n |\n |\n |\n-------\n" ;
    char mort[4] = " -------\n |      |\n |     O\n |\n |\n |\n-------\n" ;
    char mort[5] = " -------\n |      |\n |     O\n |     |\n |\n |\n-------\n";
    char mort[6] = " -------\n |      |\n |     O\n |    /|\\\n |\n |\n-------\n";
    char mort[7] = " -------\n |      |\n |     O\n |    /|\\\n |    / \\\n |\n-------\n" ;
    int essais = 0;
    while (essais < 7) {
        printf("entrez une lettre : ");
        scanf(" %c", &lettre);
        if (strchr(mots, lettre)) {
            strcat(motsdecouvert, lettre);
        } else {
            essais++;
            printf("%c\n", mort[essais]);
        }
        printf("%s\n", motsdecouvert);
    }
    if (essais == 7) {
        printf("Vous avez perdu ! Le mot etait : %s\n", mots);
    } else {
        printf("Vous avez gagne !\n");
    }
    return 0;
}
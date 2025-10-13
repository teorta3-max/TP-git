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

    char motsdécouvert = "";
    char mots =  "Anticonstitutionellement";
    char lettre;
    int longueur = len(mots);
    printf("Le mot %s a une longueur de %d caracteres\n", mots, longueur);
    while (mots != motsdécouvert) {
        printf("Entrez une lettre : ");
        scanf(" %c", &lettre);
        for (int i = 0; i < longueur; i++) {
            if (mots[i] == lettre) {
                motsdécouvert[i] = lettre;
            }
        }
    printf("Mot decouvert : %s\n", motsdécouvert);
    printf("Il vous reste %d lettres a decouvrir\n", longueur - len(motsdécouvert));
    }

}
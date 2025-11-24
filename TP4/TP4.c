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
    return nombre;
}

// Étape 4 : Fonction saisirNotes 

int saisirNotes(int nombreEleves) {
    float notes[30][3];
    printf("Saisir des notes pour %d eleve et 3 controle.\n", nombreEleves);
    for (int i = 0; i < nombreEleves; i++) {
        printf("Eleve %d :\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Entrer la note %d: ", j + 1);
            scanf("%f", &notes[i][j]);
            if (notes[i][j] < 0 || notes[i][j] > 20) {
                printf("valeur invalide.\n");
                j--;
            }
        }
    }
}

int main() {
    afficherMenu();
    lireChoix();
    int a = saisirNombreEleves();
    saisirNotes(a);
    return 0;
}
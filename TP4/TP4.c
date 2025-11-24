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

int saisirNotes(int nombreEleves,float tab[30][3]) {
    printf("Saisir des notes pour %d eleve et 3 controle.\n", nombreEleves);
    for (int i = 0; i < nombreEleves; i++) {
        printf("Eleve %d :\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Entrer la note %d: ", j + 1);
            scanf("%f", &tab[i][j]);
            if (tab[i][j] < 0 || tab[i][j] > 20) {
                printf("valeur invalide.\n");
                j--;
            }
        }
    }
}

// Étape 5 : Fonction afficherNotes 

int afficherNotes(int nb , float tab[30][3]){
    printf("Tableau des notes\n");
    printf("Eleve\tC1\tC2\tC3\n");
    for (int i = 0; i < nb ; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", tab[i][j]);
        }
        printf("\n");
    }
}

// Etape 6 : Fonction calculerMoyenneEleve 

float calculerMoyenneEleve(int indiceEleve, float tab[30][3]) {
    float somme = 0;
    for (int j = 0; j < 3; j++) {
        somme += tab[indiceEleve][j];
    }
    return somme / 3.0;
}

int main() {
    afficherMenu();
    lireChoix();
    float notes[30][3];
    int a = saisirNombreEleves();
    saisirNotes(a,notes);
    afficherNotes(a,notes);
    printf("Entrer l'indice de l'eleve (1 a %d): ", a);
    int b;
    scanf ("%d", &b);
    printf("moyene de l'eleve %d : %.2f\n", b, calculerMoyenneEleve(b-1,notes));
}
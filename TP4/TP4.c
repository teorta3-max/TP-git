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

// Étape 7 : Fonction calculerMoyenneGenerale 

float calculerMoyenneGenerale(int nombreEleves, float tab[30][3]) {
    float sommeMoyennes = 0;
    for (int i = 0; i < nombreEleves; i++) {
        sommeMoyennes += calculerMoyenneEleve(i, tab);
    }
    return sommeMoyennes / nombreEleves;
}

//Étape 8 : Fonction trouverMeilleureNoteControle 

float trouverMeilleureNoteControle(int indiceControle, int nombreEleves, float tab[30][3]) {
    float meilleureNote = -1;
    for (int i = 0; i < nombreEleves; i++) {
        if (tab[i][indiceControle] > meilleureNote) {
            meilleureNote = tab[i][indiceControle];
        }
    }
    return meilleureNote;
}

//Étape 9 : Fonction afficherMeilleuresNotes 

void afficherMeilleuresNotes(int nombreEleves, float tab[30][3]) {
    for (int j = 0; j < 3; j++) {
        float meilleureNote = trouverMeilleureNoteControle(j, nombreEleves, tab);
        printf("Meilleure note du controle %d : %.2f\n", j + 1, meilleureNote);
    }
}

// Fonction main


int main() {
    afficherMenu();
    lireChoix();
    float notes[30][3];
    int a;
    if (lireChoix() == 1) {
        a = saisirNombreEleves();
    }
    else if (lireChoix == 2) {
        saisirNotes(a,notes);
    }
    else if (lireChoix == 3) {
        afficherNotes(a,notes);
    }
    else if (lireChoix == 4) {
        int b;
        printf("Entrer l'indice de l'eleve (1 a %d): ", a);
        scanf ("%d", &b);
        printf("Moyene de l'eleve %d : %.2f\n", b, calculerMoyenneEleve(b-1,notes));
    }
    else if (lireChoix == 5) {
        printf("Moyene generale de la classe: %.2f\n", calculerMoyenneGenerale(a,notes));
    }
    else if (lireChoix == 6) {
        int c;
        printf("Entrer l'indice du controle (1 a 3): ");
        scanf ("%d", &c);
        printf("La meilleure note du controle : %.2f\n", trouverMeilleureNoteControle(c-1,a,notes));
    }
    else {
        printf("Quitter le programme.\n");
    }
}
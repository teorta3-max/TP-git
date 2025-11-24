#include <stdio.h>

// Etape 1 : Afficher le menu 

void afficher_menu() {
    printf("=== BANQUE - DISTRIBUTEUR ===\n");
    printf("1. -Faire un retrait\n");
    printf("2. -Quitter\n");
}

//Etape 2 : Demander un montant 

int saisir_montant() {
    int montant;
    printf("Montant a retirer: ");
    scanf("%d", &montant);
    return montant;
}

// Etape 3 : Vérifier la validité

int montant_valide(int montant) {
    if (montant <= 0 || montant > 1000 || montant % 5 != 0) {
        return 0;
    }
    return 1;
}

// Etape 4 : Calculer et afficher les billets

void calcul_distribution(int montant) {
    int billets_50 = montant / 50;
    montant %= 50;
    int billets_20 = montant / 20;
    montant %= 20;
    int billets_10 = montant / 10;
    montant %= 10;
    int billets_5 = montant / 5;

    printf("Distribution des billets :\n");
    if (billets_50 > 0){
        printf("Billets de 50 euro : %d\n", billets_50);
    }
    if (billets_20 > 0){
        printf("Billets de 20 euro : %d\n", billets_20);
    } 
    if (billets_10 > 0){
        printf("Billets de 10 euro : %d\n", billets_10);
    }
    if (billets_5 > 0){
       printf("Billets de 5 euro : %d\n", billets_5); 
    } 
}


int main() {
    afficher_menu();
    int choix;
    while (choix != 2) {
        printf("Choisissez une option: ");
        scanf("%d", &choix);
        if (choix == 1) {
            int montant = saisir_montant();
            if (montant_valide(montant)) {
                calcul_distribution(montant);
            } else {
                printf("Montant invalide. Veuillez reessayer.\n");
            }
        } else if (choix == 2) {
            printf("Merci d'avoir utilise le distributeur. Au revoir!\n");
        } else {
            printf("Option invalide. Veuillez reessayer.\n");
        }
        afficher_menu();
    }
    
    
}

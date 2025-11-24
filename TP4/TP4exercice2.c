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


int main() {
    afficher_menu();
    int choix;
    scanf("%d", &choix);
    if (choix == 1) {
        int x = saisir_montant();
    } 
    else {
        
    }
}

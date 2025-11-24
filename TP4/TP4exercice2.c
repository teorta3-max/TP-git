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

int main() {
    //On verra quand on aurra toutes les fonctions
}

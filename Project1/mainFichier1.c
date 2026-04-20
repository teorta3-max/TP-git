#include <stdio.h>
#include "Fichier1.h"
#include "cas.h"

int main() {
	filedattente* file = ceerfile();
	if (file == NULL) {
		return 1; // Erreur d'allocation de mémoire
	}
	printf("Bienvenue dans le système de gestion de file d'attente !\n");
	printf("Veuillez choisir une option :\n");
	printf("1. Ajouter un groupe à la file d'attente\n");
	printf("2. Déplacer le groupe en tête de la file d'attente à la fin\n");
	printf("3. Afficher la file d'attente\n");
	printf("4. Quitter\n");
	while (1) {
		int choix = 1;//menu();
		switch (choix) {
			case 1:
				ajouterGpe(NULL,file);
				break;
			case 2:
				deplacerGroupeAlafin(file);
				break;
			case 3:
				afficherFile(file);
				break;
			case 4:
				printf("Au revoir !\n");
				return 0;
			default:
				printf("Choix invalide. Veuillez réessayer.\n");
		}
	}

	return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include "Fichier1.h"

filedattente* ceerfile()
{
	filedattente* file = malloc(sizeof(filedattente));
	if (file == NULL) {
		printf("Erreur d'allocation de mémoire pour la file d'attente.\n");
		return NULL;
	}
	file->premier = NULL;
	file->dernier = NULL;

	return file;
}

Groupe * creerGpe(int taille)
{
	Groupe* gpe = malloc(sizeof(Groupe));
	if (gpe == NULL) {
		printf("Erreur d'allocation de mémoire pour le groupe.\n");
		return NULL;
	}
	gpe->taille = taille;
	gpe->suivant = NULL;

	return gpe;
}

void ajouterGpe(Groupe * gpe, filedattente* file)
{
	if (file == NULL || gpe == NULL) {
		printf("La file d'attente n'existe pas.\n");
		return NULL;
	}
	if (file->dernier == NULL) {
		file->premier = gpe;
		file->dernier = gpe;
	} else {
		file->dernier->suivant = gpe;
		file->dernier = gpe;
	}
	return gpe;
}

void deplacerGroupeAlafin(filedattente* file)
{
	if (file == NULL) {
		printf("La file d'attente n'existe pas.\n");
		return;
	}
	if (file->premier == NULL) {
		printf("La file d'attente est vide.\n");
		return;
	}
	if (file->premier == NULL) {
		return;
	}
	file->dernier->suivant = file->premier;
	file->dernier = file->dernier->suivant;

	file->premier = file->premier->suivant;
	file->dernier->suivant = NULL;
}

void afficherFile(filedattente* file) {
	if (file == NULL) {
		printf("La file d'attente n'existe pas.\n");
		return;
	}
	Groupe* current = file->premier;
	while (current != NULL) {
		printf("Groupe de taille: %d\n", current->taille);
		current = current->suivant;
	}
}

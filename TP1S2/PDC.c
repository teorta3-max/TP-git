#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PDC.h"

/* ===============================
   ETAPE 1 : Lecture des données
   =============================== */
Eleve* demander(int *nbEleves,
                int *nbRangees,
                int *nbTables)
{
    char fichier[100];
    char prenom[100], nom[100];
    FILE *f;

    printf("Nombre de rangees : ");
    scanf("%d", nbRangees);

    printf("Nombre de tables par rangee : ");
    scanf("%d", nbTables);

    printf("Nom du fichier (.txt) : ");
    scanf("%s", fichier);

    f = fopen(fichier, "r");
    if (!f) {
        printf("Erreur ouverture fichier\n");
        exit(1);
    }

    Eleve *eleves = NULL;
    *nbEleves = 0;

    while (fscanf(f, "%s %s", prenom, nom) == 2) {

        eleves = realloc(eleves,
                         (*nbEleves + 1) * sizeof(Eleve));

        eleves[*nbEleves].prenom =
            malloc(strlen(prenom) + 1);
        eleves[*nbEleves].nom =
            malloc(strlen(nom) + 1);

        strcpy(eleves[*nbEleves].prenom, prenom);
        strcpy(eleves[*nbEleves].nom, nom);

        (*nbEleves)++;
    }

    fclose(f);

    /* Mélange aléatoire */
    for (int i = *nbEleves - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Eleve temp = eleves[i];
        eleves[i] = eleves[j];
        eleves[j] = temp;
    }

    return eleves;
}


/* =========================================
   ETAPE 2, 3 et 4 : Création + Placement + Affichage
   ========================================= */
void creerSalle(Eleve *eleves,
                int nbEleves,
                int nbRangees,
                int nbTables)
{
    int total = nbRangees * nbTables;
    Place *salle = malloc(total * sizeof(Place));

    /* ETAPE 2 : Initialisation des places */
    for (int r = 0; r < nbRangees; r++) {
        for (int t = 0; t < nbTables; t++) {

            int pos = r * nbTables + t;

            salle[pos].numderangee = r;
            salle[pos].numerodetable = t;
            salle[pos].indicateuroccupee = 0;
        }
    }

    /* ETAPE 3 : Placement avec contraintes */

    int indexEleve = 0;

    /* 1er passage : tables paires (espacement maximum) */
    for (int r = 0; r < nbRangees && indexEleve < nbEleves; r++) {
        for (int t = 0; t < nbTables && indexEleve < nbEleves; t += 2) {

            int pos = r * nbTables + t;

            salle[pos].eleve = eleves[indexEleve++];
            salle[pos].indicateuroccupee = 1;
        }
    }

    /* 2e passage : tables impaires */
    for (int r = 0; r < nbRangees && indexEleve < nbEleves; r++) {
        for (int t = 1; t < nbTables && indexEleve < nbEleves; t += 2) {

            int pos = r * nbTables + t;

            salle[pos].eleve = eleves[indexEleve++];
            salle[pos].indicateuroccupee = 1;
        }
    }

    /* ETAPE 4 : Affichage */
    printf("\n===== PLAN FINAL =====\n\n");

    for (int r = 0; r < nbRangees; r++) {

        printf("Rangee %d :\n", r + 1);

        for (int t = 0; t < nbTables; t++) {

            int pos = r * nbTables + t;

            if (salle[pos].indicateuroccupee)
                printf("[%-10s %-10s] ",
                       salle[pos].eleve.prenom,
                       salle[pos].eleve.nom);
            else
                printf("[     VIDE     ] ");
        }

        printf("\n\n");
    }

    /* Libération mémoire */
    for (int i = 0; i < nbEleves; i++) {
        free(eleves[i].prenom);
        free(eleves[i].nom);
    }

    free(eleves);
    free(salle);
}
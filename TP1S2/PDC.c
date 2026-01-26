#include "PDC.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demander(int *rangees,int *tables,char nomdufichier[]){

    printf("Quel est le nombre de rangees?\n");
    scanf("%d",rangees);
    printf("Quel est le nombre de tables?\n");
    scanf("%d",tables);
    printf("Quel est le nom du fichier\n");
    scanf("%s",nomdufichier);

    FILE * fichier = fopen(nomdufichier, "r");

    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nomdufichier);
    }

    fclose(fichier);
}
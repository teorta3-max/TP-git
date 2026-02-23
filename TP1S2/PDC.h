#ifndef PDC
#define PDC
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct {
    char *prenom;
    char *nom;// avec pointeur c mieux
} Eleve;

typedef struct
{
    int numderangee;
    int numerodetable;
    int indicateuroccupee;
    Eleve eleve;// C mieux que de faire un tableau de char pour le nom et le prenom, on peut faire une structure eleve qui contient les deux et ensuite l'inclure dans la structure place, comme ça on peut facilement accéder au nom et au prenom de l'élève qui occupe la place.
}Place;

Eleve * demander(int *nbEleves,int *nbRangees,int *nbTables);

void creerSalle(Eleve *eleves,int nbEleves,int nbRangees,int nbTables);

#endif
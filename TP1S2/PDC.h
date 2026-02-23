#ifndef PDC
#define PDC
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct
{
    char prenom[50];
    char nom[50];
}Eleve;

typedef struct
{
    int numderangee;
    int numerodetable;
    int indicateuroccupee;
}Place;

void demander(int *rangees,int *tables,char nomdufichier[]);
void creesalle(int rangees,int tables,char nomdufichier[],int tab[rangees][tables]);

#endif
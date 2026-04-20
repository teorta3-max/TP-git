#ifndef Tris_h
#define Tris_h
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Medicament {
    char nom[50];
    int code;
    int dateFabrication;
    int dateExpiration;
    float prix;
    int nbVendus;
    int stockrestant;
} Medicament;

int rechercheDichotomique(Medicament *tab, int n);
void saisir(Medicament *tab, int n);
void triBulles(Medicament *tab, int n);
Medicament plusCher(Medicament *tab, int n);
float tauxVente(Medicament *tab, int n);

typedef struct Node {
    Medicament data;
    struct Node *suivant;
} Node;

void trierListe(Node *head);


// Exercice 2

typedef struct {
    char nom[50];
    char prenom[50];
    int matricule;
    float moyenne;
} Etudiant;

#endif
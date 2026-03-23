#include "TP4_TU.h"
#include <stdio.h>

int estPair(int n) {
    return n % 2 == 0;
}

int max2(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int factorielle(int n) {
    int resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat *= i;
    }
    return resultat;
}

int contientMajuscule(const char* chaine) {
    if (chaine == NULL) {
        return 0; // Traiter le cas où la chaîne est NULL
	}
    int i = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
            return 1;
        }
        i++;
    }
    return 0;
}

int divisionExacte(int a, int b) {
    if (b == 0) {
        return 0; // Traiter le cas de division par zéro
	}
    return a % b == 0;
}

int sommeTableau(const int tab[], int taille) {
    if (tab == NULL || taille < 0) {
		return 0; // Traiter les cas où le tableau est NULL ou la taille est négative
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tab[i];
    }
    return somme;
}

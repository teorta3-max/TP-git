#ifndef TP5_H
#define TP5_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <locale.h>     
 
void Menu();
int lireChoix();
void initialiser(int conso[]);
void ajouterConsommation(int conso[]);
void afficheResume(int conso[]);
void sauvegarderConsommation(int conso[]);
int charger(int conso[]);
int sauvegarder(int conso[]);
int humeurBonbons(int nb);
int humeurLegumes(int nb);
int humeurFruits(int nb);
void afficherBarre(int valeur, int max);

#endif

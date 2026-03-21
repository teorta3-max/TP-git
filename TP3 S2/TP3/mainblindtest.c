#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blindtest.h"

#define MAX_SONGS 100

int main() {
    Song chansons[MAX_SONGS];
    int nb_chansons;

    srand(time(NULL));

    // chargement
    nb_chansons = charger_chansons(chansons);
    if (nb_chansons == 0) return 1;

    // mélange
    melanger_chansons(chansons, nb_chansons);

    // joueur
    char nom[50];
    printf("Nom du joueur : ");
    scanf("%s", nom);

    int score = 0;

    // jeu
    for (int i = 0; i < nb_chansons; i++) {
        printf("\n--- Question %d ---\n", i + 1);

        jouer_musique(chansons[i].chemin);

        char reponse[100];
        printf("Titre ? ");
        scanf(" %[^\n]", reponse);

        // copie pour comparaison
        char rep[100], titre[100];
        strcpy(rep, reponse);
        strcpy(titre, chansons[i].titre);

        to_lower_str(rep);
        to_lower_str(titre);

        if (strcmp(rep, titre) == 0) {
            printf("Correct !\n");
            score++;
        } else {
            printf("Faux ! Réponse : %s\n", chansons[i].titre);
        }
    }

    // fin
    printf("\nScore final : %d\n", score);

    Score *liste = charger_scores();
    update_score(&liste, nom, score);
    sauver_scores(liste);

    return 0;
}
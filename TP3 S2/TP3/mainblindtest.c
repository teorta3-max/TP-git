#include "blindtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Song songs[100];
    int nb_chansons;
    int i;
    Score j;
    char reponse[100];

    srand(time(NULL));

    nb_chansons = load_songs("songs.txt", songs);

    if (nb_chansons <= 0) {
        printf("Erreur : aucune chanson chargee.\n");
        return 1;
    }

    printf("Entrez votre nom : ");
    scanf("%s", j.joueur);

    j.score = 0;

    for (i = 0; i < nb_chansons; i++) {
        int debut = rand() % 30;

        printf("\n--------------------------\n");
        printf("Morceau %d sur %d\n", i + 1, nb_chansons);
        printf("Lecture de l'extrait...\n");

        play_song_excerpt_at(songs[i].titre, debut, 10);

        printf("Entrez le titre : ");
        scanf("%s", reponse);

        if (string_equals_normalized(reponse, songs[i].titre)) {
            printf("Bonne reponse !\n");
            j.score++;
        } else {
            printf("Mauvaise reponse.\n");
            printf("Titre attendu : %s\n", songs[i].titre);
            printf("Artiste : %s\n", songs[i].artiste);
        }
    }

    printf("\n==========================\n");
    printf("Fin de la partie !\n");
    printf("Joueur : %s\n", j.joueur);
    printf("Score final : %d\n", j.score);

    return 0;
}
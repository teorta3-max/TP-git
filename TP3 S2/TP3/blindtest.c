#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "blindtest.h"

int charger_chansons(Song chansons[]) {
    FILE *f = fopen("songs.txt", "r");
    if (!f) {
        printf("Erreur ouverture songs.txt\n");
        return 0;
    }

    int i = 0;

    while (fscanf(f, "%[^;];%[^;];%[^\n]\n",
                  chansons[i].chemin,
                  chansons[i].titre,
                  chansons[i].artiste) == 3) {
        i++;
    }

    fclose(f);
    return i;
}

void melanger_chansons(Song tab[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        Song temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

void jouer_musique(char *chemin) {
    char cmd[400];

    // lancement en arrière-plan
    sprintf(cmd, "start /B ffplay -nodisp -autoexit -loglevel quiet \"%s\"", chemin);
    system(cmd);

    printf("\n Appuie sur ENTREE pour arreter la musique...\n");

    getchar(); // vide buffer
    getchar(); // attend entrée

    // tuer ffplay
    system("taskkill /IM ffplay.exe /F >nul 2>&1");
}

void to_lower_str(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

Score* charger_scores() {
    FILE *f = fopen("scores.txt", "r");
    if (!f) return NULL;

    Score *tete = NULL;

    char nom[50];
    int score;

    while (fscanf(f, "%[^;];%d\n", nom, &score) == 2) {
        Score *n = malloc(sizeof(Score));
        strcpy(n->nom, nom);
        n->meilleur_score = score;
        n->suivant = tete;
        tete = n;
    }

    fclose(f);
    return tete;
}

void update_score(Score **liste, char *nom, int score) {
    Score *p = *liste;

    while (p != NULL) {
        if (strcmp(p->nom, nom) == 0) {
            if (score > p->meilleur_score)
                p->meilleur_score = score;
            return;
        }
        p = p->suivant;
    }

    // ajout si joueur non trouvé
    Score *n = malloc(sizeof(Score));
    strcpy(n->nom, nom);
    n->meilleur_score = score;
    n->suivant = *liste;
    *liste = n;
}

void sauver_scores(Score *liste) {
    FILE *f = fopen("scores.txt", "w");
    if (!f) return;

    Score *p = liste;
    while (p != NULL) {
        fprintf(f, "%s;%d\n", p->nom, p->meilleur_score);
        p = p->suivant;
    }

    fclose(f);
}
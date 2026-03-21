#ifndef BLINDTEST_H
#define BLINDTEST_H

typedef struct {
    char chemin[256];
    char titre[100];
    char artiste[100];
} Song;

typedef struct Score {
    char nom[50];
    int meilleur_score;
    struct Score* suivant;
} Score;

// chansons
int charger_chansons(Song chansons[]);
void melanger_chansons(Song tab[], int n);

// jeu
void jouer_musique(char *chemin);
void to_lower_str(char *s);

// scores
Score* charger_scores();
void update_score(Score **liste, char *nom, int score);
void sauver_scores(Score *liste);

#endif
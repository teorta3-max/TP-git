#ifndef BLINDTEST_H
#define BLINDTEST_H

typedef struct Score {
    char joueur[100];
    int score;
    struct Score * suivant;
} Score;

typedef struct Song {
    char titre[100];
    char artiste[100];
    char liste[100];
} Song;

/* daja donnee */

void trim_newline(char *s);
void normalize_string(char *dest, const char *src);
int string_equals_normalized(const char *a, const char *b);
void play_song_excerpt_at(const char *filename, int start, int seconds);
int load_songs(const char *filename, Song songs[]); // j'ai completée c bon ça 

/* a faire  */

void melanger_chansons(Song songs[], int n);

Score * charger_scores();
Score * update_score(Score *list, const char *player, int score);
void sauver_scores(Score *list);

#endif
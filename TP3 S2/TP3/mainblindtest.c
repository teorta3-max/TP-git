#include "blindtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Song songs[100];
    int song_count;
    song_count = compter_chansons();
    load_songs("songs.txt", songs);
    for (int i = 0; i < song_count; i++) {
        printf("Chanson %d: %s - %s\n", i + 1, songs[i].artiste, songs[i].titre);
    }
}
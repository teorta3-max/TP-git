#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    //Exercice 1
    int secondes;
    printf("Entrez un nombre de secondes : ");
    scanf("%d", &secondes);
    int heures = secondes / 3600;
    int minutes = (secondes % 3600) / 60;
    int sec = secondes % 60;
    printf("%d secondes = %d heures, %d minutes et %d secondes\n", secondes, heures, minutes, sec);

    //Exercice 2
    int C;
    int t;
    int n;
    printf("Quelle est le montant de votre pret ? ");
    scanf("%d", &C);
    printf("Quelle est le taux d'interet annuel? ");
    scanf("%d", &t);
    printf("Sur combien d'annees ? ");
    scanf("%d", &n);
    float r = t / 100.0 / 12;
    int num_months = n * 12;
    float mensualite = C * (r * pow(1 + r, num_months)) / (pow(1 + r, num_months) - 1);
    printf("Votre mensualite est de : %.2f\n", mensualite);

    //Exercice 3
    const char *stages[10] = {
        "",
        "\n\n\n\n\n\n\n-------\n",
        "\n |\n |\n |\n |\n |\n |\n-------\n",
        " -------\n |     \n |\n |\n |\n |\n-------\n",
        " -------\n |     \n |     O\n |\n |\n |\n-------\n",
        " -------\n |     \n |     O\n |     |\n |\n |\n-------\n",
        " -------\n |     \n |     O\n |    /|\n |\n |\n |\n-------\n",
        " -------\n |     \n |     O\n |    /|\\\n |\n |\n |\n-------\n",
        " -------\n |     \n |     O\n |    /|\\\n |    / \n |\n |\n-------\n",
        " -------\n |     \n |     O\n |    /|\\\n |    / \\\n |\n-------\n"
    };
    char word[] = "ordinateur";
    int word_len = strlen(word);
    char display[11];
    memset(display, '_', word_len);
    display[word_len] = '\0';
    int wrong = 0;
    int guessed[26] = {0};
    while (wrong < 9 && strchr(display, '_')) {
        printf("%s\n", stages[wrong]);
        printf("Mot: %s\n", display);
        printf("Lettres devinees: ");
        for (char c = 'a'; c <= 'z'; c++) {
            if (guessed[c - 'a']) {
                printf("%c ", c);
            }
        }
        printf("\nEntrez une lettre: ");
        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);
        if (!isalpha(guess)) {
            printf("Entrez une lettre valide!\n");
            continue;
        }
        if (guessed[guess - 'a']) {
            printf("Deja devinee!\n");
            continue;
        }
        guessed[guess - 'a'] = 1;
        int found = 0;
        for (int i = 0; i < word_len; i++) {
            if (tolower(word[i]) == guess) {
                display[i] = word[i];
                found = 1;
            }
        }
        if (!found) {
            wrong++;
        }
    }
    if (wrong == 9) {
        printf("%s\n", stages[9]);
        printf("Perdu! Le mot etait %s\n", word);
    } else {
        printf("Gagne! Le mot etait %s\n", word);
    }
}

    
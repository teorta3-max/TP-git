#include <stdio.h>

int main()
{
    // Etape 1  
    int taille;

    // Demande une taille entre 5 et 10
    printf("Saisir une taille n (5 <= n <= 10) : ");
    scanf("%d", &taille);

    // Au cas ou la personne n'as pas respecté les consignes
    while (taille < 5 || taille > 10) {
        printf("Erreur : la taille doit etre comprise entre 5 et 10.\n");
        printf("Saisir une taille n (5 <= n <= 10) : ");
        scanf("%d", &taille);
    }

    // width = largeur de l’image
    // max_height = hauteur de l’image
    int width = taille * taille;
    int max_height = 3 * taille - 1;

    // On met le tableau
    char img[100][100];

    // Etape 2

    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = ' ';     // Pour chaque case on met un espace par défaut
        }
    }

    // Etape 3
    // On Affichage pour tester
    for (int k = 0; k < max_height; k++) {
        for (int l = 0; l < width; l++) {
            printf("%c", img[k][l]);
        }
        printf("\n");
    }

    // Etape 4

    int mid = width / 2;  // milieu de l’image sur chaque ligne

    for (int i = 0; i < taille; i++) {

        // On définit la gauche et la droite
        int gauche = mid - i;
        int droite = mid + i;

        // On place les bords en 'A'
        img[i][gauche] = 'A';
        img[i][droite] = 'A';

        // On remplit avec 'S'
        for (int j = gauche + 1; j < droite; j++) {
            img[i][j] = 'S';
        }

        // On fait la ligne du bas en '_'
        for (int c = 0; c < mid - (taille - 1); c++) {
            img[taille - 1][c] = '_';
        }

        for (int c = mid + (taille - 1) + 1; c < width; c++) {
            img[taille - 1][c] = '_';
        }
    }
    // Etape 5

    for (int i = taille; i < taille * 2 - 2; i++)
    {
        // init_t : décalage pour rétrécir au fur et a mesure la zone
        int init_t = 2 * i - 2 * taille;

        // On remplit entre init_t et width - init_t
        for (int j = init_t; j < width - init_t; j++)
        {
            img[i][j] = 'S';

            // Si j correspond aux bords : on met '.'
            if (j == init_t || j == width - init_t - 1)
            {
                img[i][j] = '.';

                // On Ajoute des 'V' juste après le bord
                img[i][init_t + 1] = 'V';
                img[i][width - init_t - 2] = 'V';
            }
        }
    }

    // Etape 6

    int nligne = taille * 2 - 2;  // l'indice de la ligne de départ

    for (int i = 0; i < taille + 1; i++)
    {
        // On remplit entièrement la ligne de 'S'
        for (int j = 0; j < width; j++)
        {
            img[nligne][j] = 'S';
        }

        // On rétrécit au fur et a mesure
        for (int j = 0; j < 2 * taille - 4 - i; j++)
        {
            img[nligne][j] = ' ';
            img[nligne][width - j - 1] = ' ';

            // On ajoute de '.' aux extrémités 
            if (j == 2 * taille - 5 - i)
            {
                img[nligne][width - j - 1] = '.';
                img[nligne][j] = '.';
            }
        }

        for (int j = mid - 2 * i; j < mid; j++)
        {
            img[nligne][j] = ' ';
            img[nligne][width - j - 1] = ' ';
            img[nligne][mid] = ' ';

            // On ajoute des guillemets " aux extrémités intérieures
            if (j == mid - 2 * i)
            {
                img[nligne][width - j - 1] = '\"';
                img[nligne][j] = '\"';
            }
        }

        nligne++;  // On passe à la ligne suivante
    }

    // Etape 7

    for (int i = 0; i < max_height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}
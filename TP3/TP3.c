#include <stdio.h>

int main()
{
    //étape 1
    int taille;

    printf("Saisir une taille n (5 <= n <= 10) : ");
    scanf("%d", &taille);
    while (taille < 5 || taille > 10) {
        printf("Erreur : la taille doit etre comprise entre 5 et 10.\n");
        printf("Saisir une taille n (5 <= n <= 10) : ");
        scanf("%d", &taille);
    }
    int width = taille * taille;
    int max_height = 3 * taille - 1;
    char img[100][100];

    // Etape 2
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = ' ';
        }
    }

    //Etape 3

    for (int k = 0; k < max_height; k++) {
        for (int l = 0; l < width; l++) {
            printf("%c",img[k][l]);
        }
        printf("\n");
    }

    //Etape4

    int mid = width / 2;
    for (int i = 0; i < taille; i++) {
        int gauche = mid - i;
        int droite = mid + i;

        img[i][gauche] = 'A';
        img[i][droite] = 'A';

        for (int j = gauche + 1; j < droite; j++) {
            img[i][j] = 'S';
        }

        for (int c = 0; c < mid - (taille - 1); c++) {
            img[taille - 1][c] = '_';
        }


        for (int c = mid + (taille - 1) + 1; c < width; c++) {
            img[taille - 1][c] = '_';
        }
    }


    for (int k = 0; k < max_height; k++) {
        for (int l = 0; l < width; l++) {
            printf("%c",img[k][l]);
        }
        printf("\n");
    }

    // étape 5 
    for (int i = taille; i < taille * 2 - 2; i++)
    {
        int init_t = 2 * i - 2 * taille;
        for (int j = init_t; j < width - init_t; j++)
        {
            img[i][j] = 'S';

            if (j == init_t || j == width - init_t - 1)
            {
                img[i][j] = '.';
                img[i][init_t+1] = 'V';
                img[i][width - init_t-2] = 'V';
            }
        }
    }

    // étape 6
    int nligne = taille * 2 - 2;
    for (int i = 0; i < taille + 1; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[nligne][j] = 'S';
        }
        for (int j = 0; j < 2 * taille - 4 - i; j++)
        {
            img[nligne][j] = ' ';
            img[nligne][width - j - 1] = ' ';
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
            if (j == mid - 2 * i)
            {
                img[nligne][width - j - 1] = '\"';
                img[nligne][j] = '\"';
            }
        }

        nligne++;
    }

    // Dessine l'etoile une dernière fois pour voir si c'est juste
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
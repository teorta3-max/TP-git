#include "TP5.h"
#include <stdio.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int consomation[7];
    int objectifs[7] = {8, 0, 0, 0, 5, 3, 2};

    if (charger(consomation) == 0) {
        printf("Aucune sauvegarde trouvée\n");
        initialiser(consomation);
    }

    int choix = 0;
    while (1) {
        Menu();
        choix = lireChoix();

        if (choix == 1) {
            ajouterConsommation(consomation);
        } else if (choix == 2) {
            afficheResume(consomation);
        } else if (choix == 3) {
            afficherObjectifsEtScore(consomation, objectifs);
        } else if (choix == 4) {
            if (sauvegarderParJour(consomation) == 1) {
                printf("Sauvegarde journalière effectuée.\n");
            } else {
                printf("Erreur avec la sauvegarde.\n");
            }
        } else if (choix == 5) {
            printf("Afficher un ou touts les jours? ? (1 = courant, 2 = tous) : ");
            int opt;
            scanf("%d", &opt);
            afficherResumeFichier(opt == 2);
        } else if (choix == 0) {
            break;
        } else {
            printf("Choix invalide, réessayez.\n");
        }
    }

    return 0;
}

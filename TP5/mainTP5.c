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
    while (choix != 4) {
        Menu();
        choix = lireChoix();
        if (choix == 1) {
            ajouterConsommation(consomation);
        } else if (choix == 2) {
            afficheResume(consomation);
        } else if (choix == 3) {
            afficherObjectifsEtScore(consomation, objectifs);
        } else if (choix == 4) {
            if (sauvegarder(consomation) == 1) {
                printf("Sauvegarde effectue.\n");
            } else {
                printf("Erreur avec la sauvegarde.\n");
            }
            return 0;
        } else {
            printf("Choix invalide, reessayer.\n");
        }
    }
    return 0;
}

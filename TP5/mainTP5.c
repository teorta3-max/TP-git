#include "TP5.h"
#include <stdio.h>

int main() {
    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleCP(CP_UTF8); 
    setlocale(LC_ALL, ".UTF-8");  
    int consomation[7];
    int choix;
    initialiser(consomation);
    while (choix != 3){Menu();
        choix = lireChoix();
        if (choix == 1) {
            ajouterConsommation(consomation);
        } else if (choix == 2) {
            afficheResume(consomation);
        } else if (choix == 3) {
            return 0;
        } else {
            printf("Choix invalide, reessayer.\n");
        }   
   } 
   return 0;
}

#include "TP5.h"
#include <stdio.h>

int main() {
   int consomation[7];
   int choix ;
   Menu();
   choix = lireChoix();
   while (choix != 1 && choix != 2 && choix != 3) {
       Menu();
       choix = lireChoix();
   }

}

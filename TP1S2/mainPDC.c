#include "PDC.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

int main (){
    int rangees;
    int tables;
    char nomdufichier[50];
    demander(&rangees,&tables,nomdufichier);
    printf("%d,%d,%s",rangees,tables,nomdufichier);
    int tab[rangees][tables];
    creesalle(rangees,tables,nomdufichier,tab);
    for (int i = 0; i < rangees; i++) {
        for (int j = 0; j < tables; j++) {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}
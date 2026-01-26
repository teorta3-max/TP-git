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
}
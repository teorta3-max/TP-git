#include <stdlib.h>
#include <time.h>
#include "PDC.h"

int main()
{
    Eleve *eleves;
    int nbEleves;
    int nbRangees, nbTables;

    srand(time(NULL));

    eleves = demander(&nbEleves,
                      &nbRangees,
                      &nbTables);

    creerSalle(eleves,
               nbEleves,
               nbRangees,
               nbTables);

    return 0;
}
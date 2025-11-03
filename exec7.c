#include <stdio.h>

int main() {
    float distance_km = 105;
    float vitesse_kmh = 50;
    float temps = distance_km / vitesse_kmh; 
    float minutes = temps * 60;
    printf("minutes = %f\n", minutes); 
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Le calcul de 'temps' utilise une division entière, ce qui peut entraîner une perte de précision si la distance n'est pas un multiple de la vitesse.
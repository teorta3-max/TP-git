#include <stdio.h>

int main() {
    int distance_km = 100;
    int vitesse_kmh = 50;
    int temps = distance_km / vitesse_kmh; 
    int minutes = temps * 60;
    printf("minutes = %d\n", minutes); 
    return 0;
}

//Il n'y a pas de message d'erreur de compilation dans ce fichier.
// Le calcul de 'temps' utilise une division entière, ce qui peut entraîner une perte de précision si la distance n'est pas un multiple de la vitesse.
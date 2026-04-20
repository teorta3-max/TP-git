#ifndef FICHIER1_H
#define FICHIER1_H

typedef struct Groupe{
	int taille;
	struct Groupe * suivant;
} Groupe;

typedef struct {
	Groupe* premier;
	Groupe* dernier;
} filedattente;

filedattente * ceerfile();
void deplacerGroupeAlafin( filedattente* file);
Groupe* creerGpe(int taille);
void ajouterGpe(Groupe* gpe, filedattente* file);
void afficherFile(filedattente* file);

#endif // !

#define TAILLE_MOT 18
#define R 4
#define C 4
typedef struct Mot_{
	char motForme[TAILLE_MOT];
	int score;
	struct Mot* suivant;
	}Mot;



void genererGrille(char grille[R][C]);
int lireFichier(char *filename, char motForme[]);
int rechercheGrille(char grille[R][C], char grilleMap[R][C], char motForme[], int indexL, int indexC, int index);
int premiereOccurence(char grille[R][C], char grilleMap[R][C], char motForme[]);
void gardeMot(Mot** nouveauMot, char motForme[]);
void imprimerGrille(char grille[R][C]);
int rechercheRepetes(int desMot[], int taille, int nouveau);
int scoreMot(char motForme[]);
void afficherMots(Mot** nouveauMot);
int getScore(Mot** nouveauMot);

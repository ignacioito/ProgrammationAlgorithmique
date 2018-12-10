//Vous devez implementer un jeu de Boggle console en C, incluant la recherche
//dans le dictionnaire, la generation de la grille de jeu, la recherche d'un mot
//dans la grille et l'interaction avec l'utilisateur.
//
//******************************
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define BUFF 20
#define TAILLE_MOT 18
#define R 4
#define C 4
#define NB_FACES 6
#define POINT 3
#define CYCLE 120000	

typedef struct Mot Mot;
struct Mot{
	char motForme[TAILLE_MOT];	
	int score;
	Mot* suivant;	
	};

/** Les 16 des officiels du jeu de boggle en francais */
const char DES[R * C][NB_FACES] =
{{'E', 'T', 'U', 'K', 'N', 'O'}, // 0
{'E', 'V', 'G', 'T', 'I', 'N'}, // 1
{'D', 'E', 'C', 'A', 'M', 'P'}, // 2
{'I', 'E', 'L', 'R', 'U', 'W'}, // 3
{'E', 'H', 'I', 'F', 'S', 'E'}, // 4
{'R', 'E', 'C', 'A', 'L', 'S'}, // 5
{'E', 'N', 'T', 'D', 'O', 'S'}, // 6
{'O', 'F', 'X', 'R', 'I', 'A'}, // 7
{'N', 'A', 'V', 'E', 'D', 'Z'}, // 8
{'E', 'I', 'O', 'A', 'T', 'A'}, // 9
{'G', 'L', 'E', 'N', 'Y', 'U'}, // 10
{'B', 'M', 'A', 'Q', 'J', 'O'}, // 11
{'T', 'L', 'I', 'B', 'R', 'A'}, // 12
{'S', 'P', 'U', 'L', 'T', 'E'}, // 13
{'A', 'I', 'M', 'S', 'O', 'R'}, // 14
{'E', 'N', 'H', 'R', 'I', 'S'}}; // 15


void genererGrille(char grille[R][C]);
int lireFichier(char *filename, char motForme[]);
int rechercheGrille(char grille[R][C], char grilleMap[R][C], char motForme[], int indexL, int indexC, int index);
int recherchePremiereMotGrille(char grille[R][C], char grilleMap[R][C], char motForme[]);
void gardeMot(Mot** nouveauMot, char motForme[]);
void imprimerGrille(char grille[R][C]);
int rechercheRepetes(int desMot[], int taille, int nouveau);
int scoreMot(char motForme[]);
void imprimerMotsTrouve(Mot** nouveauMot);
int imprimerScore(Mot** nouveauMot);

int main()
{	
	srand(time(NULL));
	char grille[R][C];
	char grilleMap[R][C];
	char motForme[TAILLE_MOT];
	Mot* nouveauMot = NULL;
	int score;
	double temps;
	
	clock_t Ticks[2];
    Ticks[0] = clock();

	genererGrille(grille);	
	for(;temps < CYCLE;)
	{
	printf("Temps passe: %g ms de %d ms\n", temps, CYCLE);
	imprimerGrille(grille);	
	imprimerMotsTrouve(&nouveauMot);	
	scanf(" %s",motForme);	
	if((lireFichier("francais.txt",motForme) == 1) && (recherchePremiereMotGrille(grille, grilleMap, motForme) == 1))	gardeMot(&nouveauMot, motForme);	
	//system("cls"); 		//windows
	printf("\033c" );	  //unix	
	Ticks[1] = clock();
    temps = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;    	
	}
	printf("      ");
	imprimerMotsTrouve(&nouveauMot);
	score = imprimerScore(&nouveauMot);
	score > POINT ? printf("\n      Votre score final etait de %d c'etait pas mal, felicitations! ", score) : 
	printf("\n      Votre score final etait de %d, vous vous etes trompe! ", score);
}
//**************************
//
// fonction qui dessine la grille et se remplit des lettres
//
//**************************
void genererGrille(char grille[R][C])
{
	int rangee;
	int colonne;
	int des;
	int desMot[R * C];
	int nouveau;
	
	for(rangee = 0; rangee < (R * C);)
	{
		nouveau = rand() % (R * C) + 0;
		if(rechercheRepetes(desMot, rangee, nouveau) == 0)
		{								
			desMot[rangee] = nouveau;			
			rangee++;			
		}		
	}
	des = 0;
	for(rangee = 0; rangee < R; rangee++)
	{	
		for(colonne = 0; colonne < C; colonne++)
		{			
			grille[rangee][colonne] = DES[desMot[des]][rand() % NB_FACES + 0];	
			des++;
		}
	}	
}
//**************************
//
// fonction qui cherche le mot dans le dictionnaire
//
//**************************
int lireFichier(char *filename, char motForme[])
{
	int a = 0;
	int b = 0;
    FILE *file = fopen(filename, "r");
    int nblines = 0;
  
    if (file == NULL )
    {
		perror("fopen");
		exit(1);
    }
    char mot[BUFF];
    while (fgets(mot, BUFF, file) != NULL) 
    {
		int l = strlen(mot);
		mot[l - 1] = '\0';	
		a = strlen(mot);
		if(a >= b)
		{
			b = a;
		}
		if(!strcmp(mot, motForme)) return 1;
	}	    
    fclose(file);
    return nblines;
}
//**************************
//
// fonction recherche le mot dans la grille
//
//**************************
int rechercheGrille(char grille[R][C], char grilleMap[R][C], char motForme[], int indexL, int indexC, int index)
{
	int rangee;
	int colonne;
	
	index = index + 1;
	for(rangee = indexL - 1; rangee <= indexL + 1; rangee++)
	{
		for(colonne = indexC - 1; colonne <= indexC + 1; colonne++)
		{				
			if((grille[rangee][colonne] == motForme[index]) && (rangee >= 0) && (rangee <= indexL + 1) && (colonne >= 0) && (colonne <= indexC + 1))
			{				
				return 1 + rechercheGrille(grille,grilleMap,motForme,rangee,colonne,index);			
			}
		}			
	}
	return 0;
}
//**************************
//
// fonction recherche le premiere mot dans la grille
//
//**************************
int recherchePremiereMotGrille(char grille[R][C], char grilleMap[R][C], char motForme[])
{
	int rangee;
	int colonne;
	int tailleMot;
	int teste;
	
	tailleMot = strlen(motForme);
	for(rangee = 0; rangee < R; rangee++)
	{
		for(colonne = 0; colonne < C; colonne++)
		{
			if(grille[rangee][colonne] == motForme[0])
			{	
				if((rechercheGrille(grille, grilleMap, motForme, rangee, colonne, 0) + 1) == tailleMot)				
				return 1;				
			}
		}		
	}
	return 0;
}
//**************************
//
// fonction qui stocke le mot existant
//
//**************************
void gardeMot(Mot** nouveauMot, char motForme[])
{ 	
	
	if(*nouveauMot == NULL)
	{
		*nouveauMot = (Mot *)malloc(sizeof(Mot));
		strcpy((*nouveauMot)->motForme,motForme);
		(*nouveauMot)->score = scoreMot(motForme);
		(*nouveauMot)->suivant = NULL;
	}
	else
	{
		gardeMot(&((*nouveauMot)->suivant),motForme);
	}
}
//**************************
//
// fonction pour imprimer la grille
//
//**************************
void imprimerGrille(char grille[R][C])
{
	
	int rangee;
	int colonne;
	printf("\n\n\n              ");
	for(rangee = 0; rangee < R; rangee++)
	{
		for(colonne = 0; colonne < C; colonne++)
		{
			printf(" %c ",grille[rangee][colonne]);
		}
		printf("\n              ");
	}
	printf("\n\n\n      ");
}
//**************************
//
// fonction recherche les nombres répétés
//
//**************************
int rechercheRepetes(int desMot[], int taille, int nouveau)
{
	int rangee;
	
	for(rangee = 0; rangee < taille;rangee++)
	{	
		if(desMot[rangee] == nouveau) return 1;
	}	
	return 0;
}
//**************************
//
// fonction retourne le mot ponctuation
//
//**************************
int scoreMot(char motForme[])
{
	if(strlen(motForme) >= POINT) return 2;
	else return 0;
}
//**************************
//
// fonction pour imprimer tout les mots trouvé
//
//**************************
void imprimerMotsTrouve(Mot** nouveauMot)
{
	if(*nouveauMot != NULL)
	{
		printf("%s,",(*nouveauMot)->motForme);
		imprimerMotsTrouve(&((*nouveauMot)->suivant));
	}
}
//**************************
//
// fonction pour imprimer le score final
//
//**************************
int imprimerScore(Mot** nouveauMot)
{	
	if(*nouveauMot != NULL)	return (*nouveauMot)->score + imprimerScore(&((*nouveauMot)->suivant));		
	return 0;
}
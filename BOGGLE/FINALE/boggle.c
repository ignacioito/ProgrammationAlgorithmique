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
#include "boggle.h"

#define BUFF 20
#define TAILLE_MOT 18
#define R 4
#define C 4
#define NB_FACES 6
#define POINT 3

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

//**************************
//
// fonction qui dessine la grille et se remplit des lettres
//
//**************************
void genererGrille(char grille[R][C])
{
	int i,j,des,nouveau;
	int desMot[R * C];

	for(i = 0; i < (R * C);)
	{
		nouveau = rand() % (R * C) + 0;
		if(rechercheRepetes(desMot, i, nouveau) == 0)
		{
			desMot[i] = nouveau;
			i++;
		}
	}
	des = 0;
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			grille[i][j] = DES[desMot[des]][rand() % NB_FACES + 0];
			des++;
		}
	}
}

int lireFichier(char *filename, char motForme[])
{

    FILE *file = fopen(filename, "r");
    if (file == NULL )
    {
		perror("fopen");
		exit(1);
    }
    char mot[BUFF];
    while (fgets(mot, BUFF, file) != NULL)
    {
		mot[strlen(mot) - 1] = '\0';
            if(!strcmp(mot, motForme))
                return 1;
	}
    fclose(file);

    return 0;
}
//**************************
//
// fonction recherche le mot dans la grille
//
//**************************
int rechercheGrille(char grille[R][C], char grilleMap[R][C], char motForme[], int indexL, int indexC, int index)
{
	int i,j;

	for(i = indexL - 1; i <= indexL + 1; i++)
	{
		for(j = indexC - 1; j <= indexC + 1; j++)
		{
			if((grille[i][j] == motForme[index+1]) && (i >= 0) && (i <= indexL + 1) && (j >= 0) && (j <= indexC + 1))
			{
				return 1 + rechercheGrille(grille,grilleMap,motForme,i,j,index+1);
			}
		}
	}
	return 0;
}

int premiereOccurence(char grille[R][C], char grilleMap[R][C], char motForme[])
{
	int i,j;
    for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			if(grille[i][j] == motForme[0])
			{
				if((rechercheGrille(grille, grilleMap, motForme, i, j, 0) + 1) == strlen(motForme))
				return 1;
			}
		}
	}
	return 0;
}

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
// fonction pour  la grille
//
//**************************
void imprimerGrille(char grille[R][C])
{

	//int i;
	int colonne;
	printf("\n\n\n              ");
	for(int i = 0; i < R; i++)
	{
		for(colonne = 0; colonne < C; colonne++)
		{
			printf(" %c ",grille[i][colonne]);
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
	int i;

	for(i = 0; i < taille;i++)
	{
		if(desMot[i] == nouveau) return 1;
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
	if(strlen(motForme) >= POINT ) return 2;
	else return 0;
}
//**************************
//
// fonction pour imprimer tout les mots trouvé
//
//**************************
void afficherMots(Mot** nouveauMot)
{
	if(*nouveauMot != NULL)
	{
		printf("%s,\n",(*nouveauMot)->motForme);
		afficherMots(&((*nouveauMot)->suivant));
	}
}

int getScore(Mot** nouveauMot)
{
	if(*nouveauMot != NULL)	return (*nouveauMot)->score + getScore(&((*nouveauMot)->suivant));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define BUFF 20
#define R 4
#define C 4
#define NB_FACES 6
#define TAILLE 4


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

void creerGrille(char grille[R][C]){
	
	srand(time(NULL));
	int indexL;
	int indexC;

	for (indexL = 0; indexL < TAILLE; indexL++)
	{
		for (indexC = 0; indexC < TAILLE; indexC++)
		{
			int x = rand() % 15;
			int y = rand() % 6;
			grille[indexL][indexC] = DES[x][y];
		}
	}
	/*for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			grille[i][j] = rand() % ('Z' - 'A' + 1) + 'A';
		}
	}*/
}

void imprimerGrille(char grille[R][C]){
	char des[NB_FACES];

	for (int i = 0; i < 16; ++i)
	{
		/* code */
	}

	for (int x = 0; x < R; ++x)
	{
		for (int y = 0; y < C; ++y)
		{
			printf("%c\n", grille[x][y]);
		}
	}
}

/*
int testerDesdansTableau(int des, int tableau[]){
	for (int i = 0; i < R; ++i)
	{
		if (tableau[i] == des)
		{
		}
	}
}
*/



int main()
{
	char grille[R][C];
	creerGrille(grille);
	imprimerGrille(grille);

	return 0;
}
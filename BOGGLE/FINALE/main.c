#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "boggle.h"
#define CYCLE 12000
#define POINT 3

int main()
{
	srand(time(NULL));
	char grille[R][C];
	char grilleMap[R][C];
	char motTrouve[TAILLE_MOT];
	Mot* nouveauMot=NULL;
	int score=1;
	double temps=0;

	clock_t Ticks[2];
    Ticks[0] = clock();
	genererGrille(grille);

	while(temps < CYCLE)
	{
	printf("Temps passe: %0.2f ms de %d ms\n", temps, CYCLE);
	imprimerGrille(grille);
	afficherMots(&nouveauMot);
	scanf("%s",motTrouve);
	if((lireFichier("francais.txt",motTrouve) == 1) &&(premiereOccurence(grille, grilleMap, motTrouve) == 1))
        {
            gardeMot(&nouveauMot, motTrouve);
        }
    else { printf("MOT INTROUVABLE \n\n ") ;
        }

	Ticks[1] = clock();
    temps = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	}

	//Afficher score
	printf("  \n\n\n    ");
	afficherMots(&nouveauMot);
	score = getScore(&nouveauMot);
	if (score > POINT)
    {printf("\n      Votre score final etait de %d c'etait pas mal, felicitations! ", score);}
    else
	{printf("\n      Votre score final etait de %d, vous vous etes trompe! ", score);}
}

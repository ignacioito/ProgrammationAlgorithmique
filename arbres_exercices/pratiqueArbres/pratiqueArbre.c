// Exercice pratique 
// Creez un algorithme qui compte le nombre de noeuds dans un arbre binaire.

// Ignacio Ito

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"pratiqueArbre.h"




Noeud* genererArbre(int nbNoeuds){
	if (nbNoeuds > 0)
    return creerNoeud((rand() % ('Z' - 'A' + 1)) + 'A',
		      genererArbre(nbNoeuds / 2),
		      genererArbre((nbNoeuds - 1) / 2));
  return NULL;
}

int main()
{
	srand(time(NULL));
	int nbNoeuds = 15;

	*Noeud racine = genererArbre(nbNoeuds);

	
	return genererArbre();
}


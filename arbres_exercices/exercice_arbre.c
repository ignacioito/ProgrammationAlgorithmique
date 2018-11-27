#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "exercice_arbre.h"

Noeud* genererArbreInacio(noeudinacio* racineInacio, int donnee)
{
  if (racineInacio == NULL)
    return creerNoeud((rand() % ('Z' - 'A' + 1)) + 'A',
		      genererArbre(nbNoeuds / 2),
		      genererArbre((nbNoeuds - 1) / 2));
  return NULL;
}

int main(int argc, char const *argv[])
{
	NoeudInacio* racineInacio;
}
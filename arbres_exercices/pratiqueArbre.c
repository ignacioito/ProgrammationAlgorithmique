// Exercice pratique 
// Creez un algorithme qui compte le nombre de noeuds dans un arbre binaire.

// Ignacio Ito

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include"pratiqueArbre.h"


Noeud* creerNoeud(char donnee, Noeud* g, Noeud* d)
{
  Noeud* n = (Noeud*)malloc(sizeof(Noeud));
  n->donnee = donnee;
  n->g = g;
  n->d = d;
  return n;
}

void libererNoeud(Noeud* n)
{
  if (n != NULL)
  {
    libererNoeud(n->g);
    libererNoeud(n->d);
    free(n);
  }
}

Noeud* genererArbre(int nbNoeuds)
{
	if (nbNoeuds > 0)
	{
    return creerNoeud((rand() % ('Z' - 'A' + 1)) + 'A', genererArbre(nbNoeuds / 2), genererArbre((nbNoeuds - 1) / 2));
    }
}

void parcoursProfondeur(Noeud* noeudArbre)
{
	if (noeudArbre != NULL)
	{
		printf("* %d\n", noeudArbre->donnee);
		parcoursProfondeur(noeudArbre->d);
		parcoursProfondeur(noeudArbre->g);

	}
}




int main()
{
	srand(time(NULL));
	int nbNoeuds = 15;
	Noeud* noeudArbre;

	Noeud* racine = genererArbre(nbNoeuds);

	
}


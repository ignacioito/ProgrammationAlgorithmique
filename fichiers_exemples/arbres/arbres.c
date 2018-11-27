
// 1 Dans parcours prof. trouver l condition de sortie de l'appel recursif la calcul de plus 
// 2 Changer l'ordre des appels recursif et du calcul de plus 
// 3 Crèez cet arbre dessu dans le main appliquez le parcours en profondeur dessus selon differents arbres
// d'instruction trouvés à la question 2
//            F
//      |           |
//      C           K
//    |   |       |    |
//    A   D       H    M

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arbres.h"

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

Noeud* genererArbreInacio(noeudinacio* racineInacio, int donnee)
{
  if (racineInacio == NULL)
    return creerNoeud((rand() % ('Z' - 'A' + 1)) + 'A', genererArbre(nbNoeuds / 2), genererArbre((nbNoeuds - 1) / 2));
  return NULL;
}

Noeud* genererArbre(int nbNoeuds)
{
  if (nbNoeuds > 0)
    return creerNoeud((rand() % ('Z' - 'A' + 1)) + 'A',
		      genererArbre(nbNoeuds / 2),
		      genererArbre((nbNoeuds - 1) / 2));
  return NULL;
}

void parcoursProfondeur(Noeud* racine)
{
  if (racine != NULL) // condition d'arrete: quand racine est NULL
  {
    printf("* %c ", racine->donnee); // Calcul de plus
    parcoursProfondeur(racine->g); // appelle recursif
    parcoursProfondeur(racine->d); // appel recursif
  }
}

void imprimerArbre(Noeud* racine, int* prefixe, int profondeur)
{
  if (racine == NULL)
    return;
  
  int prefixeNext[profondeur + 1];
  for (int i = 0; i < profondeur; i++)
  {
    switch (prefixe[i])
    {
      case VIDE : printf(PRINT_VIDE); break;
      case TRONC : printf(PRINT_TRONC); break;
      case TERMINAL : printf(PRINT_TERMINAL); break;
      case BRANCHE : printf(PRINT_BRANCHE); break;
    }
    prefixeNext[i] = prefixe[i];
  }
  if (profondeur > 0)
    prefixeNext[profondeur - 1] -= TERMINAL;
  
  printf(" %c\n", racine->donnee);
    
  prefixeNext[profondeur] = ((racine->d != NULL) ? BRANCHE : TERMINAL);
  imprimerArbre(racine->g, prefixeNext, profondeur + 1);
    
  prefixeNext[profondeur] = TERMINAL;
  imprimerArbre(racine->d, prefixeNext, profondeur + 1);
}

int main(int argc, char** argv)
{
  srand(time(NULL));
  int nbNoeuds = 15;
  if (argc > 1)
    nbNoeuds = atoi(argv[1]);
  
  Noeud* racine = genererArbre(nbNoeuds);
  imprimerArbre(racine, NULL, 0);
  
  parcoursProfondeur(racine);
  
  libererNoeud(racine);
  printf("\n");
}

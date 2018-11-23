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

}


// Liste chaînée d'arbres pour le parcours en largeur
typedef struct Queue Queue;
struct Queue
{
  Noeud* noeudArbre;
  Queue* suivant;
};

// ****************************************************************************
// static void parcoursLargeurQueue(Queue* premier)
//
// Parcourt le premier arbre dans la liste chaînée et ajoute ses enfants à
// la liste chaînée. Permet le parcours en largeur.
//
// INPUT :
//     premier : premier arbre dans une liste d'arbres à parcourir
// ****************************************************************************
static void parcoursLargeurQueue(Queue* premier)
{
  if (premier == NULL || premier->noeudArbre == NULL)
    return;
  
  printf("%c", premier->noeudArbre->donnee);
  Queue* dernier = premier;
  while (dernier->suivant != NULL)
      dernier = dernier->suivant;
  if (premier->noeudArbre->g != NULL)
  {
    dernier->suivant = (Queue*)malloc(sizeof(Queue));
    dernier = dernier->suivant;
    dernier->noeudArbre = premier->noeudArbre->g;
  }
  if (premier->noeudArbre->d != NULL)
  {
    dernier->suivant = (Queue*)malloc(sizeof(Queue));
    dernier = dernier->suivant;
    dernier->noeudArbre = premier->noeudArbre->d;
  }
  dernier->suivant = NULL;
  parcoursLargeurQueue(premier->suivant);
  free(premier);
}

void parcoursLargeur(Noeud* racine)
{
  Queue* q = (Queue*)malloc(sizeof(Queue));
  q->noeudArbre = racine;
  q->suivant = NULL;
  parcoursLargeurQueue(q);
}

// ****************************************************************************
// static void imprimerArbrePrefixe(Noeud* racine, int* prefixe,
//                                  int profondeur);
//
// Imprime une représentation hiérarchique d'un arbre
//
// INPUT :
//     racine : la racine d'un arbre
//     prefixe : description du dessin précédant racine
//     profondeur : profondeur de racine dans l'arbre
// ****************************************************************************
static void imprimerArbrePrefixe(Noeud* racine, int* prefixe, int profondeur)
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
  imprimerArbrePrefixe(racine->g, prefixeNext, profondeur + 1);
    
  prefixeNext[profondeur] = TERMINAL;
  imprimerArbrePrefixe(racine->d, prefixeNext, profondeur + 1);
}

void imprimerArbre(Noeud* racine)
{
  imprimerArbrePrefixe(racine, NULL, 0);
}

// ****************************************************************************
// Pilote pour les fonctions d'impression d'arbres. Il crée un arbre
// aléatoire de la taille spécifiée par l'usager et l'imprime hiérarchiquement
// selon le parcours en profondeur et selon le parcours en largeur.
// ****************************************************************************
int main(int argc, char** argv)
{
  srand(time(NULL));
  int nbNoeuds = 15;
  if (argc > 1)
    nbNoeuds = atoi(argv[1]);

  Noeud* racine = genererArbre(nbNoeuds);
  
  imprimerArbre(racine);
  parcoursLargeur(racine);
  printf("\n");
  parcoursProfondeur(racine);
  printf("\n");
  libererNoeud(racine);
}

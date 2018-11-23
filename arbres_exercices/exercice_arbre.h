#pragma once

#define PRINT_VIDE "   "
#define PRINT_TRONC " │ "
#define PRINT_TERMINAL " └─"
#define PRINT_BRANCHE " ├─"

enum {VIDE, TRONC, TERMINAL, BRANCHE};

typedef struct Noeud Noeud;
struct Noeud
{
  char donnee;
  Noeud* g;
  Noeud* d;
};

typedef struct Queue Queue;
struct Queue
{
  Noeud* noeudArbre;
  Queue* suivant;
};

typedef struct NoeudInacio NoeudInacio;
struct NoeudInacio
{
  int donnee;
  NoeudInacio* g;
  NoeudInacio* d;
};


Noeud* creerNoeud(char donnee, Noeud* g, Noeud* d);
void libererNoeud(Noeud* n);
Noeud* genererArbre(int nbNoeuds);
void parcoursProfondeur(Noeud* racine);
void parcoursLargeur(Noeud* queue);
void imprimerArbre(Noeud* racine, int* prefixe, int profondeur);

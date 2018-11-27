// Exercice pratique 
// Creez un algorithme qui compte le nombre de noeuds dans un arbre binaire.

// Ignacio Ito


#pragma once

#define PRINT_VIDE "   "
#define PRINT_TRONC " │ "
#define PRINT_TERMINAL " └─"
#define PRINT_BRANCHE " ├─"

enum {VIDE, TRONC, TERMINAL, BRANCHE};

typedef struct Noeud Noeud;
struct Noeud{
	char donnee;
	Noeud* d;
	Noeud* g;
};


Noeud* genererArbre(int nbNoeuds);
Noeud* creerNoeud(char donnee, Noeud* g, Noeud* d);
void libererNoeud(Noeud* n);
void parcoursProfondeur(Noeud* noeudArbre);

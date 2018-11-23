// Exercice pratique 
// Creez un algorithme qui compte le nombre de noeuds dans un arbre binaire.

// Ignacio Ito


#pragma once

#define PRINT_VIDE "   "
#define PRINT_TRONC " │ "
#define PRINT_TERMINAL " └─"
#define PRINT_BRANCHE " ├─"

typedef struct Noeud* Noeud;
struct Noeud{
	char donnee;
	Noeud* d;
	Noeud* g;
};

typedef struct Queue Queue;
struct Queue{
	Noeud* racine;
	Queue* suivant;
};


Noeud* genererArbre(char donnee, Noeud* g, Noeud* d);
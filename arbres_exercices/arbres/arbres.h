// ****************************************************************************
// arbre.h
// 20 novembre 2018
// Rébecca
// Les arbres binaires
// ****************************************************************************
#pragma once

// Parties du dessin d'un arbre
#define PRINT_VIDE "   "
#define PRINT_TRONC " │ "
#define PRINT_TERMINAL " └─"
#define PRINT_BRANCHE " ├─"

enum {VIDE, TRONC, TERMINAL, BRANCHE};

// Noeud dans un arbre
typedef struct Noeud Noeud;
struct Noeud
{
  char donnee;
  Noeud* g;
  Noeud* d;
};

// ****************************************************************************
// Noeud* creerNoeud(char donnee, Noeud* g, Noeud* d);
//
// Crée un noeud en mémoire et initialise sa donnée, son enfant gauche et droit
//
// INPUT :
//     donnee : le contenu du nouveau noeud
//     g : son enfant gauche
//     d : son enfant droit
//
// OUTPUT :
//     Une référence vers le nouveau noeud, en mémoire tas.
// ****************************************************************************
Noeud* creerNoeud(char donnee, Noeud* g, Noeud* d);

// ****************************************************************************
// void libererNoeud(Noeud* racine);
//
// Libère la mémoire utilisée par l'arbre enraciné
//
// INPUT :
//     racine : la racine d'un arbre
//
// ****************************************************************************
void libererNoeud(Noeud* racine);

// ****************************************************************************
// Noeud* genererArbre(int nbNoeuds);
//
// Bâtit un arbre binaire balancé de nbNoeuds noeuds dont le contenu est
// initialisé avec des lettres pigées aléatoirement
//
// INPUT :
//     nbNoeuds : Le nombre de noeuds à mettre dans l'arbre
//
// OUTPUT :
//     Une référence vers la racine du nouvel arbre, en mémoire tas.
// ****************************************************************************
Noeud* genererArbre(int nbNoeuds);

// ****************************************************************************
// void parcoursProfondeur(Noeud* racine)
//
// Parcours l'arbre enraciné en profondeur, dans l'ordre infix.
//
// INPUT :
//     racine : la racine d'un arbre
// ****************************************************************************
void parcoursProfondeur(Noeud* racine);

// ****************************************************************************
// void parcoursLargeur(Noeud* racine)
//
// Parcours l'arbre enraciné en largeur
//
// INPUT :
//     racine : la racine d'un arbre
// ****************************************************************************
void parcoursLargeur(Noeud* queue);

// ****************************************************************************
// void imprimerArbre(Noeud* racine);
//
// Imprime une représentation hiérarchique d'un arbre
//
// INPUT :
//     racine : la racine d'un arbre
// ****************************************************************************
void imprimerArbre(Noeud* racine);

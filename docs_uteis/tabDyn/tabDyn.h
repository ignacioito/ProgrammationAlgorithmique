// *****************************************************************************
// Nom : tabDyn.h
// Auteur : Rébecca
// Date : 5 novembre 2018
//
// Utilitaire implémentant un tableau dynamique
// *****************************************************************************
#pragma once

// Nombre de cases tampon
#define BUFF 10

// *****************************************************************************
// Un tableau dynamique contient un tableau (tab) dont la taille sera
// allongée au besoin
// *****************************************************************************
typedef struct TabDyn TabDyn;
struct TabDyn{
    double* tab;
    int taille;
    int dernier;
};

// *****************************************************************************
// void initialiser(TabDyn* tabDyn);
//
// Initialise le tableau dynamique
//
// INPUT :
//    tabDyn : un pointeur vers un tableau dynamique
//
// *****************************************************************************
void initialiser(TabDyn* tabDyn);

// *****************************************************************************
// int ajouterElement(TabDyn* tabDyn, double e);
//
// Ajoute l'élément e à la fin du tableau dynamique tabDyn. Si le tableau
// est sur le point de déborder, il est allongé.
//
// INPUT :
//     tabDyn : un pointeur vers un tableau dynamique
//     e : l'élément à ajouter
//
// OUTPUT :
//     0 si l'ajout a échoué, 1 sinon.
//
// *****************************************************************************
int ajouterElement(TabDyn* tabDyn, double e);

// *****************************************************************************
// void libererMemoire(TabDyn* tabDyn);
//
// Libère la mémoire réservée par le tableau dynamique
//
// INPUT :
//    tabDyn : un pointeur vers un tableau dynamique
//
// *****************************************************************************
void libererMemoire(TabDyn* tabDyn);

// *****************************************************************************
// void imprimerTabDyn(TabDyn tabDyn);
//
// Imprime à la console le contenu du tableau dynamique
//
// INPUT :
//    tabDyn : un tableau dynamique
//
// *****************************************************************************
void imprimerTabDyn(TabDyn tabDyn);

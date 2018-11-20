// ****************************************************************************
// listeChaineeRecursive.c
// 16 novembre 2018
// Rébecca
// Exercice de liste chaînée la récursion
// ****************************************************************************
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Noeud Noeud;
struct Noeud{
    int donnee;
    Noeud* suivant;
};

// ****************************************************************************
// void imprimerListe(Noeud* n)
//
// Imprime les données des noeuds dans une liste chaînée
//
// INPUT :
//     n : Une référence vers le premier noeud d'une liste chaînée.
// ****************************************************************************
void imprimerListe(Noeud* n)
{
    if (n != NULL)
    {
        printf("%d ", n->donnee);
        imprimerListe(n->suivant);
    }

}

// ****************************************************************************
// void imprimerListeEnvers(Noeud* n)
//
// Imprime à l'envers les données des noeuds d'un liste chaînée.
//
// INPUT :
//     n : Une référence vers le premier noeud d'une liste chaînée.
// ****************************************************************************
void imprimerListeEnvers(Noeud* n)
{
    
}

// ****************************************************************************
// Noeud* genererListe(const int L)
//
// Génère une liste chaînée de longueur L dans le tas, avec des valeurs
// aléatoires et retourne une référence vers le premier noeud.
//
// INPUT :
//     L : La longueur de la liste chaînée à générer
//
// OUTPUT : 
//     Une référence vers le premier noeud dans la nouvelle liste chaînée.
// ****************************************************************************
Noeud* genererListe(const int L)
{
    Noeud* n[L];
    for (int i = 0; i < L; i ++)
    {
        n[i] = (Noeud*) malloc(L * sizeof(Noeud));
        n[i]->donnee = rand() % L;
        n[i]->suivant = ((i > 0) ? n[i - 1] : NULL);
    }
    return n[L - 1];
}

// ****************************************************************************
// int get(Noeud* n, int i)
//
// Retourne la donnée dans le ie noeud d'une liste qui commence à n
//
// INPUT :
//     n : Une référence vers le premier noeud d'une liste chaînée.
//     i : L'indice du noeud à partir de n dont on doit trouver la valeur.
//
// OUTPUT : 
//     La valeur du ie noeud à partir de n.
// ****************************************************************************
int get(Noeud* n, int i)
{
    return 0;
}

// ****************************************************************************
// int longueurListe(Noeud* premier)
//
// Calcule la longueur d'une liste chaînée à partir d'un noeud
//
// INPUT :
//     n : Une référence vers le premier noeud d'une liste chaînée.
//
// OUTPUT : 
//     La longueur d'une liste à partir de n.
// ****************************************************************************
int longueurListe(Noeud* n)
{
    return 0;
}

// ****************************************************************************
// void libererListe(Noeud* n)
//
// Libère la mémoire utilisée par les noeuds de la liste
// chaînée à partir de n.
//
// INPUT :
//     n : Une référence vers le premier noeud d'une liste à libérer
// ****************************************************************************
void libererListe(Noeud* n)
{
    if (n != NULL)
    {
        libererListe(n->suivant);
        free(n);
    }
}

// ****************************************************************************
// Fonction pilote pour tester imprimerListe et imprimerListeEnvers
// ****************************************************************************
int main()
{
    srand(time(NULL));
    Noeud* premier = genererListe(10);

    printf("À l'endroit : ");
    imprimerListe(premier);
    printf("\nÀ l'envers  : ");

    // Exercice 0 : 
    imprimerListeEnvers(premier);
    printf("\n");

    // Exercice 1 : Calculer la longueur d'une liste
    // de manière récursive.


    // Exercice 2 : Retourner le ie élément d'une liste chaînée
    // de manière récursive.

    libererListe(premier);
}
// *****************************************************************************
// Nom : tabDyn.c
// Auteur : Rébecca
// Date : 5 novembre 2018
//
// Utilitaire implémentant un tableau dynamique
// *****************************************************************************
#include <stdlib.h>
#include <stdio.h>
#include "tabDyn.h"

void initialiser(TabDyn* tabDyn)
{
    tabDyn->dernier = 0;
    tabDyn->taille = BUFF;
    tabDyn->tab = (double*)malloc(tabDyn->taille * sizeof(double));
}

int ajouterElement(TabDyn* tabDyn, double e)
{
    tabDyn->tab[tabDyn->dernier] = e;
    tabDyn->dernier++;
    if (tabDyn->dernier >= tabDyn->taille)
    {
        tabDyn->taille += BUFF;
        double* temp = (double*)
           realloc(tabDyn->tab, tabDyn->taille * sizeof(double));
        if (temp == 0)
        {
	    free(tabDyn->tab);
            return 0;
        }
        tabDyn->tab = temp;
    }
    return 1;
}

void libererMemoire(TabDyn* tabDyn)
{
    free(tabDyn->tab);
}

void imprimerTabDyn(TabDyn tabDyn)
{
    printf("Le tableau contient %d cases, dont %d sont utilisées : \n",
	   tabDyn.taille, tabDyn.dernier);
  
    for (int j = 0; j < tabDyn.dernier; j++)
        printf("%0.1lf ", tabDyn.tab[j]);
    printf("\n");
}

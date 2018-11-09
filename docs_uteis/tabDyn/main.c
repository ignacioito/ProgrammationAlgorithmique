// *****************************************************************************
// Nom : main.c
// Auteur : Rébecca
// Date : 5 novembre 2018
//
// Programme qui demande des nombres à l'usager et les imprime.
// Il sert à tester notre implémentation de tableau dynamique
// *****************************************************************************

#include <stdlib.h>
#include <stdio.h>
#include "tabDyn.h"


// *****************************************************************************
// Fonction pilote pour tester notre implémentation de tableau dynamique
// *****************************************************************************
int main()
{
    TabDyn tabDyn;
    initialiser(&tabDyn);
    double a;

    printf("Entrez des nombres non-négatifs. "
	   "Pour terminer, entrez un nombre négatif.\n");
  
    do
    {
        scanf("%lf", &a);
        if (!ajouterElement(&tabDyn, a))
            return -1;
    } while (a >= 0);
    imprimerTabDyn(tabDyn);
    libererMemoire(&tabDyn);
}

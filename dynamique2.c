#include <stdio.h>
#include <stdlib.h>

// variables globales, elles sont enregistrees dans la memoire statique
const int TAILLE = 10;

// ***********************************************************
// void imprimerTableau(int* tableau)
//
// Imprime le tableau a la console. Sa taille doit etre TAILLE
//
// INPUT : un tableau de taille TAILLE.
//
// ***********************************************************
void imprimerTableau(int* tableau)
{
    if (NULL == tableau)
    {
	printf("Le tableau est nul.\n");
    }
    else
    {
	printf("Contenu du tableau a l'adresse %p : \n", tableau);
	for (int j = 0; j < TAILLE; j++)
	{
	    printf("  %d^e case = %d\n", j, tableau[j]); 
	}
    }
    printf("\n");
}

// ***********************************************************
// int* fabriquerTableauPile()
//
// Fabrique un tableau dans la pile et met les nombres 1 a
// TAILLE dedans.
//
// Retourne l'adresse du tableau dans la pile.
//
// ***********************************************************
int* fabriquerTableauPile()
{
    int tableauPile[TAILLE];
  
    for (int j = 0; j < TAILLE; j++)
    {
	tableauPile[j] = j;
    }

    printf("***** Impression du tableau automatique dans fabriquerTableauPile ***** \n");
    imprimerTableau(tableauPile);


    return tableauPile;
}

//************************************************************

void fabriquerTableau(int* t)
{
  
    for (int j = 0; j < TAILLE; j++)
    {
    t[j] = j;
    }

    printf("***** Impression du tableau automatique dans fabriquerTableauPile ***** \n");
    imprimerTableau(t);


}



//************************************************************

// ***********************************************************
// int* fabriquerTableauTas()
//
// Fabrique un tableau dans le tas et met les nombres TAILLE a
// 1 dedans.
//
// Retourne l'adresse du tableau dans le tas.
//
// ***********************************************************


int* fabriquerTableauTas()
{
    int * tableauTas = (int *)malloc(TAILLE * sizeof(int));
    if (NULL == tableauTas)
    {
	fprintf(stderr, "malloc a échoué\n");
	return NULL;
    }
    for (int j = 0; j < TAILLE; j++)
    {
	tableauTas[j] = TAILLE - j; 
    }
    printf("***** Impression du tableau dynamique dans fabriquerTableauTas *****\n");
    imprimerTableau(tableauTas);
    return tableauTas;
}
    
// ***********************************************************
// int main()
//
// Appelle les deux fonctions de creation de tableau et imprime
// les tableaux recus.
//
// ***********************************************************
int main()
{

    int* tabPile = fabriquerTableauPile();
    int* tabTas = fabriquerTableauTas();


    int* tabPile = (int *)malloc(TAILLE * sizeof(int));


    printf("*************** Impression du tableaux 1 ***************\n");
    imprimerTableau(tabPile);
    int tableauMain[TAILLE];
    imprimerTableau(tabTas);

    fabriquerTableau(tableauMain);
    printf("*************** Impression du tableaux 2 ***************\n");
    imprimerTableau(tableauMain);

    //===== A) Quelle est l’adresse du pointeur tableauPile dans fabriquerTableauPile?
    printf("l’adresse du pointeur tableauPile %p \n", &tabPile);

    //===== B) Quelle est l’adresse du pointeur tableauTas dans fabriquerTableauTas?
    printf("l’adresse du pointeur tableauTas %p\n", &tabTas);

    //===== C) C) Quelle est l’adresse de la fonction imprimerTableau?
    printf("l’adresse de la fonction imprimerTableau %p\n", &imprimerTableau);

    //===== D) Quelle est l’adresse de la variable globale TAILLE?
    printf("l’adresse de la variable globale %p\n", &TAILLE);


    free(tabTas);
    return 0;
}

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
	printf("Le tableau est nul.\n");
    else
    {
	printf("%p : ", tableau);
	for (int j = 0; j < TAILLE; j++)
	  printf("%d%s", tableau[j], ((j == TAILLE - 1) ? "\n" : ", ")); 
    }
}

// ***********************************************************
// int* remplirTableauPile()
//
// Remplit un tableau plus bas dans la pile et met les nombres 10 à TAILLE*10
// dedans.
//
// ***********************************************************
void remplirTableauPile(int* tableauPile)
{ 
    for (int j = 0; j < TAILLE; j++)
	tableauPile[j] = j * 10;

    printf("\n***** Impression du tableau automatique dans remplirTableauPile ***** \n");
    imprimerTableau(tableauPile);
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
	tableauPile[j] = j;

    printf("\n***** Impression du tableau automatique dans fabriquerTableauPile ***** \n");
    imprimerTableau(tableauPile);

    return tableauPile;
    
    // Réponse à la question H
    // Durée de vie (mémoire) : de la déclaration à la fin du bloc
    // Portée (nom) : de la déclaration à la fin du bloc
}

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
	tableauTas[j] = TAILLE - j; 
    printf("\n***** Impression du tableau dynamique dans fabriquerTableauTas *****\n");
    imprimerTableau(tableauTas);
    return tableauTas;
    
    // Réponse à la question G
    // Si on libère tableauTas ici, alors il n'existe plus dans le main.

    // Réponse à la question I
    // Durée de vie (mémoire) : du malloc au free
    // Portée (nom) : de la déclaration à la fin du bloc
}

// ***********************************************************
// int f()
//
// Fonction récursive qui sert à faire déborder la pile.
//
// ***********************************************************
int f()
{
  printf("f ");
  f();
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
    int* tabPileHaute = fabriquerTableauPile();
    int* tabTas = fabriquerTableauTas();
    int tabPileBasse[TAILLE];
    remplirTableauPile(tabPileBasse);

    printf("\n*************** Impression des tableaux dans le main ***************\n");
    imprimerTableau(tabPileHaute);
    imprimerTableau(tabTas);
    imprimerTableau(tabPileBasse);

    printf("\n*************** Réponses aux questions théoriques ***************\n");
    
    // Réponses aux questions A à D
    printf("\ntabPileHaute = %p\n", tabPileHaute); // Pile
    printf("tabTas = %p\n", tabTas); // Tas
    printf("&imprimerTableau = %p\n", &imprimerTableau); // Data statique
    printf("&TAILLE = %p\n", &TAILLE); // Data statique

    free(tabTas);
    
    // Réponse à la question E
    printf("\nIl faut %lu octets (%lu bits) pour stocker une adresse.\n",
	   sizeof(void*), sizeof(void*) * 8);

    
    // Réponse à la question F
    const int GRANDE_TAILLE = 100;
    int* valeursTasMalloc = (int*)malloc(GRANDE_TAILLE * sizeof(int));
    float* valeursTasCalloc = (float*)calloc(GRANDE_TAILLE, sizeof(float));
    char valeursPile[GRANDE_TAILLE];

    printf("\nAvec malloc, les valeurs ne sont pas nécessairement initialisées : ");
    for(int i = 0; i < GRANDE_TAILLE; i++)
        printf("%d ", valeursTasMalloc[i]);

    printf("\nAvec calloc, les valeurs sont initialisées à 0 : ");
    for(int i = 0; i < GRANDE_TAILLE; i++)
        printf("%.1f ", valeursTasCalloc[i]);

    
    printf("\nDans la pile, les valeurs ne sont pas nécessairement initialisées : ");
    for(int i = 0; i < GRANDE_TAILLE; i++)
        printf("%c", valeursPile[i]);

    free(valeursTasMalloc);
    free(valeursTasCalloc);

    printf("\n");


    // Débordement de la pile :
    // f();

    // Débordement du tas : (Risque de faire planter votre OS)
    // for (;;)
    // {
    //     int* x = (int*)malloc(sizeof(int) * 1000000);
    //     printf("malloc ");
    // }
    
    return 0;
}

// ****************************************************************************
// Nom : retirerNoeud.c
// Auteur : Rébecca
// Date : 12 novembre 2018
//
// Solution à l'exercice de retrait dans une liste doublement chaînée
// ****************************************************************************
#include <stdlib.h>
#include <stdio.h>

typedef struct Noeud Noeud;
struct Noeud{
   Noeud* precedent;
   int donnee;
   Noeud* suivant;
};

typedef struct Queue Queue;
struct Queue{
   Noeud* premier;
};


// ****************************************************************************
// void imprimerQueue(Queue queue)
// 
// Imprime les éléments d'une liste doublement chaînée
//
// INPUT
//    queue : la liste doublement chaînée à imprimer
// ****************************************************************************
void imprimerQueue(Queue queue)
{
	Noeud* n = queue.premier;
	while(n != NULL)
	{
		printf("%d ", n->donnee);
		n = n->suivant;
	}
	printf("\n");	
}

// ****************************************************************************
// void retirerValeur(Queue* queue, int valeur)
// 
// Retire tous les noeuds dont la donnée vaut valeur de la liste doublement
// chaînée. 
//
// INPUT
//    queue : Une référence vers la liste doublement chaînée
//    valeur : La valeur à retirer
// ****************************************************************************
void retirerValeur(Queue* queue, int valeur)
{
	Noeud* n = queue->premier;
	while (n != NULL)  // Parcours de la liste doublement chaînée
	{
		if (n->donnee == valeur)
		{
			if (n->suivant != NULL)
				(n->suivant)->precedent = n->precedent;
			if (n->precedent != NULL)
				(n->precedent)->suivant = n->suivant;
			else
				queue->premier = n->suivant; // On a retiré la tête!
		}
		n = n->suivant;
	}
}
// ****************************************************************************
// int main()
//
// Fonction pilote pour tester retirerValeur
// ****************************************************************************
int main()
{
	Noeud premier;
	premier.donnee = 20;
	Noeud deuxieme;
	deuxieme.donnee = 10;
	Noeud troisieme;
	troisieme.donnee = 44;
	premier.precedent = NULL;
	premier.suivant = &deuxieme;
	deuxieme.precedent = &premier;
	deuxieme.suivant = &troisieme;
	troisieme.precedent = &deuxieme;
	troisieme.suivant = NULL;

	Queue q;
	q.premier = &premier;

	const int RETRAIT = 44;
	printf("Avant le retrait des noeuds de valeur %d : ", RETRAIT);
	imprimerQueue(q);
	printf("Après le retrait des noeuds de valeur %d : ", RETRAIT);
	retirerValeur(&q, 44);
	imprimerQueue(q);
}
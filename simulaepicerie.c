#include<stdio.h>
#include<stdlib.h>



typedef struct Client Client;
struct Client
{
	int nbArticles;
	int arrivee;
};
 

Client* creerClientDyn(int instant, int nbArticles)
{
	Client* c = (Client*)malloc(sizeof(Client));
	c->arrivee = arrivee;
	c->nbArticles = nbArticles;
	return c;
}

int main()
{


	Client* c = creerClient(1, 21);

	printf("%d %d\n", c->arrivee, c->nbArticles);

	// Creer 100 clients, avec un nombrre d'articles aleatoire
	// imprimer les clients
	// Imprimer le nombre d'articles total, moyen, maximum et minimum.
	free(c);
}
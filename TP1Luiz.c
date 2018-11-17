//**************************************************************************************
//Auteur : Luiz Gustavo
//Fichier : TP1.c
//Date : 19 novembre 2018
//
//La structure de donnees "Queue"
//
//Vous allez implementer la structure de donnees Queue. Une queue suit le
//principe "premier arrive, premier servi".
//La queue sera composee de pointeurs vers des instances de la structure
//Client (dont les membres sont precises).
//La queue doit implementer les fonctionnalites offrirClient, coupDOeilTete,
//obtenirTete, longueurQueue et imprimerQueue.
//
//Les bonus sont mis en place.
//
//**************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define NOMBRE_DE_CYCLES 200
#define TAUX_ARRIVE_NOUVEAUX_CLIENTS 6
#define NOMBRE_ARTICLES_MOYEN_PANIER 10
#define PAUSE_PAR_CYCLE 100000
#define TAUX_IMPRESSION_CAISSES 1
#define LAMBDA 0.1
#define MIN 1
#define CHANCE 3
#define MAX_CAISSE 4

typedef struct Client Client;
struct Client{ 
	int caisse;
	int cycleArrive;
	int nombreArticles;
	int patience;	
	Client* ensuite;
	};
typedef struct Queue Queue;
struct Queue{	
	Client* client;	
	};
	
int cycle;
enum caisse {CAISSE1, CAISSE2, CAISSE3, CAISSE4, CAISSE5};


void offrirClient(Queue* queue, Client* client);
Client* coupDOeilTete(Queue queue);
Client* obtenirTete(Queue* queue);
int longueurQueue(Queue queue);
void imprimerQueue(Queue queue);

double randExpo(double lambda);
Client* ajouterPanierClient();
int piger(int min, int max);
void creerAttente(Queue* queue);
void imprimerSimulationnToutQueues(Queue queue);
void imprimerSimulationnUnQueue(Queue queue);

int main()
{
	int arriveNouveauClients;
	Queue queue;
	queue.client = NULL;
		
	for(cycle = 1; cycle <= NOMBRE_DE_CYCLES; cycle++)
	{	
		for(arriveNouveauClients = 0; arriveNouveauClients < TAUX_ARRIVE_NOUVEAUX_CLIENTS; arriveNouveauClients++)
		{
			if(piger(MIN, TAUX_ARRIVE_NOUVEAUX_CLIENTS) == CHANCE) offrirClient(&queue, ajouterPanierClient());	
		}						
		usleep(PAUSE_PAR_CYCLE);			
	}	
}
//****************************************************************************
//
// Ajoute le client a la fin de queue.
//
//****************************************************************************
void offrirClient(Queue* queue, Client* client)
{
	Client* bClient;
	if((queue == NULL) && (client->nombreArticles != 0))
	{
		queue->client = client;
	}
	else if(client->nombreArticles != 0)
	{
		bClient = queue->client;
		while(bClient != NULL)
		{			
			bClient = bClient->ensuite;
		}
		bClient = client;
	}
}
//***************************************************************************
//
// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
//
//****************************************************************************
Client* coupDOeilTete(Queue queue)
{
	if(queue.client == NULL) return NULL;
	else return queue.client;
}
//***************************************************************************
//
// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
//
//****************************************************************************
Client* obtenirTete(Queue* queue)
{

}
//***************************************************************************
//
// Retourne le nombre de clients dans la queue.
//
//****************************************************************************
int longueurQueue(Queue queue)
{
	
}
//***************************************************************************
//
// Imprime chaque client de la queue.
//
//****************************************************************************
void imprimerQueue(Queue queue)
{
	
}
//***************************************************************************
//
//La fonction double randExpo(double lambda) retourne un naturel
//au hasard, selon la distribution exponentielle d'esperance 1/lambda.
//
//****************************************************************************
double randExpo(double lambda)
{
double u = rand() / (RAND_MAX + 1.0);
return -log(1 - u) / lambda;
}
//***************************************************************************
//
// Retourne un nombre aléatoire entre min et max.
//
//****************************************************************************
int piger(int min, int max)
{
	return rand() % max + min;
}
//***************************************************************************
//
// Ajouter le panier au client.
//
//****************************************************************************
Client* ajouterPanierClient()
{
	int nombreArticles;
	Client* nouveauClient = malloc(sizeof(Client));
	if(!nouveauClient)
	{
		printf(" ERREUR D'ALLOCATION, HEAP FULL!\n");	
	}
	nombreArticles = randExpo(LAMBDA);
	if(nombreArticles <= 5)
	{
		nouveauClient->caisse = CAISSE5;
	}
	else nouveauClient->caisse = piger(MIN, MAX_CAISSE);	
	nouveauClient->cycleArrive = cycle;
	nouveauClient->nombreArticles = randExpo(LAMBDA);
	nouveauClient->patience = piger(MIN, NOMBRE_DE_CYCLES);	
	nouveauClient->ensuite = NULL;
	return nouveauClient;
}

	

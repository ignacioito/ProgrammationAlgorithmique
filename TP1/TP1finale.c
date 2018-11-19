#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define MIN 3
#define MAX 3
#define CICLOMAX 200
#define CHANCE 3
#define LAMBDA 0.1

int ciclo = 0;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

typedef struct Client Client;
  struct Client{

  	int instant;
  	int nbArticle;
  	Client* suivant;
   
   };
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
typedef struct Queue Queue;
  struct Queue{

  	Client* premiere;

 };


double randExpo(double lambda);
Client* nouveauClient ();
void offrirClient(Queue* queue, Client* client);
Client* coupDOeilTete(Queue queue);
Client* obtenirTete(Queue* queue);
int longueurQueue(Queue queue);
void imprimerQueue(Queue queue);
int fonctionPiger();

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------


double randExpo(double lambda)
{
  		double u = rand() / (RAND_MAX + 1.0);
  		return -log(1 - u) / lambda;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
Client* nouveauClient ()
{

  Queue queueCaisse1;
  Queue queueCaisse2;
  Queue queueCaisse3;
  Queue queueCaisse4;

  int ciclo;
	
	Client* nouveauClient = (Client*)malloc(sizeof(Client));
	nouveauClient->instant = ciclo;
  nouveauClient->nbArticle = randExpo(LAMBDA) + 1;
  nouveauClient->suivant = NULL;
  return nouveauClient;

  while ((ciclo < CICLOMAX)) 
  {
    int nombre = rand() % MAX + MIN;     
    if (nombre == CHANCE)
    {
      if(longueurQueue(queueCaisse1) == 0) offrirClient(&queueCaisse1, nouveauClient);
      if(longueurQueue(queueCaisse2) == 0) offrirClient(&queueCaisse2, nouveauClient);
      if(longueurQueue(queueCaisse3) == 0) offrirClient(&queueCaisse3, nouveauClient);
      if(longueurQueue(queueCaisse4) == 0) offrirClient(&queueCaisse4, nouveauClient);

      if (longueurQueue(queueCaisse1) < longueurQueue(queueCaisse2) && longueurQueue(queueCaisse1) < longueurQueue(queueCaisse3) && longueurQueue(queueCaisse1) < longueurQueue(queueCaisse4))
      {offrirClient(&queueCaisse1, nouveauClient);}

      if (longueurQueue(queueCaisse1) > longueurQueue(queueCaisse2) && longueurQueue(queueCaisse2) < longueurQueue(queueCaisse3) && longueurQueue(queueCaisse2) < longueurQueue(queueCaisse4))
      {offrirClient(&queueCaisse2, nouveauClient);}

      if (longueurQueue(queueCaisse1) > longueurQueue(queueCaisse2) && longueurQueue(queueCaisse2) > longueurQueue(queueCaisse3) && longueurQueue(queueCaisse3) < longueurQueue(queueCaisse4))
      {offrirClient(&queueCaisse3, nouveauClient);}

      if (longueurQueue(queueCaisse1) > longueurQueue(queueCaisse2) && longueurQueue(queueCaisse2) > longueurQueue(queueCaisse3) && longueurQueue(queueCaisse3) > longueurQueue(queueCaisse4))
      {offrirClient(&queueCaisse4, nouveauClient);} 
      
    }
    ciclo++;
  }

}


// Etat des fonctions et des pointeurs
// Ajoute le client a la fin de queue.
void offrirClient(Queue* queue, Client* client)
{
  Client* auxClient;	
  if(queue == NULL)
  {
  	queue = (Queue*)malloc(sizeof(Queue));
  	queue->premiere = client;	
  }
  else
  	auxClient = queue->premiere;
  	while(auxClient->suivant != NULL)
  	{
  		auxClient = auxClient->suivant;
  	}
  		auxClient->suivant = client;
}

// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* coupDOeilTete(Queue queue)
{
  if(queue.premiere == NULL) return NULL;
  else return queue.premiere;
}

// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* obtenirTete(Queue* queue)
{
 	Client* auxClient;
  if(queue->premiere == NULL) return NULL;
  else
  	auxClient = queue->premiere;
  	queue->premiere = queue->premiere->suivant;
  	free(auxClient);
  	return queue->premiere;
 }
  // Retourne le nombre de clients dans la queue.
int longueurQueue(Queue queue)
{
 	int conteur = 0;
 	Client* auxClient;
 	if(queue.premiere == NULL) return 0;
 	else
 	
  while(auxClient->suivant != NULL)
  {
  	auxClient = auxClient->suivant;
  	conteur++;
  }	
  	return conteur;
}

// Imprime chaque client de la queue.
void imprimerQueue(Queue queue) 
{
  Client* auxClient;
 	if(queue.premiere == NULL) printf("[]");
 	else
 		
  while(auxClient->suivant != NULL)
  {
  	printf("[{cycle #%d, %d articles}]", ciclo, queue.premiere->nbArticle);
  	auxClient = auxClient->suivant;
  }
  		
}

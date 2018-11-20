//**************************************************************************************
//Auteur : Ignacio Ito
//Fichier : TP1.c
//Date : 19 novembre 2018
//
//La structure de donnees "Queue"
//
//Vous allez implementer la structure de données Queue. Une queue suit le
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
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "TP1finale.h"





Client* nouveauClient ()
{
  Client* client = (Client*) malloc(sizeof(Client));
  client->suivant = NULL;
  client->instant = 0;
  client->nbArticle = 0;
  
  return client;
}


void commencer(Queue* caisse[])
{
  for(int i=0; i<4; i++)
  {
    caisse[i] = (Queue*) malloc(sizeof(Queue));
    caisse[i]->premiere = NULL;
    caisse[i]->derniere = NULL;
  }
}

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
void epicerie ()
{

  Queue* caisse[4];

  
  srand(time(NULL));
  commencer(caisse);

  int ciclo = 0;
  int tecla = 0;
  
  
  while (ciclo < CICLOMAX) 
  {
    system("clear");  
    ciclo++;
    int nombre = rand() % MAX + MIN;     
    int PG[] = {0,0,0,0};
    if (nombre == CHANCE)
    {
      Client* client = (Client*) malloc(sizeof(Client));
      client->instant = ciclo;
      client->nbArticle = randExpo(LAMBDA) + 1;
      client->suivant = NULL;

      PG[0] = longueurQueue(caisse[0]);
      PG[1] = longueurQueue(caisse[1]);
      PG[2] = longueurQueue(caisse[2]);
      PG[3] = longueurQueue(caisse[3]);
        

      int minimum = PG[0];
      int indice = 0;

      for (int i = 0; i < 4; ++i)
      {
        if(PG[i] < minimum)
        {
          minimum = PG[i];
          indice = i;
        }
      }
        offrirClient(caisse[indice], client);
      }
  
    ciclo++;

    for (int j = 0; j < 4; ++j)
    {
      printf("Caisse %d", j+1);
      imprimerQueue(caisse[j]);
      printf("\n");
    }

    sleep(arreteParCycle); 
        
    }


}
// Fonction pour faire le calcul des statistiques
void statistiquesQueue(Queue* queue, Client* client)
{
      printf("STATISTIQUES:\n");
      printf("Nombre de clients entrés  : \n" );
      printf("Nombre d'articles vendus  : \n");
      printf("Temps d'attente moyen     : \n");
      printf("Temps d'attente maximum   : \n");
      printf("Nombre d'articles maximum : \n");
      printf("Nombre d'articles minimum : \n");
      printf("Nombre d'articles moyen   : \n");   
}

// Etat des fonctions et des pointeurs
// Ajoute le client a la fin de queue.
void offrirClient(Queue* queue, Client* client)
{
  Client* auxClient = queue->premiere;
  if (auxClient == NULL)
  { 
    queue->premiere = client;
    queue->derniere = client; 
  }
  else
  {
    queue->derniere->suivant = client;
    queue->derniere = client;
  }

}

// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* coupDOeilTete(Queue queue)
{
  return queue.premiere;
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
int longueurQueue(Queue* queue)
{
 	int conteur = 0;
 	Client* auxClient = queue->premiere; 	
  while(auxClient != NULL)
  {
  	conteur++;
    auxClient = auxClient->suivant;
  }	
  	
  return conteur;
}

// Imprime chaque client de la queue.
void imprimerQueue(Queue* queue) 
{
  Client* auxClient = queue->premiere;

  printf("[");
 		
  while(auxClient != NULL)
  {
  	printf("[{cycle #%d, %d articles}]", auxClient->instant, auxClient->nbArticle);
  	auxClient = auxClient->suivant;
  }
  		
  printf("]");    
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN 1
#define MAX 6
#define CICLO 10
#define CHANCE 3


typedef struct Client Client;
struct Client{

  int instant;
  int nbArticle;
  Client* suivant;

};

typedef struct Queue Queue;
struct Queue{

  Client* premiere;

};

void nouveauClient ();
void fonctionPiger();
double randExpo(double lambda);
void offrirClient(Queue* queue, Client* client);
void imprimerQueue(Queue queue);
  
 // Ajoute le client a la fin de la queue.


void nouveauClient (){
		
	Queue queue;
	queue.premiere = NULL;

     	
    if (fonctionPiger(MIN,MAX) == CHANCE)
    {
     	Client* nouveauClient = (Client*)malloc(sizeof(Client)); //cree client

			nouveauClient->suivant = NULL;
     	nouveauClient->instant = i;
     	nouveauClient->nbArticle = randExpo (0.1);
     	offrirClient (&queue, nouveauClient);
    }



    if(*nouveauClient == 0)
    {
     	free (*nouveauClient);
    }

      imprimerQueue(queue);
    

     
}

//--------------------------------------------------------------------------

int fonctionPiger(int a, int b){


  for (int i = 0; i < CICLO; ++i)
  {
    int n = rand() % MAX + MIN;
}
  return n;

}

//--------------------------------------------------------------------------

double randExpo(double lambda)
{
  double u = rand() / (RAND_MAX + 1.0);
  return -log(1 - u) / lambda;
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------



void offrirClient(Queue* queue, Client* client)
{

  if (queue->premiere == NULL)
  {
  	queue->premiere = client; // se o primeiro da fila tiver NULL tem espaço para coloca-lo ali na filha
  }
  else{

  	Client* temporaire = queue->premiere; // 
  			
  	while (temporaire->suivant != NULL)
		{
  		temporaire = temporaire->suivant;
  	}
  			temporaire->suivant = client;
  	}
 
  
}
// essa funçao observa s fila, se o primeiuro é nulo significa que nao tem ninguem na fila e ele recebe cliente
// o cliente aponta para o proximo. enquanto o  

// Ici nous avons couru un pour pour pour la première fois remplir le tableau contenant
// les valeurs des données du premier coup.
   

// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.

Client* coupDOeilTete(Queue queue){

  if(queue.premiere == NULL){
    return NULL;
  }
  else{
    return queue.premiere;
  }
    
}

// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.

Client* obtenirTete(Queue* queue){

  Client* clientAux;

  clientAux = queue->premiere;

  queue->premiere = clientAux->suivant;

  free(clientAux);

  return queue->premiere;
}
  

// Retourne le nombre de clients dans la queue.

int longueurQueue(Queue queue)
{
  int c;
  Client* clientAux;
  clientAux->premiere;
  while(clientAux->premiere != NULL){
    clientAux = clientAux->premiere;
    c = c + 1;
  }
  return c;
}
// Imprime chaque client de la queue.
  

void imprimerQueue(Queue queue)
{
 	Client* temporaire = queue.premiere;
  
  while (temporaire != NULL)
	{
  	printf("valeur %d", temporaire->nbArticle);
  	temporaire = temporaire->suivant;
  				
  	//
  }
  				
  					
}

  int main ()
  {
  
  	nouveauClient();
  	
  }
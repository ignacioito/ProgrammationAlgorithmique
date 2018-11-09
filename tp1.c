#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 6
#include <math.h>

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
double randExpo(double lambda);
void offrirClient(Queue* queue, Client* client);
void imprimerQueue(Queue queue);
  
 // Ajoute le client a la fin de queue.


   void nouveauClient (){
		
		Queue queue;
		queue.premiere = NULL;

  	for (int i = 0; i < 200; ++i)
  	{
  		int n = rand() % MAX + MIN;
     	
     	if (n == 3)
     	{
     		Client* nouveauClient = (Client*)malloc(sizeof(Client));
 //cree client 
			nouveauClient->suivant = NULL;
     		nouveauClient->instant = i;
     		nouveauClient->nbArticle = randExpo (0.1);
     		offrirClient (&queue, nouveauClient);
     	}

     	/*if(queue->premiere->nbArticle == 0)
     	{
     		free (*premiere);
     	}*/
     	imprimerQueue(queue);
     }

     
 }

//--------------------------------------------------------------------------

	double randExpo(double lambda)
	{
  		double u = rand() / (RAND_MAX + 1.0);
  		return -log(1 - u) / lambda;
	}

//--------------------------------------------------------------------------



  void offrirClient(Queue* queue, Client* client)
 {

  	if (queue->premiere == NULL)
  		{
  		queue->premiere = client;
  		}
  		
  	else 

  	{
  		Client* temporaire = queue->premiere;
  			
  		while (temporaire->suivant != NULL)
		{
  			temporaire = temporaire->suivant;
  		}
  			temporaire->suivant = client;
  	}
 
  
}

// Ici nous avons couru un pour pour pour la première fois remplir le tableau contenant
// les valeurs des données du premier coup.
   

  // Retourne le premier client dans la queue.
  // Si la queue est vide, NULL est retourne.
  Client* coupDOeilTete(Queue queue);


  // Retire et retourne le premier client dans la queue.
  // Si la queue est vide, NULL est retourne.
  Client* obtenirTete(Queue* queue);


  // Retourne le nombre de clients dans la queue.
  int longueurQueue(Queue queue);

  // Imprime chaque client de la queue.
  

  void imprimerQueue(Queue queue)
 	{
 			Client* temporaire = queue.premiere;
  			while (temporaire->suivant != NULL)
			{
  				temporaire = temporaire->suivant;
  				printf("valor %d", temporaire->nbArticle);
  				printf("\n");
  			}
  				
  					
 	}

  int main ()
  {
  	nouveauClient();
  	
  }
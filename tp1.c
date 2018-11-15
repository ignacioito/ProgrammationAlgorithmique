#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN 1
#define MAX 6
#define CICLO 200
#define CHANCE 3


typedef struct Client Client;
  struct Client{

<<<<<<< HEAD
  	int instant;
  	int nbArticle;
  	Client* suivant;
=======
    int instant;
    int nbArticle;
    Client* suivant;
>>>>>>> 8870430a2c3eac328190b64d9d82f01985d6f081

   };

 typedef struct Queue Queue;
  struct Queue{

<<<<<<< HEAD
  	Client* premiere;
=======
    Client* premiere;
>>>>>>> 8870430a2c3eac328190b64d9d82f01985d6f081

   };

void nouveauClient ();
double randExpo(double lambda);
void offrirClient(Queue* queue, Client* client);
void imprimerQueue(Queue queue);
  
 // Ajoute le client a la fin de queue.


   void nouveauClient (){
<<<<<<< HEAD
		
		Queue queue;
		queue.premiere = NULL;

  	for (int i = 0; i < CICLO; ++i)
  	{
  		int n = rand() % MAX + MIN;
     	
     	if (n == CHANCE)
     	{
     		Client* nouveauClient = (Client*)malloc(sizeof(Client)); //cree client

			nouveauClient->suivant = NULL;
     		nouveauClient->instant = i;
     		nouveauClient->nbArticle = randExpo (0.1);
     		offrirClient (&queue, nouveauClient);
     	}



     	if(nouveauClient->nbArticle == 0)
     	{
     		free (*nouveauClient);
     	}

     	imprimerQueue(queue);
=======
    
    Queue queue;
    queue.premiere = NULL;

    for (int i = 0; i < CICLO; ++i)
    {
      int n = rand() % MAX + MIN;
      
      if (n == CHANCE)
      {
        Client* nouveauClient = (Client*)malloc(sizeof(Client)); //cree client

      nouveauClient->suivant = NULL;
        nouveauClient->instant = i;
        nouveauClient->nbArticle = randExpo (0.1);
        offrirClient (&queue, nouveauClient);
      }



      if(nouveauClient->nbArticle == 0)
      {
        free (nouveauClient);
      }

      imprimerQueue(queue);
>>>>>>> 8870430a2c3eac328190b64d9d82f01985d6f081
     }

     
 }

//--------------------------------------------------------------------------

<<<<<<< HEAD
	double randExpo(double lambda)
	{
  		double u = rand() / (RAND_MAX + 1.0);
  		return -log(1 - u) / lambda;
	}
=======
  double randExpo(double lambda)
  {
      double u = rand() / (RAND_MAX + 1.0);
      return -log(1 - u) / lambda;
  }
>>>>>>> 8870430a2c3eac328190b64d9d82f01985d6f081

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------



  void offrirClient(Queue* queue, Client* client)
 {

<<<<<<< HEAD
  	if (queue->premiere == NULL)
  		{
  		queue->premiere = client; // se o primeiro da fila tiver NULL tem espaço para coloca-lo ali na filha
  		}
  		
  	else 

  	{
  		Client* temporaire = queue->premiere; // 
  			
  		while (temporaire->suivant != NULL)
		{
  			temporaire = temporaire->suivant;
  		}
  			temporaire->suivant = client;
  	}
=======
    if (queue->premiere == NULL)
      {
      queue->premiere = client; // se o primeiro da fila tiver NULL tem espaço para coloca-lo ali na filha
      }
      
    else 

    {
      Client* temporaire = queue->premiere; // 
        
      while (temporaire->suivant != NULL)
    {
        temporaire = temporaire->suivant;
      }
        temporaire->suivant = client;
    }
>>>>>>> 8870430a2c3eac328190b64d9d82f01985d6f081
 
  
}
// essa funçao observa s fila, se o primeiuro é nulo significa que nao tem ninguem na fila e ele recebe cliente
// o cliente aponta para o proximo. enquanto o  

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
<<<<<<< HEAD
 	{
 			Client* temporaire = queue.premiere;
  			while (temporaire != NULL)
			{
  				printf("valor %d", temporaire->nbArticle);
  				temporaire = temporaire->suivant;
  				
  				//
  				printf("\n");
  			}
  				
  					
 	}

  int main ()
  {
  	nouveauClient();
  	
=======
  {
      Client* temporaire = queue.premiere;
        while (temporaire != NULL)
      {
          printf("valor %d", temporaire->nbArticle);
          temporaire = temporaire->suivant;
          
          //
          printf("\n");
        }
          
            
  }

  int main ()
  {
    nouveauClient();
    
>>>>>>> 8870430a2c3eac328190b64d9d82f01985d6f081
  }
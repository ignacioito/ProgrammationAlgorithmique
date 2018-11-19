//*****************************************
#pragma once
#define MIN 3
#define MAX 3
#define CICLOMAX 200
#define CHANCE 3
#define LAMBDA 0.1
#define arreteParCycle 10000

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

double randExpo(double lambda);

Client* nouveauClient ();

void offrirClient(Queue* queue, Client* client);

Client* coupDOeilTete(Queue queue);

Client* obtenirTete(Queue* queue);

int longueurQueue(Queue queue);

void imprimerQueue(Queue queue);


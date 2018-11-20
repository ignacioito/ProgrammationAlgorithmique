//*****************************************
#pragma once
#define MIN 3
#define MAX 3
#define CICLOMAX 20
#define CHANCE 3
#define LAMBDA 0.1
#define arreteParCycle 1

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


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

double randExpo(double lambda);

Client* nouveauClient();

void epicerie();

void offrirClient(Queue* queue, Client* client);

Client* coupDOeilTete(Queue queue);

Client* obtenirTete(Queue* queue);

int longueurQueue(Queue* queue);

void imprimerQueue(Queue* queue);


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

#pragma once
#define MIN 1
#define MAX 6
#define CICLOMAX 200
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
  	Client* derniere;

 };


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

double randExpo(double lambda);

Client* nouveauClient();

void epicerie();

void statistiquesQueueNBclietns(Queue* queue, Client* client);

void offrirClient(Queue* queue, Client* client);

Client* coupDOeilTete(Queue queue);

Client* obtenirTete(Queue* queue);

int longueurQueue(Queue* queue);

void imprimerQueue(Queue* queue);


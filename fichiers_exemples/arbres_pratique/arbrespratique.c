#include<stdio.h>
#include<stdlib.h>
#define MAX 2000
#define MIN 1
#define TAILLE 30

typedef struct Arbre Arbre;
struct Arbre{
	int donnee;
	Arbre* d;
	Arbre* g;
};

void genererArbre(Arbre** racine){
	*racine = NULL;
}

void inserirNoeud(Arbre** racine, int donnee){
	if(*racine==NULL)
	{
		(*racine)=(Arbre*)malloc(sizeof(Arbre));
		(*racine)->donnee = donnee;
		(*racine)->d = NULL;
		(*racine)->g = NULL;
	}
	else
	{
		if (donnee < (*racine)->donnee)
		{
			inserirNoeud(&(*racine)->g, donnee);
		}
		else
		{
			inserirNoeud(&(*racine)->d, donnee);
		}
	}
}

void parcourirArbre(Arbre* racine){
	if(racine != NULL){
		printf("* %d", racine->donnee);
		parcourirArbre(racine->d);
		parcourirArbre(racine->g);
	}
}


int main()
{
	Arbre* racine;
	genererArbre(&racine);

	for (int i = 0; i < TAILLE; ++i)
	{
		inserirNoeud(&racine, rand() % (MAX - MIN));
	}
	parcourirArbre(racine);

}










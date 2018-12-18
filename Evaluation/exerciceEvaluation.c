#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

typedef struct Palavra Palavra;
struct Palavra {
	char Mot[30];
};


void fonctionAssainir(Palavra inacio[5]){
	//
	char auxiliar[30];
	printf("Foi\n");
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			if (((inacio[i].Mot[j]) >= 65) && ((inacio[i].Mot[j]) <= 90))
			{
				strcpy(auxiliar, inacio[i].Mot[j]);
				printf("test %s", auxiliar);
			}
		}	
	}
	
	printf("test\n");
	printf("\n");

}


void meilleurMot(Palavra inacio[5]){
	int mao = 0;
	char tab[30];
	for (int i = 0; i < 5; ++i)
	{
		if (mao < strlen(inacio[i].Mot))
		{
			mao = strlen(inacio[i].Mot);
			strcpy(tab,inacio[i].Mot);
		}
	}
	printf("La majeur est %s\n", tab);
}


int main()
{
	//char Mot[20];
	Palavra inacio[5];
	//printf("Tapez le mot: \n");
	for (int i = 0; i < 5; ++i)
	{
		fgets(inacio[i].Mot, 30, stdin);

	}
	for (int j = 0; j < 5; ++j)
	{
		printf("%s\n", inacio[j].Mot);
	}
	
	fonctionAssainir(inacio);

	meilleurMot(inacio);
	
	
	return 0;
}
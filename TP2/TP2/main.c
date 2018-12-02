



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define BUFF 20
#define TAILLE 4

/**
 * \fn int lireFichier(char *filename)
 * \brief Lit un fichier texte ligne par ligne et imprime son contenu à la console.
 * \param filename Le nom du fichier
 */

/**
 * \Retiré du fichier lireFichier.c
 * \brief Lit un fichier texte ligne par ligne.
 * \author Rébecca Lapointe
 * \version 0.1
 * \date 22 octobre 2018
 *
 */

void genererGrille(){

	char grille[4][4];
	int indexL;
	int indexC;
	

	for(indexL = 0; indexL < TAILLE; indexL++)
	{
		for(indexC = 0; indexC < TAILLE; indexC++)
		{
			grille[indexL][indexC] = rand() % ('Z' - 'A' + 1) + 'A';
		}
	}

	for(indexL = 0; indexL < TAILLE; indexL++)
	{
		for(indexC = 0; indexC < TAILLE; indexC++)
		{
			printf(" %c ",grille[indexL][indexC]);
		}
		printf("\n");
	}
	
}

int lireFichier(char *filename, char motComplet[]){

	int a = 0;
	int b = 0;
	
    FILE *file = fopen(filename, "r");
    int nblines = 0;
  
    if (file == NULL )
      {
	perror("fopen");
	exit(1);
      }

    
    char mot[BUFF];
    while (fgets(mot, BUFF, file) != NULL) 
    {
	int l = strlen(mot);
	mot[l - 1] = '\0';
	printf("%s, ", mot);
    }
    
    fclose(file);
    return nblines;
}

int main()
{
	srand(time(NULL));
	char motComplet[18];
	genererGrille();
	gets(motComplet);
	if (lireFichier("francais.txt", motComplet) == 1) 
	{
		printf(" Le mot est là!\n");
	}
	else
	{
		printf(" Le mot n'est pas là!\n");
	}
	return 0;
}
/**
 * \file lireFichier.c
 * \brief Lit un fichier texte ligne par ligne.
 * \author Rébecca Lapointe
 * \version 0.1
 * \date 22 octobre 2018
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define BUFF 20
/**
 * \fn int lireFichier(char *filename)
 * \brief Lit un fichier texte ligne par ligne et imprime son contenu à la console.
 * \param filename Le nom du fichier
 */
int lireFichier(char *filename)
{
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


// Lit le fichier passé comme argument
int main(int argc, char** argv)
{
  lireFichier(argv[1]);
}

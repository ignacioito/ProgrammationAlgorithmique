// ****************************************************************************
// recursion.c
// 14 novembre 2018
// Rébecca
// Exercice avec la récursion
// ****************************************************************************


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ****************************************************************************
// void fonctionMystere(long n)
//
// Fonction mystère
// ****************************************************************************

int fonctionMystere(long n){
	if (n == 0)
	{
		return 0;
	}
	fonctionMystere(n / 2);
	printf("%ld", n % 2);

	return n;
}
// ****************************************************************************
// int palyndrome(char* c, int longueur)
//
// Détermine si une chaîne de caractères est un palyndrome
//
// INPUT :
//     c : Une chaîne de caractères
//     longueur : La longueur de c
//
// OUTPUT :
//     1 si c est un palyndrome, 0 sinon.
// ****************************************************************************

int palyndrome(char* c, int longueur)
{
	if ((longueur == 0) || (longueur == 1))
	{
		printf("C'est un palyndrome");
		printf("\n");
	}
		if ((*c == c[longueur - 1]) && palyndrome(c + 1, longueur - 2))
		{
			printf("C'est un palyndrome");
		    	printf("\n");
		}
    }

    
   
    //if (c[0] == c[longueur - 1]) return 1;
    //else return 0;


// ****************************************************************************
// void syracuse(long n)
//
// Imprime la suite de syracuse à partir de n
//
// INPUT :
//     n : premier nombre dans la suite à imprimer
// ****************************************************************************

int syracuse(long n){
	
	if (n == 1)
	{
		printf("%ld ", n);
		return 0;
	}
	printf("%ld ", n);
	if ((n % 2) == 0)
	{
		
		n = (n / 2);
		//printf("%ld ", n);
		syracuse(n);
	}
	else{
		n = ((n * 3) + 1);
		//printf("%ld ", n);
		syracuse(n);
	}
	return n;
}

// ****************************************************************************
// void parenthesageSuffixe(char* c, int longueur)
//
// Imprimer la chaîne c avec des parenthèse suffixe (a(b(c)))
//
// INPUT :
//     c : La chaîne de caractère à parenthéser
//     longueur : la longueur de c
// ****************************************************************************

void parenthesagePrefixe(char* c, int longueur)	
{


	if (longueur == 0)
		return;
		printf("(");
		parenthesagePrefixe(c, longueur - 1);
		printf("%c)", c[longueur - 1]);
		
	
}
// ****************************************************************************
// Fonction pilote pour tester la fonctionMystere, syracuse,
// palyndrome et les fonctions de parenthésage.
// ****************************************************************************

void parenthesageSuffixe(char* c, int longueur)
{
		
		if (longueur == 0)
		return;
		printf("(%c", c[0]);
		parenthesageSuffixe(c + 1, longueur - 1);
		printf(")");
}

// ****************************************************************************
// void parenthesagePrefixe(char* c, int longueur)
//
// Imprimer la chaîne c avec des parenthèse préfixe (((a)b)c)
//
// INPUT :
//     c : La chaîne de caractère à parenthéser
//     longueur : la longueur de c
// ****************************************************************************

int main()
{
	/*
	long n;
	for (;;)
	{
		printf("Tapez les nombre n: \n");
		scanf(" %ld", &n);
		syracuse(n);
		printf("\n");
	}
	*/


	char mot[255];
    int longueur;
    printf("Entrez un mot\n");
    fgets(mot, 255, stdin);
    mot[strlen(mot) - 1] = '\0';
    longueur = strlen(mot);

    parenthesagePrefixe(mot, longueur);
    printf("\n");
    parenthesageSuffixe(mot, longueur);
    printf("\n");
    printf("%s %s un palyndrome.\n", mot,
        (palyndrome(mot, longueur) ? "est" : "n'est pas"));

    long n = 1;
    printf("Entrez un nombre\n");
    scanf("%ld", &n);
    printf("Fonction mystère : ");
    fonctionMystere(n);
    printf("\nSuite de syracuse : ");
    syracuse(n);
    printf("\n");
	
}

























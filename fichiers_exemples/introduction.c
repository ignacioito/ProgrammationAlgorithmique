// *****************************************************************************
// Fichier : introduction.c
// Auteur : Rébecca
// Date : 26 octobre 2018
//
// Solution aux exercices du cours 1 de programmation algorithmique
// *****************************************************************************
#include <stdio.h>

#define PRECISION 0.001
#define BASE 10

enum Romain{M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1};

// *****************************************************************************
// double absolue(double x)
//
// Calcule la valeur absolue d'un double
//
// INPUT
//     x : un nombre réel
//
// OUTPUT
//     La valeur absolue de x
//
// *****************************************************************************
double absolue(double x)
{
    if (x < 0)
        x = -x;
    return x;
}

// *****************************************************************************
// double racine(double x)
//
// Calcule la racine carrée d'un double, à PRECISION pres
//
// INPUT
//     x : un nombre réel
//
// OUTPUT
//     La racine carrée de x, si x est positif, 0 sinon.
//
// Cette fonction implémente la méthode babylonienne
//
// *****************************************************************************
double racine(double x)
{
    if (x <= 0)
        return 0;
    double r = 10.0;
    while (absolue(r * r - x) > PRECISION * PRECISION)
        r = 0.5 * (r + (x / r));
    return r;
}

// *****************************************************************************
// int pgcd(int x, int y)
//
// Calcule le plus grand commun diviseur entre deux entiers.
//
// INPUT
//     x : un nombre entier
//     y : un nombre entier
//
// OUTPUT
//     Le plus grand commun diviseur (non-négatif) entre x et y
//
// Cette fonction implémente l'algorithme d'Euclide
//
// *****************************************************************************
int pgcd(int x, int y)
{
    while (y)
    {
        int t = y;
	y = x % y;
	x = t;
    }
    return absolue(x);
}

// *****************************************************************************
// int russe(int x, int y)
//
// Calcule le produit entre deux entiers.
//
// INPUT
//     x : un nombre entier
//     y : un nombre entier
//
// OUTPUT
//     Le produit x*y.
//
// Cette fonction implémente l'algorithme de multiplication à la russe en base 2
//
// *****************************************************************************
int russe(int x, int y)
{
    int a = absolue(x);
    int p = 0;
    while (a)
    {
        if ((a % 2))
	{
	    p = p + y;
	    a = a - 1;
	}
	a = a / 2;
	y = y * 2;
    }
    return ((x < 0) ? -p : p);
}

// *****************************************************************************
// int russeBase(int x, int y)
//
// Calcule le produit entre deux entiers.
//
// INPUT
//     x : un nombre entier
//     y : un nombre entier
//
// OUTPUT
//     Le produit x*y.
//
// Cette fonction implémente l'algorithme de multiplication à la russe en BASE.
//
// *****************************************************************************
int russeBase(int x, int y)
{
    int a = absolue(x);
    int p = 0;
    while (a)
    {
        int r = a % BASE;
	if (r)
	{
	    p = p + y * r;
	    a = a - r;
	}
	a = a / BASE;
	y = y * BASE;
    }
    return ((x < 0) ? -p : p);
}

// *****************************************************************************
// int romainADecimal(char* romain)
//
// Converti un nombre écrit en chiffres romains en nombre écrit en base
// décimale. 
//
// INPUT
//     romain : Une chaîne représentant un nombre écrit en chiffres romains.
//              cette chaîne doit être valide et terminer avec \n ou \0.
//
// OUTPUT
//     La valeur du nombre en décimal.
//
// *****************************************************************************
int romainADecimal(char* romain)
{
    int decimal = 0;
    for (int i = 0; romain[i] != '\n' && romain[i] != '\0'; i++)
    {
        switch(romain[i])
	{
	case 'M':
	    decimal += M;
	    break;
	case 'D' :
	    decimal += D;
	    break;
	case 'C' :
	    switch (romain[i + 1])
	    {
	    case 'M' :
	        decimal += M - C;
		i++;
		break;
	    case 'D':
	        decimal += D - C;
		i++;
		break;
	    default:
	        decimal += C;
	    }
	    break;
	case 'L' :
	    decimal += L;
	    break;
	case 'X' :
	    switch (romain[i + 1])
	    {
	    case 'C' :
	        decimal += C - X;
		i++;
		break;
	    case 'L':
	        decimal += L - X;
		i++;
		break;
	    default:
	        decimal += X;
	    }
	    break;
	case 'V' :
	    decimal += V;
	    break;
	case 'I' :
	    switch (romain[i + 1])
	    {
	    case 'X' :
	        decimal += X - I;
		i++;
		break;
	    case 'V':
	        decimal += V - I;
		i++;
		break;
	    default:
	        decimal += I;
	    }
	    break;
	}
    }
    return decimal;
}
	  
// *****************************************************************************
// Pilote pour les exercices
// *****************************************************************************
int main()
{
    printf("Entrez un nombre écrit en chiffres romains\n");
    char s[100];
    fgets(s, 100, stdin);
    printf("En décimal, ce nombre est %d\n", romainADecimal(s));
  
    printf("Entrez deux entiers.\n");
    int x, y;
    scanf("%d %d", &x, &y);
    
    printf("racine(%d) = %lf\n", x, racine(x));
    printf("racine(%d) = %lf\n", y, racine(y));
    
    printf("absolue(%d) = %d\n", x, (int)absolue(x));
    printf("absolue(%d) = %d\n", y, (int)absolue(y));
    
    printf("pgcd(%d,%d) = %d\n", x, y, pgcd(x,y));

    printf("russe(%d,%d) = %d\n", x, y, russe(x,y));
    printf("russeBase(%d,%d) = %d\n", x, y, russeBase(x,y));
}

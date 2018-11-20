// ****************************************************************************
// recursion.c
// 14 novembre 2018
// Rébecca
// Exercice avec la récursion
// ****************************************************************************
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ****************************************************************************
// void fonctionMystere(long n)
//
// Fonction mystère
// ****************************************************************************
void fonctionMystere(long n)
{
    if (n == 0)
        return;
    fonctionMystere(n/2);
    printf("%d", (int)(n%2));
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
    return 0;
}

// ****************************************************************************
// void syracuse(long n)
//
// Imprime la suite de syracuse à partir de n
//
// INPUT :
//     n : premier nombre dans la suite à imprimer
// ****************************************************************************
void syracuse(long n)
{

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
void parenthesageSuffixe(char* c, int longueur)
{

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
int main()
{
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
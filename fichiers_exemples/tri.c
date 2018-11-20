// ****************************************************************************
// tris.c
// 12 novembre 2018
// Rébecca
// Trois petits tris (insertion, sélection et bulle)
// ****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ****************************************************************************
// void imprimerTableau(int* tab, int n)
//
// Imprime le tableau reçu à la console
//
// INPUT :
//     tab : un tableau d'entier
//     n : la taille de tab
// ****************************************************************************
void imprimerTableau(int* tab, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d%s", tab[i], ((i < n - 1) ? ", " : "\n"));
}

// ****************************************************************************
// void echanger(int* a, int* b)
//
// Échange la valeur des entiers pointés par a et b.
//
// INPUT :
//     a : un pointeur vers un entier
//     b : un pointeur vers un deuxième entier
// ****************************************************************************
void echanger(int* a, int* b)
{
  int t = *b;
  *b = *a;
  *a = t;
}

// ****************************************************************************
// void triABulle(int* tab, int n)
//
// Tri tab selon l'algorithme de tri à bulle
//
// INPUT :
//     tab : un tableau d'entier
//     n : la taille de tab
// ****************************************************************************
void triABulle(int* tab, int n)
{
  int temoin = 1;
  while (temoin)
  {
    temoin = 0;
    for (int i = 1; i < n; i++)
      if (tab[i - 1] > tab[i])
      {
        echanger(tab + i - 1, tab + i);
        temoin = 1;
      }
    n--;
  }
}

// ****************************************************************************
// void triInsertion(int* tab, int n)
//
// Tri tab selon l'algorithme de tri par insertion
//
// INPUT :
//     tab : un tableau d'entier
//     n : la taille de tab
// ****************************************************************************
void triInsertion(int* tab, int n)
{
  for (int i = 1; i < n; i++)
    for (int j = i; (j > 0) && (tab[j - 1] > tab[j]); j--)
      echanger(tab + j, tab + j - 1);
}

// ****************************************************************************
// void triSelection(int* tab, int n)
//
// Tri tab selon l'algorithme de tri par sélection
//
// INPUT :
//     tab : un tableau d'entier
//     n : la taille de tab
// ****************************************************************************
void triSelection(int* tab, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
      if (tab[min] > tab[j])
        min = j;
    echanger(tab + i, tab + min);
  }
}

// ****************************************************************************
// Pilote pour tester les trois algorithmes de tri.
// ****************************************************************************
int main()
{
  srand(time(NULL));
  const int TAILLE = 20;
  int tab[TAILLE];
  for (int i = 0; i < 50; i++)
  {
    for (int i = 0; i < TAILLE; i++)
      tab[i] = rand() % TAILLE;
    switch (i % 3)
    {
      case 0 : triABulle(tab, TAILLE); break;
      case 1 : triInsertion(tab, TAILLE); break;
      case 2 : triSelection(tab, TAILLE); break;
    }
    imprimerTableau(tab, TAILLE);
  }
}
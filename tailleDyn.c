#include<stdio.h>
#include<stdlib.h>

#define BUFF 3
#

typedef struct TabDyn TabDyn;
struct TabDyn{
 double* tab;
 int dernier;
 int taille;
};

void initialiser(TabDyn* tabDyn){
	tabDyn -> tab = (double*)malloc(BUFF * sizeof(double));
	tabDyn -> dernier = 0;
	tabDyn -> taille = BUFF;
}

int ajouterElement(TabDyn* tabDyn, double e){
 tabDyn->tab[tabDyn->dernier] = e;
 tabDyn->dernier++;
 if(tabDyn->dernier >= tabDyn->taille)
 {
 	tabDyn->taille += BUFF;
 	tabDyn->tab = (double*)realloc(tabDyn->tab, tabDyn -> taille * sizeof(double));
	if (tabDyn -> tab == NULL)
	 	return 0; // On retourne FAUX, ajouter a échoué
 }
 return 1;
}

void libererMemoire(TabDyn* tabDyn){
	free(tabDyn);
}


void imprimerTableau(TabDyn tabDyn){
	for (int i = 0; i < tabDyn.dernier; ++i)
	{
		printf("%lf\n", tabDyn.tab[i]);
		printf("\n");
	}
}

int main()
{
	
	TabDyn tabDyn;
	initialiser(&tabDyn);
	double a;
	do{
 	scanf("%lf", &a);
 	if (!ajouterElement(&tabDyn, a))
 		return -1;
	}
	
	while (a >= 0);
	libererMemoire(&tabDyn);
}
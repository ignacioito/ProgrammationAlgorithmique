//
//

//Ignacio Ito

//
//

#include"stdio.h"
#include"stdlib.h"

void swapTab(char* a, char* b){
	char t = *a;
	*a = *b;
	*b = t;
}

void ordonnerBsort(char tab[], int x){

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if(tab[j] < tab[j -1]){
				swapTab(&tab[j], &tab[j - 1]);
			}
		}
	}

}

//trier par chaque 
void ordonnerIsort(char tab[], int x){
	
	int temp;

	for (int i = 0; i < x; ++i)
	{
		/* code */
	}



}

//trier par selection (compara o primeiro numero ate o ultimo)
void ordonnerSsort(char t[], int x){

	int min;
	int j;

	for (int a = 0; a < x; ++a)
	{

			min = a;
			j = a + 1;

		while(j < x){
			if (t[min] > t[j])
			{
				min = j;
			}
			j++;
		}
		swapTab(&t[a], t[min]);

	}
		
	
		
	}


int main()
{
	char tab[7] = {"BLOPVXB"};
	char tab1[7] = {"IGNACIO"};
	char tab2[7] = {"REBECCA"};

	ordonnerBsort(tab, 7);
	ordonnerIsort(tab1, 7);
	ordonnerSsort(tab2, 7);

	return 0;
}

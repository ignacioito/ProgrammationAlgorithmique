
#include<stdio.h>
#include<stdlib.h>
//Indentifier touts les variables et donnez leur type
//Lesquelles sont des pointeurs? Que fait le code? Remarquez-vous quelque
//chose dans les arguments à scanf?



int pgcd(int a, int b)
{
	return ((b == 0) ? a : pgcd(b, a % b));

/*	if (b == 0)
		return a;
	else
		return pgcd(b, a % b)	*/
}

void reduire(int* a, int* b)
{
	int p = pgcd(*a, *b);
	*a /= p;
	*b /= p;
}
void inverser (int* a, int* b){
	int temp = *b;
	*b = *a;
	*a = temp;

}
void ordonner(int* a, int* b, int* c){


	if(*b > *a){
		
		printf("%d %d\n", );
	}
	// abc
	// acb
	// bac
	// bca
	// cab
	// cba
}



int main()
{
int a, b;
scanf("tapez: %d %d\n", &a, &b);
 inverser(&a, &b);
printf("%d - %d\n", a, b);
}



#include<stdio.h>
#include<stdlib.h>
#define T 6

void triInsertion(char *n, int t){
	for (int i = 1; i < t; ++i)
	{
		char aux = n[i];
		for (int j = i; (j > 0) && (aux < n[j-1]); j--)
		{
			n[j] = n[j - 1];
			n[j - 1] = aux;
		}
	}
	for (int l = 0; l < t; ++l)
	{
		printf("%c\n", n[l]);
	}
}

int main()
{
	char v[]={"ANFGDK"};
	triInsertion(v, T);
	return 0;
}
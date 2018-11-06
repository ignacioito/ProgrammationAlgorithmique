#include<stdio.h>
#include<stdlib.h>
#define TAILLE 1000000

int count(int x){
	while(x < TAILLE){
		x++;
		printf("x vault: %d\n", x);
		count(x);
	}

}

int main()
{
	int a = 0;
	count(a);
}
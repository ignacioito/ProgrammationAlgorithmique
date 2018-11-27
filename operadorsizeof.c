#include<stdio.h>
#include<stdlib.h>
//Le sizeof retourne la taille exacte de bytes par rapport le tipe donné

// char: 1 byte
// int: 4 bytes
// float: 4 bytes
//double: 8 bytes


struct ponto{
	int x, y;
};

int main()
{
	printf("char: %d\n", sizeof(char)); 
	printf("int: %d\n", sizeof(int)); 
	printf("float: %d\n", sizeof(float)); 
	printf("double: %d\n", sizeof(double)); 
	printf("struct: %d\n", sizeof(struct ponto)); 
}
#include<stdio.h>
#include<stdlib.h>

/*
Fonction Malloc
Serve para alocar memória durante a execução do programa
Ela faz o pedido de memória ao computador e retorna um ponteiro com o endereço do inicio
do espaço de memória alocado.
*/

//Protótipo:
//void* malloc(unsigned int num);


int main()
{
/*
	Funcionamento:
	a função malloc() recebe por parâmetro 
	- a quantidade de bytes a ser alocada e retorna
	- NULL: no caso de erro
	-- ponteiro: para a primeira posição do array	
*/

	int *y = malloc(200);
	char *c = malloc(50);

	system("pause");
	return 0;
}

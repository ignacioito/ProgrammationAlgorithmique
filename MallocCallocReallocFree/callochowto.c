#include<stdio.h>
#include<stdlib.h>

/*
Fonction calloc():
Serve para alocar memória durante a execução do programa.
Ela faz o pedido de memória ao computador e retorna um ponteiro com o endereço do inicio
do espaço de memória alocado.
*/

//Protótipo:
//void* calloc(unsigned int num, unsigned int size);

/*
int main()
{

	//Funcionamento:
	//Na alocação da memória, deve-se levar em conta o tamanho do tipo.

	//Exemplo: criar um array de tamanho 50

	int *v = (int*) calloc(50, 4);
	char *c = malloc(50, 1);


	//solução: usar o sizeof()
	int *v = (int*)calloc(50, sizeof(int));
	char *c = (char*)calloc(50, sizeof(char));

	system("pause");
	return 0;
}
*/

int main()
{
	/*Se não houver memória suficiente para alocar a memória
	requisitada, a função calloc() retorna NULL */

	int *p;
	p = (int*) calloc(5,sizeof(int));
	if (p == NULL)
	{
		printf("Erro de memória! \n");
		exit(1); //termina o programa
	}
	int i;
	for (int i = 0; i < 5; ++i)
	{
		printf("Digite p[%d]: ", i);
		scanf("%d", &p[i]);
	}
	//libera a memória alocada:
	free(p);
	return 0;
}


/*
Sendo assim, qual é a diferença entre o malloc e o calloc?
A diferença além da ligeira diferença de sintaxe é que o malloc aloca a memória
com os espaços vazios. O calloc aloca a memória do mesmo jeito, mas preenche os
espaços com 0. (o malloc vai exibir números estranhos, lixo de memória: 23X8983)

*/



















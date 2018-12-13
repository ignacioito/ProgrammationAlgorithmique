#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

typedef struct Palavra Palavra;
struct Palavra {
	char Mot[30];
};

void fonctionAssainissement(char* Mot){
	//
	printf("Foi\n");
	for (int i = 0; i < strlen(Mot); ++i)
	{
		if ((Mot[i] >= 65) && (Mot[i] <= 90))
		{
			printf("%c", Mot[i]);
		}
	}
	printf("\n");

}

int main()
{
	char Mot[20];
	Palavra inacio[5];
	printf("Tapez le mot: \n");
	for (int i = 0; i < 4; ++i)
	{
		fgets(" %s", Mot);

	}
	fonctionAssainissement(Mot);
	
	
	return 0;
}
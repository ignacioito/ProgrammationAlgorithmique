/*



*/


#include<stdio.h>
#include<stdlib.h>


int mult(int x, int y){

	int r = 0;

	while(x != 0){
		if(x % 2 == 1){

			r = r + y;
			x = x - 1;

		}

		x = x / 2;
		y = y * 2;

	}

	return r;

}

int main()
{
	int x = 0;
	int y = 0;
	for (;;)
	{
		printf("Rentrez le nombre x: \n");
		scanf("%d", &x);
		printf("Rentrez le nombre y: \n");
		scanf("%d", &y);
	}

	return 0;

}
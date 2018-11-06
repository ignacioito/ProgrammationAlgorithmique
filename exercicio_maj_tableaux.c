 #include <stdio.h>

#define max 10

void preencher(int vet[]){

    printf("\n");

    for(int i=0; i<max; i++){
        printf("[%d]: ", i+1);
        scanf("%d", &vet[i]);
    }

    printf("\n");
}

void ordenarC(int vet[], int vet1[], int vet2[]){

    printf("\n");

    for(int cont=0; cont<max; cont++){

        if(vet1[cont] > vet2[cont]) vet[cont] = vet1[cont];
        else vet[cont] = vet2[cont];

         printf("\n[%d]", vet[cont]);
    }

    printf("\n");
}

int main(){

     int vetA[max], vetB[max], vetC[max], cont;

     printf("\nValores do vetor 1\n");
     preencher(vetA);

     printf("\nValores do vetor 2\n");
     preencher(vetB);

     printf("\nValores do vetor C");
     ordenarC(vetC, vetA, vetB);

     return 0;
}

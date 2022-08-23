#include <stdio.h>
#include <stdlib.h>
#define OK 0

int *alocaVetor(int tamanho){
    int *vetor;
    vetor = (int*) malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++){
        printf("%do valor do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    return vetor;
}

int main(int argc, char ** argv){

    int valor;
    int *vetor;

    printf("Informe o tamanho do vetor que quer alocar: ");
    scanf("%d", &valor);

    vetor = alocaVetor(valor);

    for(int i = 0; i < valor; i++){
        printf("Valor %d: %d\n", i+1, vetor[i]);
    }

    free(vetor);

    return OK;
}
#include <stdio.h>
#include <stdlib.h>
#define OK 0

void leVetor(float *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Informe %d valor: ", i+1);
        scanf("%f", &vetor[i]);
    }
}

float calculaMediaVetor(float *vetor, int tamanho){
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    return soma/tamanho;
}

int main(int argc, char ** argv){

    int tamanho;
    float *vetor, media;
    
    printf("\nCalcule a media - informe a quantidade de valores a calcular: ");
    scanf("%d", &tamanho);

    vetor = (float*) malloc(tamanho * sizeof(float));
    
    leVetor(vetor, tamanho);
    media = calculaMediaVetor(vetor, tamanho);

    printf("A media dos valores eh: %g", media);

    free(vetor);

    return OK;
}
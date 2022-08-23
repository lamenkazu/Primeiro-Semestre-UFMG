#include <stdio.h>
#include <stdlib.h>
#define OK 0

int main(int argc, char ** argv){

    int tamanho, indiceMaior, indiceMenor;
    float *vetor;
    float maior = -999999999, menor = 9999999999;


    //Aloca vetor do tamanho desejado
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    vetor = (float*) malloc(tamanho * sizeof(float));

    //Preenche vetor com valores do teclado
    for(int i = 0; i < tamanho; i++){
        printf("valor %d: ", i+1);
        scanf("%f", &vetor[i]);
    }

    //Descobre Maior e seu índice
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
            indiceMaior = i;
        }
    }

    //Descobre Menor e seu índice
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] < menor){
            menor = vetor[i];
            indiceMenor = i;
        }
    }
    
    printf("O menor valor eh %g na posicao %d do vetor\n", menor, indiceMenor);
    printf("O maior valor eh %g na posicao %d do vetor\n", maior, indiceMaior);

    free(vetor);
    


    return OK;
}
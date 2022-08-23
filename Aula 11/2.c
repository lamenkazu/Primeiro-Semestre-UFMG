#include <stdio.h>
#define OK 0
#define TAMANHO 3

float somaMatriz(float matriz[][TAMANHO]){
    float soma = 0;

    //Soma os elementos da matriz
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            soma += matriz[i][j];
        }
    }

    return soma;
}

int main(int argc, char ** argv){

    float matriz[TAMANHO][TAMANHO], resultado;

    //Preenche a Matriz
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            printf("Informe o [%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("A soma da matriz eh: %g\n", somaMatriz(matriz));
    
    return OK;
}
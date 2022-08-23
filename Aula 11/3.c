#include <stdio.h>
#define OK 0
#define TAMANHO 5


void multiplicaVetorMatriz(int vetor[], int matriz[][TAMANHO]){

    int produto = 0;
    //Multiplica todos os valorez do vetor por todos os valores da matriz e encontra um produto
    for(int i = 0;i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            for(int k = 0; k < TAMANHO; k++){
                produto += vetor[i] * matriz[j][k];
            }
        }
    }

    printf("O resultado da multiplicação eh: %d", produto);
}

int main(int argc, char ** argv){

    int vetor[TAMANHO], matriz[TAMANHO][TAMANHO];

    //Preenche o vetor com valores do teclado
    printf("Preencha o vetor: \n");
    for(int i = 0; i < TAMANHO; i++){
        printf("Informe o %d valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    //Preenche a matriz com valores do teclado
    printf("\nAgora preencha a matriz: \n");
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            printf("Informe o [%d][%d] valor: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    multiplicaVetorMatriz(vetor, matriz);

    return OK;
}
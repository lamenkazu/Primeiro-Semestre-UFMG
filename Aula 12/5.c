#include <stdio.h>
#include <stdlib.h>
#define OK 0

float *alocaMatriz(int x, int y){
    float ** matriz;

    matriz = (float**) malloc(x * sizeof(float*));
    if(matriz == NULL){
        printf("**Erro**");
        return 1;
    }
    for(int i = 0; i < x; i++){
        matriz[i] = (float*) malloc(y *sizeof(float));
        if(matriz[i] == NULL){
            printf("**Erro**");
            return 1;
        }
    }

    return matriz;
}

float somaMatriz(float **matriz, int x, int y){
    float soma = 0;

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            soma += matriz[i][j];
        }
    }

    return soma;
}

void leMatriz(float **matriz, int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("Informe valor [%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
}

int main(int argc, char ** argv){

    int x, y;
    float **matriz;

    printf("Informe o tamanho da matriz [x][y] \n[x]: ");
    scanf("%d", &x);
    printf("[y]: ");
    scanf("%d", &y);

    matriz = alocaMatriz(x,y);

    leMatriz(matriz, x, y);
    printf("A soma da matriz [%d][%d] eh: %g", x, y, somaMatriz(matriz, x, y));

    //Libera matriz alocada
    for(int i = 0; i < x; i++) free(matriz[i]);
    free(matriz);

    return OK;
}
#include <stdio.h>
#include <stdlib.h>
#define OK 0

float *alocaMatriz(int x, int y){

    float ** matriz;

    //Aloca primeira dimensão da matriz
    matriz = (float **) malloc(x * sizeof(float*));
    if(matriz == NULL){
        printf("**erro**");
        return 1;
    }

    //Aloca segunda dimensão da matriz
    for(int i = 0; i < x; i++){
        matriz[i] = (float*) malloc(y * sizeof(float));
        if(matriz[i] == NULL){
            printf("**erro**");
            return 1;
        }
    }

    //Preenche os valores da matriz no tamanho selecionado
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("[%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    return matriz;
}



int main(int argc, char ** argv){

    int x, y;
    float ** matriz;

    printf("Aloque uma matriz [x][y]. Informe o tamanho\n[x]: ");
    scanf("%d", &x);
    printf("[y]: ", &y);
    scanf("%d", &y);

    matriz = alocaMatriz(x,y);


    //Imprime os valores da matriz na tela;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("[%d][%d]: %g\n", i+1, j+1, matriz[i][j]);
        }
    }

    //Libera matriz
    for(int i = 0; i < x; i++){
        free(matriz[i]);
    }
    free(matriz);

    return OK;
}
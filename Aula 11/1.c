#include <stdio.h>
#define OK 0
#define TAMANHO_MATRIZ 5

void imprimeTransposta(int matriz[][TAMANHO_MATRIZ]){

    for(int i = 0; i < TAMANHO_MATRIZ; i++){
        
        //Se for primeira linha imprime. Se não, apenas pula linha
        if(i == 0){ 
            printf("Sua matriz transposta eh: \n");
        }else{
            printf("\n"); 
        }
        
        //Imprime matriz transposta
        for(int j = 0; j < TAMANHO_MATRIZ; j++){
            printf("%d ", matriz[j][i]);
        }
    }
    printf("\n");
    
}

int main(int argc, char ** argv){

    int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ];

    //Preenche a matriz
    printf("Informe os valores da matriz [%d][%d]:\n", TAMANHO_MATRIZ, TAMANHO_MATRIZ);
    for(int i = 0; i < TAMANHO_MATRIZ; i++){
        for(int j = 0; j < TAMANHO_MATRIZ; j++){
            printf("Informe valor[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    imprimeTransposta(matriz);


    return OK;
}
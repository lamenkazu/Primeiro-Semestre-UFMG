#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERRO_SEGMENTACAO 1


int * alocaMatriz(int produtos, int lojas){
    int ** matriz;

    matriz = (int **) malloc(produtos * sizeof(int*));
    if(matriz == NULL){
        printf("**Erro**");
        return ERRO_SEGMENTACAO;
    }
    
    for(int i = 0; i < produtos; i++){
        matriz[i] = (int *) malloc(lojas * sizeof(int));
        if(matriz[i] == NULL){
            printf("**Erro**");
            return ERRO_SEGMENTACAO;
        }
    }

    return matriz;
}

void leMatriz(int ** matriz, int produtos, int lojas){
    
    for(int i = 0; i < produtos; i++){
        for(int j = 0; j < lojas; j++){
            printf("Quantidade de produto %d da loja %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimeMatriz(int ** matriz, int produtos, int lojas){
    printf("\t\tLojas\n");
    for(int i = 0; i < produtos; i++){
        printf("Produto %d\t", i+1);
        for(int j = 0; j < lojas; j++){
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimeQuantidadeProdutos(int ** matriz, int produtos, int lojas){
    int posProduto = 0, soma;
    do{
        soma = 0;
        for(int i = 0; i < lojas; i++){
            soma += matriz[posProduto][i];
        }
        printf("Total do produto %d em todas as lojas: %d \n", posProduto+1, soma);
        posProduto++;
    }while(posProduto < produtos);
}

int lojaComMenosProdutos(int ** matriz, int produtos, int lojas){
    int lojaComMenos, soma, menor = 999999999;
    for(int i = 0; i < produtos; i++){
        soma = 0;
        for(int j = 0; j < lojas; j++){
            soma += matriz[i][j];
        }
        if(soma < menor){
            menor = soma;
            lojaComMenos = i + 1;
        }
    }

    return lojaComMenos;
}

int main(int argc, char ** argv){

    int qntLojas, qntProdutos;
    int **matriz;

    //Aloca matriz [Produtos] x [Lojas]
    printf("Quantas lojas tem a empresa? ");
    scanf("%d", &qntLojas);
    printf("Quantos produtos tem nessa empresa? ");
    scanf("%d", &qntProdutos);
    matriz = alocaMatriz(qntProdutos, qntLojas);

    //Utiliza procedimentos pra Ler e Imprimir
    leMatriz(matriz, qntProdutos, qntLojas);
    imprimeMatriz(matriz, qntProdutos, qntLojas);
    imprimeQuantidadeProdutos(matriz, qntProdutos, qntLojas);

    //Recebe resultado da função e imprime na tela
    int lojaComMenos = lojaComMenosProdutos(matriz, qntProdutos, qntLojas);
    printf("A loja que tem menos produtos eh %d", lojaComMenos);

    //Libera memoria alocada
    for(int i = 0; i < qntProdutos; i++) free(matriz[i]);
    free(matriz);

    return OK;
}
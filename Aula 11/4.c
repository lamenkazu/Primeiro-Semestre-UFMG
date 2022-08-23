#include <stdio.h>
#define OK 0

#define PRODUTOS 3
#define LOJAS 5

int main(int argc, char ** argv){

    int matriz[PRODUTOS][LOJAS];
    int soma, posProduto;
    int menor = 9999999, lojaComMenos;

    //Recebe Quantos produtos tem em cada loja
    for(int i = 0; i < PRODUTOS; i++){
        for(int j = 0; j < LOJAS; j++){
            printf("Informe a quantidade do produto %d da loja %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    //Imprime a tabela de relação (Produtos x Loja) - Pode virar Procedimento
    printf("\t\tLojas\n");
    for(int i = 0; i < PRODUTOS; i++){
        printf("Produto %d\t", i+1);
        for(int j = 0; j < LOJAS; j++){
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }

    //Imprime o Total de cada produto em cada Loja - Pode virar procedimento
    posProduto = 0;
    do{
        soma = 0;
        for(int j = 0; j < LOJAS; j++){
            soma += matriz[posProduto][j];
        }
        printf("Total do produto %d em todas as lojas: %d \n", posProduto+1, soma);
        posProduto++;

    }while(posProduto < PRODUTOS);

    //Retorna a loja que tem menos produtos - Pode virar função
    for(int i = 0; i < PRODUTOS; i++){
        soma = 0;
        for(int j = 0; j < LOJAS; j++){
            soma += matriz[i][j];
        }
        if(soma < menor){
            menor = soma;
            lojaComMenos = i + 1;
        }
    }
    printf("A loja com menos produtos eh a loja %d", lojaComMenos);
    
    



        
    return OK;
}
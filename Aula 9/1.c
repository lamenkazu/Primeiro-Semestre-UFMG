#include <stdio.h>
#define OK 0
#define TAMANHO 20

int main (int argc, char ** argv){


    int valores[TAMANHO];
    int menor = 999999999999;

    for(int i = 0; i < TAMANHO; i++){
        printf("Informe o %d valor: ", i+1);
        scanf("%d", &valores[i]);
    }

    for(int i = 0; i < TAMANHO; i++){
        if(valores[i] < menor){
            menor = valores[i];
        }

        if(i == TAMANHO - 1){
            printf("O menor valor tem posicao %d e eh: %d ", i+1, menor);
        }
    }



    return OK;
}
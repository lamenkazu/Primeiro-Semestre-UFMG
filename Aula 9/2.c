#include <stdio.h>
#define OK 0
#define TAMANHO 5

void funcao(int vetor[]){
    for(int i = 0; i < TAMANHO; i++){
        if(i == OK){
            printf("Vetor sem Escala = {%g,", vetor[i]);
        }else if(i == TAMANHO - 1){
            printf(" %g}\n", vetor[i]);
        }else{
            printf(" %g,", vetor[i]);
        }
        
    }
}


int main (int argc, char ** argv){


    float vetor[TAMANHO], escalar, resultado[TAMANHO];

    for(int i = 0; i < TAMANHO; i++){
        printf("Informe o %d valor real do vetor: ", i+1);
        scanf("%f", &vetor[i]);
    }
    printf("Por quanto quer multiplicar cada valor do vetor? ");
    scanf("%f", &escalar);

    for(int i = 0 ; i < TAMANHO; i++){
        resultado[i] = vetor[i] * escalar;

    }

    for(int i = 0; i < TAMANHO; i++){
        if(i == OK){
            printf("Vetor sem Escala = {%g,", vetor[i]);
        }else if(i == TAMANHO - 1){
            printf(" %g}\n", vetor[i]);
        }else{
            printf(" %g,", vetor[i]);
        }
        
    }

    

    for(int i = 0; i < TAMANHO; i++){
        if(i == OK){
            printf("Resultado Em (%g) = {%g,",escalar, resultado[i]);
        }else if(i == TAMANHO - 1){
            printf(" %g}", resultado[i]);
        }else{
            printf(" %g,", resultado[i]);
        }
        
    }

    return OK;
}
#include <stdio.h>
#define OK 0
#define TAMANHO 5

int main (int argc, char ** argv){

    int vet1[TAMANHO], vet2[TAMANHO], produto[TAMANHO];

    for(int i = 0; i < TAMANHO; i++){
        printf("Informe valor %d do vetor 1: ", i+1);
        scanf("%d", &vet1[i]);
    }

    for(int i = 0; i < TAMANHO; i++){
        printf("Informe valor %d do vetor 2: ", i+1);
        scanf("%d", &vet2[i]);
    }

    for(int i = 0; i < TAMANHO; i++){
        produto[i] = vet1[i] * vet2[i];

    }

    for(int i = 0; i < TAMANHO; i++){
        if(i==OK){
            printf("Produto escalar dos vetores: ");
        }
        if(i == 5 - 1){
            printf("%d.", produto[i]);
        }else{
            printf("%d, ", produto[i]);
        }
    }


    return OK;
}
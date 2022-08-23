#include <stdio.h>
#define OK 0

int main(){

    int x;
    printf("Informe o tamanho do vetor desejado: ");
    scanf("%d", &x);


    float vetor[x], media, soma = 0;

    for(int i = 0; i < x; i++){
        printf("Informe valor %d do vetor: ", i+1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / x;
    printf("A media dos valores informados eh: %g \n", media);

    return OK;
}
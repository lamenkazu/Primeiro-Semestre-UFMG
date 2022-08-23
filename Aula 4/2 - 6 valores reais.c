#include <stdio.h>
#define Ok 0
#define quant 6 //Define Quantidade de valores

int main(){
    float valores, media, soma = 0;
    for(int cont = 1; cont<=6; cont++){
        printf("Digite o %d valor: ", cont);
        scanf("%f", &valores);
        soma += valores;
        media = soma / quant;
    }
    printf("A média dos valores inseridos é: %f \n\n", media);

    return Ok;
}
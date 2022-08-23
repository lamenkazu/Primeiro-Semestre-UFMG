#include <stdio.h>
#define Ok 0

int main(){
    int valores, soma = 0;
    for(int cont = 1; cont <= 5; cont++){
        printf("Digite o %d valor: ", cont);
        scanf("%d", &valores);
        soma += valores;
    }
    printf("\nA soma dos valores é: %d\n\n", soma);

    return Ok;
}
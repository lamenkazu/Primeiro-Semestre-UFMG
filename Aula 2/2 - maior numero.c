#include <stdio.h>
#define Ok 0

int main(){
    int n1, n2;
    printf("Informe 2 números!\nNumero 1: ");
    scanf("%d", &n1);
    printf("Numero 2: ");
    scanf("%d",&n2);

    if(n1 > n2){
        printf("%d é maior que %d, uai\n", n1, n2);
    } else if(n1 < n2){
        printf("%d é maior que %d, ne!\n", n2, n1);
    }else{
        printf("%d e %d sao iguais, bobao!");
    }

    return Ok;
}
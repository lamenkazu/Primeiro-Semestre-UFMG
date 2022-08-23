#include <stdio.h>
#define Ok 0

int main(){
    int c1, c2, c3;

    printf("Informe o comprimento 1: ");
    scanf("%d", &c1);
    printf("Informe o comprimento 2: ");
    scanf("%d", &c2);
    printf("Informe o comprimento 3: ");
    scanf("%d", &c3);

    if((c1 + c2) > c3 && (c1 + c3) > c2 && (c2 + c3) > c1){
        printf("É um triangulo!!\n");
    }else{
        printf("Não é um triangulo :( \n");
    }

    return Ok;
}
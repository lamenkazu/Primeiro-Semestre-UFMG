#include <stdio.h>
#define OK 0

int ehPrimo(int valor){

    for(int i = 2; i < valor; i++){
        if(valor % i == OK){
            return i;
        }
    }

    return OK;
}

int main(int argc, char ** argv){

    int valor;

    printf("Digita um numero ai troxa: ");
    scanf("%d", &valor);

    if(ehPrimo(valor) == OK){
        printf("%d eh primo", valor);
    }else{
        printf("%d nao eh primo", valor);
    }

    return OK;
}
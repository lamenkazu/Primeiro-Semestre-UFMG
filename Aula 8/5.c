#include <stdio.h>
#define OK 0

int calculaFatorial(int valor){

    int resultado = 1;

    for(int i = valor; i > 1 ; i--){
        resultado *= i;
    }

    return resultado;
}

int main(int argc, char ** argv){

    int valor;
    printf("Informe um valor inteiro: ");
    scanf("%d", &valor);

    printf("(%d!) = %d", valor, calculaFatorial(valor));

    return OK;
}
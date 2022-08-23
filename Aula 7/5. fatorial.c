#include <stdio.h>
#define OK 0

int calculaFatorial(int valor){

    int fatorial = 1;
    for(int i = valor; i > 1; i--){
        fatorial *= i;
    }

    return fatorial;
}

int main(int argc, char ** argv){

    int val, fat;

    printf("Informe um valor para calcular o Fatorial: ");
    scanf("%d", &val);

    fat = calculaFatorial(val);

    printf("%d! = %d\n", val, fat);

    return OK;
}
#include <stdio.h>
#define OK 0

float soma(float num1, float num2){
    return num1 + num2;
}

float produto(float num1, float num2){
    return num1 * num2;
}

float quociente(float num1, float num2){
    return num1 / num2;
}

int main(int argc, char ** argv){

    int op;
    float num1, num2;

    do{
        printf("Escolha uma opcao de calculo pra dois numeros: \n1 - Soma\n2 - Produto\n3 - Quociente\n4 - Sair\nOpcao: ");
        scanf("%d", &op);

        if(op != 4){
            printf("Informe numero 1: ");
            scanf("%f", &num1);
            printf("Informe numero 2: ");
            scanf("%f", &num2);
        }

        switch(op){
            case 1:
                printf("%g + %g = %g\n\n", num1, num2, soma(num1, num2));
                break;
            case 2:
                printf("%g * %g = %g\n\n", num1, num2, produto(num1, num2));
                break;
            case 3:
                printf("%g / %g = %g\n\n", num1, num2, quociente(num1, num2));
                break;
            
        }
        
    }while (op != 4);

    



    return OK;
}
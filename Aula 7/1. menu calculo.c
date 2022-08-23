#include <stdio.h>
#define OK 0

float somaNumeros(float num1, float num2){
    return (num1 + num2);
}

float multiplicaNumeros(float num1, float num2){
    return (num1 * num2);
}

float divideNumeros(float num1, float num2){
    return (num1 / num2);
}

int main(int argc, char ** argv){

    int op;
    float num1, num2;

    do{
        
        printf("\nEscolha uma operacao para realizar: \n1 - Soma\n2 - Produto\n3 - Quociente\n4 - Sair\nOpcao: ");
        scanf("%d", &op);

        if(op != 4){

            if(op < 1 || op > 4){
                printf("\nOperacao invalida, tente de novo.\n");
                system("PAUSE");
            }else{
                printf("Informe 2 numeros para realizar a operacao entre eles: ");
                scanf("%f %f", &num1, &num2);

                switch(op){
                    case 1:
                        printf("%g + %g = %g\n", num1, num2, somaNumeros(num1, num2));
                    break;

                    case 2:
                        printf("%g * %g = %g\n", num1, num2, multiplicaNumeros(num1, num2));
                    break;

                    case 3:
                        printf("%g / %g = %g\n", num1, num2, divideNumeros(num1, num2));
                    break;
                }
            }
            
        }        

    }while(op != 4);

    return OK;
}
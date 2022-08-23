#include <stdio.h>
#define Ok 0

int main(){
    float res, n1, n2;
    char op;
    printf("Hora de calcular hehehe...\nNumero 1: ");
    scanf("%f", &n1); 
    printf("Informe a operação (+, -, * ou /): ");
    scanf("%s", &op);
    printf("Numero 2: ");
    scanf("%f", &n2); 


    if(op == '+'){
        res = n1 + n2;
        printf("o resultado é %g", res);
    }else if(op == '-'){
        res = n1 - n2;
        printf("o resultado é %g", res);
    }else if(op == '*'){
        res = n1 * n2;
        printf("o resultado é %g", res);
    }else if(op == '/'){
        res = n1 / n2;
        printf("o resultado é %g", res);
    }else{
        printf("Operação incorreta ou não especificada.\n");
    }

    return Ok;
}
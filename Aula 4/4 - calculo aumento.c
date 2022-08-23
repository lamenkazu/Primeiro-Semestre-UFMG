#include <stdio.h>
#define Ok 0

int main(){
    float salarioAtual, porcentagem, novoSalario;

    printf("Informe seu salario atual: ");
    scanf("%g", &salarioAtual);
    printf("Informe agora o valor percentual do aumento: ");
    scanf("%g", &porcentagem);

    novoSalario = salarioAtual + ((salarioAtual * porcentagem) / 100);
    printf("\nCom um aumento de %g%%, seu novo salário é: %g\n", porcentagem, novoSalario);

    return Ok;
}
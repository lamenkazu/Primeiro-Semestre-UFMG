#include <stdio.h>
#define Ok 0

int main(){
    float media, nota1, nota2, nota3, soma=0;

    printf("Informe nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Informe nota da prova 2: ");
    scanf("%f", &nota2);
    printf("Informe nota da prova 3: ");
    scanf("%f", &nota3);

    media = ((nota1 * 4) + (nota2 * 3) + (nota3 * 3) / 3);
    printf("A nota final do aluno é: %g", media);

}
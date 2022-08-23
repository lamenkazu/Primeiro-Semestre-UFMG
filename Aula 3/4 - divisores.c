#include <stdio.h>
#define Ok 0

int main()
{
    int num, cont = 1;
    printf("Insira um valor para descobrir seus divisores: ");
    scanf("%d", &num);

    
    printf("D(%d)={", num); //Parte visual do código

    while (cont <= num) //Enquanto Contador menor que Numero inserido pelo usuário
    {
        if (num % cont == 0)
        {
            if (num != cont)
            {
                printf("%d, ", cont);
            }
            else
            {
                printf("%d}\n\n", cont);
            }
        }
        cont++;
    }

    return Ok;
}
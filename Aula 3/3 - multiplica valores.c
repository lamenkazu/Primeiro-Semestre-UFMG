#include <stdio.h>
#define Ok 0

int main()
{
    int num, acumulo = 1;
    while (num != 0)
    {
        printf("Informe um valor para multiplicar (0 para sair): ");
        scanf("%d", &num);
        if (num != 0)
        {
            acumulo *= num;
        }
    }
    printf("O resultado é: %d", acumulo);

    return Ok;
}
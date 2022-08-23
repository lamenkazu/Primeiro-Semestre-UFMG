#include <stdio.h>
#define Ok 0

int main()
{
    int num, cont = 1;
    int res;
    printf("Informe um valor: ");
    scanf("%d", &num);
    
    while (cont <= 10)
    {
        res = num * cont;
        printf("%d x %d = %d\n", num, cont, res);
        cont++;
    }

    return Ok;
}
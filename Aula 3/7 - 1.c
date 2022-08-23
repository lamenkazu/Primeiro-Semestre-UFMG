#include <stdio.h>
#define Ok 0

int main()
{

    int num, cont = 1, res;
    printf("Informe um valor: ");
    scanf("%d", &num);

    do{
        res = num * cont;
        printf("%d x %d = %d\n", num, cont, res);

        cont++;
    } while (cont <= 10);

    return Ok;
}
#include <stdio.h>
#define Ok 0

int main(){
    int num, res;

    printf("Informe um valor: ");
    scanf("%d", &num);

    for(int cont = 1; cont <= 10; cont++){
        res = num * cont;
        printf("%d x %d = %d\n", num, cont, res);
    }

    return Ok;
}
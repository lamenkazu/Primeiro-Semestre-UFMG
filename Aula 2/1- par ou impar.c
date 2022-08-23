#include <stdio.h>
#define Ok 0

int main(){
    int num;
    printf("Informe um numero: ");
    scanf("%d", &num);
    if(num%2==0){
        printf("%d é um numero par.\n",num);
    } else{
        printf("%d é um numero impar.\n", num);
    }
    return Ok;
}
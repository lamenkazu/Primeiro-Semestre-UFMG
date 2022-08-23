#include <stdio.h>
#define Ok 0

int main(){
    int num;
    printf("Insira um valor para descobrir seus divisores: ");
    scanf("%d", &num);
    printf("D(%d)={", num);
    
    for(int cont = 1; cont <= num; cont++){
        if(num % cont == 0){
            if(num != cont){
                printf("%d, ", cont);
            }else{
                printf("%d}", cont);
            }
        }
    }

    return Ok;
}
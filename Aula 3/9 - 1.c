#include <stdio.h>
#define Ok 0

int main(){
     int num, cont = 1;
     printf("Insira um valor para descobrir seus divisores: ");
     scanf("%d", &num);
     printf("D(%d)={", num);

     do{
          if (num % cont == 0){
      
            if (num != cont){
                printf("%d, ", cont);
            }
            else{
                printf("%d}", cont);
            }

          }

          cont++;
     }while(cont <= num);

     return Ok;
}
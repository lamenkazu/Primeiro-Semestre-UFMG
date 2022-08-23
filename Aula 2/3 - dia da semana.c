#include <stdio.h>
#define Ok 0

int main(){
    int num;

    printf("Digite o dia da semana: ");
    scanf("%d", &num);
    if(num < 1 || num > 7){
        printf("N tem esse dia na semana :@\n");
    }else{
        switch (num)
        {
        case 1:
            printf("%d é Domingo\n", num);
            break;
        
        case 2:
            printf("%d é segunda\n", num);
            break;
        case 3:
            printf("%d é terça\n", num);
            break;
        case 4:
            printf("%d é quarta\n", num);
            break;
        case 5:
            printf("%d é TBT\n", num);
            break;
        case 6:
            printf("%d é sextooou\n", num);
            break;
        case 7:
            printf("%d é Hora do descanso, sabadola\n", num);
            break;
        
        default:
            break;
        }
    }

    return Ok;

}
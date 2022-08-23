#include <stdio.h>
#define OK 0

void tempoEmHoras(int tempoEmSegundos){

    int hora = 0, minuto = 0, segundo = 0;

    for(int i = 0; i < tempoEmSegundos; i++){
        segundo++;
        if(segundo == 60){
            minuto++;
            segundo = 0;
            if(minuto == 60){
                hora++;
                minuto = 0;
            }
        }
    }
    
    printf("O experimento durou %dh %dm %ds \n", hora, minuto, segundo);

}

int main(int argc, char ** argv){

    int tempo;
    printf("Informe o tempo do experimento em segundos: ");
    scanf("%d", &tempo);

    tempoEmHoras(tempo);

    return OK;
}
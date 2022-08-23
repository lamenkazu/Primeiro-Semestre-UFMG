#include <stdio.h>
#define OK 0

void tempoHoras(int tempoSegundos){

    int hora=0, minuto=0, segundo=0;

    for(int i = 1; i <= tempoSegundos; i++){
        segundo++;
        if(segundo == 60){
            minuto++;
            if(minuto == 60){
                hora++;
                minuto = 0;
            }
            segundo = 0;
        }
    }
    
    printf("Tempo: %dh %dm %ds", hora, minuto, segundo);

}

int main(int argc, char ** argv){

    int tempoSegundos;

    printf("Quanto tempo durou?");
    scanf("%d", &tempoSegundos);

    tempoHoras(tempoSegundos);

    return OK;
}
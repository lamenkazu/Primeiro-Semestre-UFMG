#include <stdio.h>
#define OK 0
#define ANO 365
#define MES 30

int idadeEmDias(int anos, int meses, int dias){

    int tempo=0;
    for(int i = 1; i <= anos; i++){
        tempo += ANO;
    }
    for(int i = 1; i <= meses; i++){
        tempo += MES;
    }
    tempo += dias;

    return tempo;
}

int main(int argc, char ** argv){

    int anos, meses, dias, tempo;

    printf("Informe sua idade...\nEm anos: ");
    scanf("%d", &anos);
    printf("Quantos meses?");
    scanf("%d", &meses);
    printf("Quantos dias?: ");
    scanf("%d", &dias);

    tempo = idadeEmDias(anos, meses, dias);

    printf("Você tem %d dias de vida", tempo);


    return OK;
}
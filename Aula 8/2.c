#include <stdio.h>
#define OK 0

int idadeEmDias(int anos, int meses, int dias){
    int emDias;

    emDias = anos * 365;
    emDias += meses * 30;
    emDias += dias;

    return emDias;
}

int main(int argc, char ** argv){

    int anos, meses, dias;

    printf("Informe sua idade:\nQuantos anos? ");
    scanf("%d", &anos);
    printf("Quantos meses? ");
    scanf("%d", &meses);
    printf("Quantos dias? ");
    scanf("%d", &dias);

    printf("%d", idadeEmDias(anos, meses, dias));

    return OK;
}
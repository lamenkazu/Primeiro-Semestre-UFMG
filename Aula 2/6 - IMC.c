#include <stdio.h>
#define Ok 0

int main(){
    char sexo;
    int alturaCm;
    float ideal, peso, alturaM;

    //Recebe Variáveis
    printf("Informe seu sexo (M/F)");
    scanf("%s", &sexo);
    printf("Informe sua altura em cm: ");
    scanf("%d", &alturaCm);
    printf("Informe seu peso: ");
    scanf("%f", &peso);

    //Transforma altura de Centimetros p/ Metros
    alturaM = alturaCm/100;

    //Informa peso ideal baseado no sexo (questão bem transfóbica né)
    if(sexo == 'M'){
        ideal = (72.7 * alturaM) - 58;
        printf("Seu peso ideal é: %g", &ideal);
               

    }else if(sexo == 'F'){
        ideal = (62.1 * alturaM) - 44.7;
        printf("Seu peso ideal é: %g", &ideal);

    }else{
        printf("Sexo Inválido\n"); //Ética e moralmente errado, nunca poste isso online
    }

    if(peso < ideal){
            printf("Você está abaixo do peso.\n");

        } else if(peso > ideal){
            printf("Você está acima do peso.\n");

        } else if(peso = ideal){
            printf("Uau! você está no peso ideal :O");
        }

        return Ok;
}
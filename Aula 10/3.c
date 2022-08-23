#include <stdio.h>
#include <string.h>

#define OK 0
#define TAMANHO (300 + 1)

int main(int argc, char ** argv){

    char frase[TAMANHO];
    int vogal = 0;

    printf("Informe uma string: ");
    fgets(frase, sizeof(frase), stdin);

    for(int i = 0; i < strlen(frase); i++){
        switch(frase[i]){
            case 'a' : vogal++;
            break;
            case 'e' : vogal++;
            break;
            case 'i' : vogal++;
            break;
            case 'o' : vogal++;
            break;
            case 'u' : vogal++;
            break;
            case 'A' : vogal++;
            break;
            case 'E' : vogal++;
            break;
            case 'I' : vogal++;
            break;
            case 'O' : vogal++;
            break;
            case 'U' : vogal++;
            break;
        }
    }

    printf("Sua frase tem %d vogais", vogal);

    return OK;
}
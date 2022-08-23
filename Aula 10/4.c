#include <stdio.h>
#include <string.h>

#define OK 0
#define TAMANHO 300 + 1

int main(int argc, char ** argv){

    char frase[TAMANHO];

    printf("Informe uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[0] -= 32; //Transforma primeira letra em maíuscula
    for(int i = 0; i < strlen(frase); i++){ //Transforma letras dps do espaço em maiusculas
        if(frase[i] == ' '){
            frase[i + 1] -= 32;
        } 
    }
    

    printf("Sua frase é: ");
    puts(frase);


    return OK;
}
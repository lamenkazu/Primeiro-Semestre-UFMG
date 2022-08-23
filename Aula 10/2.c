#include <stdio.h>
#define OK 0
#define TAMANHO 300 + 1

int main(int argc, char ** argv){

    char frase[TAMANHO], resultado[TAMANHO];

    printf("Digita uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    /*Se o caracter for espaço, pula ele e continua lendo o próximo.
    **Insere o valor que não é espaço no lugar do espaço e continua lendo até o final;
    */
    for(int i = 0, j = 0; i < strlen(frase); i++, j++){ 
        if(frase[j] == ' '){
            j++;
        }
        frase[i] = frase[j];
    }

    printf("Sua frase sem espaços: ");
    fputs(frase, stdout);

    return OK;
}
#include <stdio.h>
#define OK 0
#define TAMANHO 300

int main(int argc, char ** argv){

    char str[TAMANHO];
    int space = 0;

    printf("Digite uma string: ");
    fgets(str, TAMANHO, stdin);

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            space++;
        }
    }

    printf("Tem %d espacos em branco.", space);

    return OK;
}
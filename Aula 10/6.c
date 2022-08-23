#include <stdio.h>
#include <string.h>
#define OK 0
#define TAMANHO 100 + 1

typedef bool_t;
#define TRUE (1==1)
#define FALSE (!TRUE)

int main(int argc, char ** argv){

    bool_t ehPalindromo = TRUE;
    char frase[TAMANHO];

    //Recebe Frase do teclado
    printf("Informe uma frase: ");
    fgets(frase, sizeof(frase),stdin);


    //Deixa todas as letras da frase minusculas
    for(int i = 0; i < sizeof(frase); i++){
        frase[i] = tolower(frase[i]);
    }

    //Remove espaços, traços e pontuações da frase (máximo de 2 seguidos)
    for(int i = 0, j = 0; i < strlen(frase); i++, j++){
        if(frase[j] == ' ' || frase[j] == '-' || frase[j] == '!' || frase[j] == '?' || frase[j] == ',' || frase[j] == '.' || frase[j] == '\'' ){
            j++;
            if(frase[j] == ' ' || frase[j] == '-' || frase[j] == '!' || frase[j] == '?' || frase[j] == ',' || frase[j] == '\''){
                j++;
            }
        }
        frase[i] = frase[j];
    }

    //Verifica se é palindromo
    for(int inicio = 0, fim = strlen(frase) - 2; inicio < fim; inicio++, fim--){
        if(frase[inicio] != frase[fim]){
            ehPalindromo = FALSE;
            break;
        }
    }

    if(ehPalindromo){
        printf("Essa frase eh palindromo!\n");
    }else{
        printf("Essa frase nao eh palindromo :(\n");
    }

    return OK;
}
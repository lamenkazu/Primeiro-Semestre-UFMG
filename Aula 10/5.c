#include <stdio.h>
#include <string.h>

typedef bool_t;
#define TRUE (1 == 1)
#define FALSE (!TRUE)

#define OK 0
#define TAMANHO 100 + 1


int main(int argc, char ** argv){
    
    char frase[TAMANHO];
    bool_t ehPalindromo = TRUE;

    printf("Informe uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    for(int i = 0, f = strlen(frase) - 2; i < f; i++, f--){
        if(frase[i] != frase[f]){
            ehPalindromo = FALSE;
            break;
        }
    }

    if(ehPalindromo){
        printf("A frase Ê palindromo");
    }else{
        printf("A frase nao eh palindromo");
    }
}
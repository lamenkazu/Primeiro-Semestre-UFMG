#include <stdio.h>
#define OK 0

//Define novo Type boolean
typedef bool_t; 
#define TRUE (1 == 1)
#define FALSE (!TRUE)

bool_t verificaPrimo(int valor){

    bool_t ehPrimo = TRUE;

    for(int i = 2; i < valor; i++){
        if(valor % i == 0){
            ehPrimo = FALSE;
            return ehPrimo;
        }
    }
    return ehPrimo;
}

int main(int argc, char ** argv){

    int valor;

    do{
        
        printf("Informe um valor inteiro (0 para sair): ");
        scanf("%d", &valor);

        if(verificaPrimo(valor)){
            printf("O valor %d eh Primo.\n\n", valor);
        }else{
            printf("O valor %d nao eh primo\n\n", valor);
        }

    }while(valor != 0);

    

    return OK;
}
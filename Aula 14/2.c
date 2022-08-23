#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0
#define TAMANHO_CONTEUDO (100+1)

int retornaCaracteresTXT(FILE * arquivo){

    int qnt, aux, soma = 0;
    int tamanho;
    char conteudo[TAMANHO_CONTEUDO];

    while(!feof(arquivo)){

        aux = 0; //Soma dos Espaços e Quebras de linha
        qnt = 0; //Todos os caracteres lidos no fgets

        fgets(conteudo, TAMANHO_CONTEUDO , arquivo); //Pega trecho do arquivo até o \n
        qnt += strlen(conteudo);

        for(int i = 0; i < qnt; i++){
            if(conteudo[i] == ' ' || conteudo[i] == '\n'){
                aux++;
            }
            
        }
        soma += qnt - aux; //Acrescenta à variavel soma a quantidade de caracteres desconsidenrando espaços e quebras de linha
    
    }


    return soma; //Retorna a quantidade de caracteres lidas até o final do arquivo
}

int main(int argc, char ** argv){

    int qnt;

    FILE * arquivo;
    arquivo = fopen("texto.txt", "r");
    
    if(arquivo != NULL){
        qnt = retornaCaracteresTXT(arquivo);
        printf("Caracteres no arquivo: %d", qnt);

        fclose(arquivo);
    }

    return OK;
}
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define TAMANHO_TEXTO_ARQUIVO (100 + 1)

int leLinhasTXT(FILE *arquivo){

    int qnt = 0;
    char conteudo[TAMANHO_TEXTO_ARQUIVO];

    while(!feof(arquivo)){
        //o fgets lê até o \n, então toda vez que um conteúdo é lido do arquivo, a quantidade de \n sobe.
        //Assim se conta quantas linhas tem no arquivo txt
        fgets(conteudo, TAMANHO_TEXTO_ARQUIVO, arquivo);
        qnt++; 
    }

    return qnt;

}

int main(int argc, char ** argv){

    int qnt;

    //Manipulação do Arquivo para Leitura
    FILE * arquivo;
    arquivo = fopen("texto.txt", "r");
    if(arquivo != NULL){
        qnt = leLinhasTXT(arquivo);
        printf("Linhas no arquivo: %d", qnt);

        fclose(arquivo);
    }


    return OK;
}
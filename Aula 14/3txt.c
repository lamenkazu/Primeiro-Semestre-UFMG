#include <stdio.h>
#include <stdlib.h>
#define OK 0

#define TAM_NOME 50 + 1
#define QNT_NOTAS 2

//Quantidade máxima de alunos no arquivo não é decidida pelo usuário
#define MAX_ALUNOS 3

typedef struct aluno {
    char nome [TAM_NOME];
    float notas[QNT_NOTAS];
    float media;

} alunos_t;

void pegaDadosAlunosTXT(FILE * notas, alunos_t * lista){


   for(int i = 0; i <= MAX_ALUNOS; i++){
    fgets(&lista[i].nome, TAM_NOME, notas);
    lista[i].nome[strlen(lista[i].nome) - 1] = '\0';
    fscanf(notas, "%f %f\n", &lista[i].notas[0], &lista[i].notas[1]);
   }

    for(int i = 0; i < MAX_ALUNOS; i++){
        printf("%s ", lista[i].nome);
        for(int j = 0; j < QNT_NOTAS; j++){
            printf("%g ", lista[i].notas[j]);
        }
        printf("\n");
    }

}

void calculaMediaAlunos(alunos_t * lista){

    float soma = 0;

    for(int i = 0; i < MAX_ALUNOS; i ++){
        soma = 0;
        for(int j = 0; j < QNT_NOTAS; j++){
            soma += lista[i].notas[j];
        }
        lista[i].media = soma / QNT_NOTAS;
    }

}

void geraArquivoMediaAlunosTXT(alunos_t * lista){

    FILE * medias;
    medias = fopen("medias.txt", "w");
    if(medias != NULL){
        for(int i = 0; i < MAX_ALUNOS; i++){
            fprintf(medias, "%s %g\n", lista[i].nome, lista[i].media);
        }
    }

}

int main(int argc, char ** argv){

    alunos_t * lista;
    lista = (alunos_t*) malloc( MAX_ALUNOS * sizeof(alunos_t));

    FILE * notas;
    notas = fopen("notas.txt", "r");
    if(notas != NULL){
        pegaDadosAlunosTXT(notas, lista);
        calculaMediaAlunos(lista);
        geraArquivoMediaAlunosTXT(lista);

        fclose(notas);
    }

    free(lista);

    return OK;
}
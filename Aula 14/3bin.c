#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0

#define TAM_NOME 50 + 1
#define QNT_NOTAS 2

//Quantidade máxima de alunos no arquivo não é definida pelo usuário
#define MAX_ALUNOS 3

typedef struct aluno {
    char nome [TAM_NOME];
    float notas[QNT_NOTAS];
    float media;

} alunos_t;

typedef struct medias {
    char nome[TAM_NOME];
    float media;
} medias_t;

void pegaDadosAlunosBIN(FILE *notas, alunos_t * lista){

    fread(lista, sizeof(alunos_t), MAX_ALUNOS, notas);

    for(int i = 0; i < MAX_ALUNOS; i++){
        printf("%s", lista[i].nome);
        printf("%g ", lista[i].notas[0]);
        printf("%g\n", lista[i].notas[1]);
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

    for(int i = 0; i < MAX_ALUNOS; i++){
            printf("media %d: %g\n", i+1, lista[i].media);

        }

}

void geraArquivoMediaAlunosBIN(alunos_t * lista){

    FILE * medias;
    medias = fopen("medias.bin", "wb");
    if(medias != NULL){
        for(int i = 0; i < MAX_ALUNOS; i++){
            fwrite(&lista[i].nome, sizeof(char), 1, medias);
            fwrite(&lista[i].media, sizeof(float), 1, medias);
        }
    }

    fclose(medias);

    medias_t * listaMedias;
    listaMedias = (medias_t*) malloc(MAX_ALUNOS * sizeof(medias_t));

    medias = fopen("medias.bin", "rb");
    if(medias != NULL){
        fread(listaMedias, sizeof(medias_t), MAX_ALUNOS, medias);
        for(int i = 0; i < MAX_ALUNOS; i++){
            printf("%s", lista[i].nome);
            printf("%g\n", lista[i].media);
        }
    }

}

void geraBinario(alunos_t * lista){

    int descarte;
    char lixo;


    FILE * arqBin;
    arqBin = fopen("notas.bin", "wb");
    if(arqBin != NULL){

        for(int i = 0; i < MAX_ALUNOS; i++){
            printf("Informe nome %d: ", i+1);
            fgets(lista[i].nome, TAM_NOME, stdin);

            if(lista[i].nome[ strlen(lista[i].nome) - 1] == '\n' ){
                lista[i].nome[ strlen(lista[i].nome) - 1] == '\0' ;
            }
            

        
            for(int j = 0; j < QNT_NOTAS; j++){
                printf("Informe a nota da %dª prova: ", j+1);
                descarte = scanf("%f", &(lista[i].notas[j]));
            }
            descarte = scanf("%c", &lixo);

        
            
        }

        for(int i = 0; i < MAX_ALUNOS; i++){
            fwrite(lista, sizeof(alunos_t), MAX_ALUNOS, arqBin);
        }

        fclose(arqBin);
        

        /*
        fwrite("Erick Etiene", sizeof(char), 1, arqBin);
        fwrite("70 80", sizeof(int), 2, arqBin);
        */

    }
}

int main(int argc, char ** argv){

    alunos_t * lista;
    lista = (alunos_t*) malloc( MAX_ALUNOS * sizeof(alunos_t));

    geraBinario(lista);

    FILE * notas;
    notas = fopen("notas.bin", "rb");
    if(notas != NULL){
        pegaDadosAlunosBIN(notas, lista);
        calculaMediaAlunos(lista);
        
        geraArquivoMediaAlunosBIN(lista);

        fclose(notas);
    }

    free(lista);

    return OK;
}
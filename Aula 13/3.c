#include <stdio.h>
#include <stdlib.h>
#define OK 0

#define TAMANHO_NOME 50 +1
#define TAMANHO_CURSO 30 +1
#define QNT_NOTAS 3
#define MINIMO_APROVACAO 60

#define TRUE (1==1)
#define FALSE !TRUE
typedef bool_t;

typedef struct alunos {
    char nome[TAMANHO_NOME];
    char curso[TAMANHO_CURSO];
    int idade;
    float notas[QNT_NOTAS];
    float media;
    bool_t aprovado;
} alunos_t;

int main(int argc, char ** argv){

    float media, soma = 0;
    int qnt = 1, INA;
    char lixo;

    //Aloca 1 no 'vetor' de alunos
    alunos_t *aluno;
    aluno = (alunos_t*) malloc(sizeof(alunos_t)) ;

    do{
        printf("\n1 - Inserir Novo Aluno?\n0 - Finalizar\nOption: ");
        scanf("%d%c", &INA, &lixo);

        if(INA == 1){
            if(qnt > 1){
                //A cada vez que se deseja inserir um aluno, realoca +1 de espaço no 'vetor' Aluno
                aluno = (alunos_t*) realloc(aluno, (qnt+1) * sizeof(alunos_t));
                soma = 0;
            }
            
            printf("\nInforme seu nome: ");
            fgets(aluno[qnt-1].nome, TAMANHO_NOME, stdin);
            printf("Informe seu curso: ");
            fgets(aluno[qnt-1].curso, TAMANHO_CURSO, stdin);
            printf("Informe sua idade: ");
            scanf("%d", &aluno[qnt-1].idade);

            for(int i = 0; i < QNT_NOTAS; i++){
                printf("Informe a nota da %dª prova: ", i+1);
                scanf("%f", &(aluno[qnt-1].notas[i]));
                soma += aluno[qnt-1].notas[i];
            }

            aluno[qnt-1].media = soma / QNT_NOTAS;

            //Indica se aluno foi aprovado ou não
            if(aluno[qnt-1].media >= 60){
                aluno[qnt-1].aprovado = TRUE;
            }else{
                aluno[qnt-1].aprovado = FALSE;
            }

            }

    qnt++;

    }while(INA == 1);

    printf("\n\tLista de Alunos Cadastrados:\n");
        for(int i = 0; i < qnt; i++){
            if(aluno[i].aprovado == TRUE){
                printf("Situação: Aprovado!\nMedia: %g\nNome: %sCurso: %sIdade: %d\n\n", aluno[i].media, aluno[i].nome, aluno[i].curso, aluno[i].idade);
            }else if(aluno[i].aprovado == FALSE){
                printf("Situação: Reprovado!\nMedia: %g\nNome: %sCurso: %sIdade: %d\n\n", aluno[i].media, aluno[i].nome, aluno[i].curso, aluno[i].idade);
            }
        }

    free(aluno);

    return OK;
}
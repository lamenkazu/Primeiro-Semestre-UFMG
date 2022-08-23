#include <stdio.h>
#define OK 0
#define TAMANHO_NOME 50 +1
#define TAMANHO_CURSO 30 +1

typedef struct alunos {
    char nome[TAMANHO_NOME];
    char curso[TAMANHO_CURSO];
    int idade;
} alunos_t;

int main(int argc, char ** argv){

    alunos_t aluno;
    printf("Informe seu nome: ");
    fgets(aluno.nome, TAMANHO_NOME, stdin);
    printf("Informe seu curso: ");
    fgets(aluno.curso, TAMANHO_CURSO, stdin);
    printf("Informe sua idade: ");
    scanf("%d", &(aluno.idade));

    printf("\tDados do aluno:\nNome: %sIdade: %d\nCurso: %s", aluno.nome, aluno.idade, aluno.curso);

    return OK;
}
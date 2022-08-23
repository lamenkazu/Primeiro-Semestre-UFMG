#include <stdio.h>
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
} alunos_t;

int main(int argc, char ** argv){

    float media, soma = 0;
    bool_t aprovado;

    alunos_t aluno;
    printf("Informe seu nome: ");
    fgets(aluno.nome, TAMANHO_NOME, stdin);
    printf("Informe seu curso: ");
    fgets(aluno.curso, TAMANHO_CURSO, stdin);
    printf("Informe sua idade: ");
    scanf("%d", &(aluno.idade));


    //Recebe as 3 notas do aluno
    for(int i = 0; i < QNT_NOTAS; i++){
        printf("Informe a nota da %dª prova: ", i+1);
        scanf("%f", &(aluno.notas[i]));
        soma += aluno.notas[i];
    }

    media = soma / QNT_NOTAS;

    if(media >= MINIMO_APROVACAO){
        aprovado = TRUE;
        printf("\nResultado: Foi aprovado!\nAluno: %sIdade: %d\nCurso: %sMedia: %g", aluno.nome, aluno.idade, aluno.curso, media);
    }else{
        aprovado = FALSE;
        printf("\nResultado: Foi reprovado!\nAluno: %sIdade: %d\nCurso: %sMedia: %g", aluno.nome, aluno.idade, aluno.curso, media);
    }

    

    return OK;
}
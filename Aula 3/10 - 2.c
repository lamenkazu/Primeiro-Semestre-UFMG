#include <stdio.h>
#define Ok 0

int main(){
    int nota, porc, alunos = 5,
    aprovado = 0, reprovado = 0;

    for(int cont = 1; cont <= alunos; cont++){
        printf("Informe a nota do %d aluno:", cont);
        scanf("%d", &nota);
        if(nota >= 60){
            aprovado++;
        }else{
            reprovado++;
        }
    }
    porc = (100 * aprovado) / alunos;
    printf("\nPorcentagem de aprovação: %d%%", porc);
    
    return Ok;
}
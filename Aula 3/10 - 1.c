#include <stdio.h>
#define Ok 0

int main(){
    int nota, porc, alunos = 30, aprovado = 0,
    reprovado = 0, cont = 1; 
    do{
        printf("Informe a nota do %d aluno:", cont);
        scanf("%d", &nota);
        if(nota >= 60){
            aprovado++;
        }else{
            reprovado++;
        }
        cont++;
    }while(cont <= alunos);
    porc = (100 * aprovado) / alunos;
    printf("\nPorcentagem de aprovação: %d%%", porc);

    return Ok;
}
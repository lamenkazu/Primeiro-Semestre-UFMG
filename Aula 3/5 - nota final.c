#include <stdio.h>
#define Ok 0

int main()
{
    int nota, porc, alunos = 30, aprovado = 0, reprovado = 0, cont = 1;

    while (cont <= alunos)
    {
        printf("Informe a nota do %d aluno:", cont);
        scanf("%d", &nota);
        
        if (nota >= 60)
        {
            aprovado++;
        }
        else
        {
            reprovado++;
        }
        cont++;
    }
    porc = (100 * aprovado) / alunos;
    printf("\nPorcentagem de aprovados: %d%%", porc);

    return Ok;
}
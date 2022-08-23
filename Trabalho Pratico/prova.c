/**
 * @file   prova2o.c
 * @brief  Arquivo com a implementação da 2a prova de 2022.
 * @author <SEU_NOME_AQUI>
 * @date   2022-06-22
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

/* Constantes */


/// Lista de erros
#define SUCESSO                 (0)
#define FALHA                   (1)

/// Definições de limites
#define NUMERO_ESTADOS_E_DF     (26 + 1)
#define TAMANHO_MAIOR_NOME      (19 + 1)

// Aloca um vetor com <nCaracteres> de tamanho
char * alocaVetorCaracteres(int nCaracteres) {

    char * vetor;

    vetor = (char*) malloc(nCaracteres * sizeof(char));

    return vetor;
}

// Aloca um vetor de vetores onde cara linha do vetor tenha
// <tamLinhas[i]> caracteres
char ** alocaVetorBidimensional(int * tamLinhas, int nLinhas) {

    char ** matriz;

    matriz = (char**) malloc(nLinhas * sizeof(char*));
    

    for(int i = 0; i < nLinhas; i++){

        matriz[i] = (char*) malloc(tamLinhas[i] * sizeof(char));

        if(matriz[i] == NULL) {
            printf("Erro!!");
            return FALHA;
        }
    }



  return matriz;
}

// Imprime em cada linha o conteúdo da linha da matriz
void imprimeMatrizDinamica(char ** matriz, int nLinhas) {

    for(int i = 0; i < nLinhas; i++){
        puts(matriz[i]);
    }

}

// Libera a memória alocada
void liberaMatriz(char ** matriz, int nLinhas) {

    for(int i = 0; i < nLinhas; i++){
        free(matriz[i]);
    }
    
    free(matriz);
}

// Imprime uma matriz como se fosse um vetor linear
// É importante saber o tamanho das colunas para fazer
// a quebra na posição correta.
void imprimeMatriz(char * matriz, int nLinhas, int nColunas) {

  int i;

  for (i = 0; i < nLinhas; i++) {
    printf("%s\n", &matriz[i * nColunas]);
  }
}

/**
 * Rotina que imprime o nome de cada um dos estados que está no vetor.
 * Essa função não é genérica no sentido de imprimir qualquer vetor.
 * Ela imprime unicamente um vetor de char * de dimensões fixas.
 * @param vetor Endereço do vetor com os endereços das STRINGS que
 * serão impressas.
 */
void imprimeVetorNomesEstados(char * vetor[NUMERO_ESTADOS_E_DF]) {

  int i;

  for (i = 0; i < NUMERO_ESTADOS_E_DF; i++) {
    printf("%s\n", vetor[i]);
  }

}

/**
 * Rotina que imprime o nome de cada um dos estados que está na matriz.
 * Essa função não é genérica no sentido de imprimir qualquer matriz.
 * Ela imprime unicamente uma matriz de char de dimensões fixas.
 * @param matriz Endereço da matriz com os nomes dos estados que
 * serão impressos.
 */
void imprimeMatrizNomesEstados(char matriz[NUMERO_ESTADOS_E_DF][TAMANHO_MAIOR_NOME]) {

  int i;

  for (i = 0; i < NUMERO_ESTADOS_E_DF; i++) {
    printf("%s\n", matriz[i]);
  }

}

/**
 * Rotina que ordena um vetor de STRINGS.
 * Essa rotina é a implementação do algoritmo do BubbleSort em sua versão
 * mais simples. O objetivo aqui é simplesmente mapear de ALGORITMO para C.
 * Basicamente o que esse algoritmo faz é comparar cada posição com o
 * próximo, se for maior, então ele troca de posição, como se fosse uma
 * BOLHA subindo, daí o nome BubbleSort. Observe que como o vetor só
 * contêm endereços, ele só precisa trocar um endereço com o outro. Caso
 * o algoritmo fosse implementado na matriz, ele teria que copiar a STRING
 * inteira de um lugar para o outro.
 * @param vetor Endereço do vetor com o endereço das STRINGS a serem ordenadas.
 */
void ordenacaoPorNome(char * vetor[NUMERO_ESTADOS_E_DF]) {

  int i, j;
  char * tmp;

  for (i = 0; i < (NUMERO_ESTADOS_E_DF - 1); i++) {
    for (j = 0; j < (NUMERO_ESTADOS_E_DF - 1); j++) {
      // Se estiver fora de ordem...
      if (strcmp(vetor[j], vetor[j + 1]) > 0) {
        // ... troca de posicao
        tmp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = tmp;
      }
    }
  }
}

char ** copiaMatriz(char matriz[][TAMANHO_MAIOR_NOME], int x, int y){

    char ** copia;
    int tamanhos[x];

    for(int i = 0; i < x; i++){
      for(int j = 0; j < y; j++){
        tamanhos[i] = matriz[i];
      }
    }

    copia = alocaVetorBidimensional(tamanhos, x);

    for(int i = 0; i < x; i++){
      for(int j = 0; j < tamanhos[j]; j++){
        copia[i][j] = matriz[i][j];
      }
    }
    return copia;
}

void ordenaAlfabeticamente(char matriz[][TAMANHO_MAIOR_NOME], int x){

    for(int i = 0; i < x; i++){
      ordenacaoPorNome(matriz);
    }

}


/**
 * Função principal.
 * @param argc Número de parâmetros.
 * @param argv Vetor com os parâmetros.
 * @return SUCESSO caso o programa rode normalmente, ou caso contrário,
 * o código do erro ocorrido.
 */
int main(int argc, char ** argv) {

  // Matriz com o nome dos estados do Brasil e DF
  char NOMES_ESTADOS[NUMERO_ESTADOS_E_DF][TAMANHO_MAIOR_NOME] = {
    "Roraima", "Amapa", "Tocantins", "Alagoas", "Paraiba", "Mato Grosso", "Piaui",
    "Bahia", "Acre", "Goias", "Sao Paulo", "Pernambuco", "Santa Catarina",
    "Espirito Santo", "Rio Grande do Sul", "Rondonia", "Mato Grosso do Sul", "Maranhao",
    "Para", "Minas Gerais", "Parana", "Distrito Federal", "Rio Grande do Norte",
    "Ceara", "Rio de Janeiro", "Sergipe", "Amazonas"
  };

  // ------------------------
  // - INÍCIO DO SEU CÓDIGO -
  // ------------------------

  //************************* Questão 1

    /*

    char * vetorCaracteres;
    char ** vetorVetorCaracteres;;
    int tamLinhas[] = {27, 24, 26};

    vetorCaracteres = alocaVetorCaracteres(3);
    vetorVetorCaracteres = alocaVetorBidimensional(tamLinhas, 3);

    strcpy(vetorVetorCaracteres[0], "Lorem ipsum dolor sit amet");
    strcpy(vetorVetorCaracteres[1], "Ut urna sem, rhoncus eu");
    strcpy(vetorVetorCaracteres[2], "Donec dapibus, nisl vitae");

    imprimeMatrizDinamica(vetorVetorCaracteres, 3);

    liberaMatriz(vetorVetorCaracteres, 3);
    
    free(vetorCaracteres);

    */
    

  //************************Fim Questão 1

  //************************Questão 2

  

    char ** matrizDinamica;

    printf("Matriz Estatica:\n");
    imprimeMatriz(NOMES_ESTADOS, NUMERO_ESTADOS_E_DF, TAMANHO_MAIOR_NOME); // Aqui precisa do X e Y

    
    printf("\n\nMatriz Dinamica Copia:\n");
    matrizDinamica = copiaMatriz(NOMES_ESTADOS, NUMERO_ESTADOS_E_DF, TAMANHO_MAIOR_NOME);

    imprimeMatrizDinamica(matrizDinamica, NUMERO_ESTADOS_E_DF); // Aqui só precisa do X
    

    


  //************************Fim Questão 2

  //************************Questão 3

    printf("\nMatriz Ordenada Alfabeticamente:\n");

    ordenaAlfabeticamente(matrizDinamica, NUMERO_ESTADOS_E_DF);

    imprimeMatrizDinamica(matrizDinamica, NUMERO_ESTADOS_E_DF);

    
    printf("\n\nOriginal:\n");

    imprimeMatriz(NOMES_ESTADOS, NUMERO_ESTADOS_E_DF, TAMANHO_MAIOR_NOME);
    
  

  //************************Fim Questão 3




  // Exemplo de uso do imprimeMatriz
  // Apague para a resolução da prova. Está aqui apenas como dica ;-)
  
  
  //imprimeMatriz((char *)NOMES_ESTADOS, NUMERO_ESTADOS_E_DF, TAMANHO_MAIOR_NOME);

  // Libere a memória alocada AQUI
  liberaMatriz(matrizDinamica, NUMERO_ESTADOS_E_DF); // Aqui só precisa do X

  // ------------------------
  // - FIM DO SEU CÓDIGO    -
  // ------------------------

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0

/* Constantes */

// Tamanho máximo que o nome de um aluno pode ter
#define NOME_TAMANHO_MAXIMO  (50 + 1)

// Número de notas no registro do alun
#define NUMERO_NOTAS 2

// Nome do arquivo de dados
#define NOME_ARQUIVO_DADO      "./dados.bin"
#define NOME_ARQUIVO_MEDIA     "./medias.bin"
#define NOME_ARQUIVO_DADO_TXT  "./dados.txt"
#define NOME_ARQUIVO_MEDIA_TXT "./medias.txt"

/* Tipos */

/// Estrutura com as informações de um aluno
struct aluno_s {
  char nome[NOME_TAMANHO_MAXIMO];
  float notas[NUMERO_NOTAS];
};

/// Tipo "Aluno"
typedef struct aluno_s aluno_t;

/// <summary>
///  Estrutura responsável por armazenar a lista de alunos
/// </summary>
struct listaAlunos_s {
  aluno_t* lista;
  int numeroAlunos;
};

/// <summary>
/// Tipo "Lista de Alunos"
/// </summary>
typedef struct listaAlunos_s listaAlunos_t;

float calculaMedia(aluno_t* aluno) {

  int i;
  float total = 0.0f;

  for (i = 0; i < NUMERO_NOTAS; i++) {
    total += aluno->notas[i];
  }

  // Retorna a média
  return total / NUMERO_NOTAS;
}

void leAluno(aluno_t* aluno) {

  int i;
  int retornoDescartado;
  char lixo;

  // Leio o nome do aluno
  printf("Digite o nome: ");
  fgets(aluno->nome, NOME_TAMANHO_MAXIMO, stdin);

  // Removo o '\n' final caso ele exista
  if (aluno->nome[strlen(aluno->nome) - 1] == '\n') {
    aluno->nome[strlen(aluno->nome) - 1] = '\0';
  }

  // Leio as notas dos alunos
  printf("Digite as notas (n1 n2): ");
  for (i = 0; i < NUMERO_NOTAS; i++) {
    retornoDescartado = scanf("%f", &(aluno->notas[i]));
  }

  // Jogo o '\n' que está no buffer fora
  retornoDescartado = scanf("%c", &lixo);
}

void imprimeAluno(aluno_t* aluno) {
  printf("| %-*s | %6.2f | %6.2f | %6.2f |\n", NOME_TAMANHO_MAXIMO, aluno->nome, 
                                               aluno->notas[0],
                                               aluno->notas[1],
                                               calculaMedia(aluno));
}

void imprimeListaAlunos(listaAlunos_t* lista) {

  int i;

  // Imprime o cabeçalho
  printf("| %-*s | %6s | %6s | %6s |\n", NOME_TAMANHO_MAXIMO, "Aluno",
                                         "Nota1", "Nota2", "Media");
  // Imprime os dados
  for (i = 0; i < lista->numeroAlunos; i++) {
    imprimeAluno(&(lista->lista[i]));
  }
}

void insereAlunoLista(listaAlunos_t* listaAlunos, aluno_t* aluno) {


  // Aloca o espaço para mais um aluno
  listaAlunos->lista = realloc(listaAlunos->lista, (listaAlunos->numeroAlunos + 1) * sizeof(aluno_t));
  // Copia o aluno para o espaço recêm criado
  listaAlunos->lista[listaAlunos->numeroAlunos] = *aluno;
  // Incremente o número de alunos
  listaAlunos->numeroAlunos++;
}

void salvaListaAlunos(listaAlunos_t* listaAlunos) {

  FILE* arquivo;

  arquivo = fopen(NOME_ARQUIVO_DADO, "wb");
  if (arquivo == NULL) {
    // Deu pau
    return;
  }

  fwrite(&(listaAlunos->numeroAlunos), sizeof(int), 1, arquivo);
  fwrite(listaAlunos->lista, sizeof(aluno_t), listaAlunos->numeroAlunos, arquivo);

  fclose(arquivo);
}

void salvaArquivoMedias(listaAlunos_t* listaAlunos) {

  int i;
  FILE* arquivo;
  float media;

  arquivo = fopen(NOME_ARQUIVO_MEDIA, "wb");
  if (arquivo == NULL) {
    // Deu pau
    return;
  }

  fwrite(&(listaAlunos->numeroAlunos), sizeof(int), 1, arquivo);

  for (i = 0; i < listaAlunos->numeroAlunos; i++) {
    fwrite(listaAlunos->lista[i].nome, NOME_TAMANHO_MAXIMO, 1, arquivo);
    media = calculaMedia(&(listaAlunos->lista[i]));
    fwrite(&media, sizeof(float), 1, arquivo);
  }

  fclose(arquivo);

}

void salvaArquivoMedias_TXT(listaAlunos_t* listaAlunos) {

  int i;
  FILE* arquivo;
  float media;

  arquivo = fopen(NOME_ARQUIVO_MEDIA_TXT, "w");
  if (arquivo == NULL) {
    // Deu pau
    return;
  }

  fprintf(arquivo, "%d\n", listaAlunos->numeroAlunos);

  for (i = 0; i < listaAlunos->numeroAlunos; i++) {
    fprintf(arquivo, "%s\n", listaAlunos->lista[i].nome);
    media = calculaMedia(&(listaAlunos->lista[i]));
    fprintf(arquivo, "%.2f\n", media);
  }

  fclose(arquivo);
}

void salvaListaAlunos_TXT(listaAlunos_t* listaAlunos) {

  int i;
  FILE* arquivo;

  arquivo = fopen(NOME_ARQUIVO_DADO_TXT, "w");
  if (arquivo == NULL) {
    // Deu pau
    return;
  }

  fprintf(arquivo, "%d\n", listaAlunos->numeroAlunos);
  for (i = 0; i < listaAlunos->numeroAlunos; i++) {
    fprintf(arquivo,"%s\n%.2f %.2f\n", listaAlunos->lista[0].nome,
                                        listaAlunos->lista[0].notas[0],
                                        listaAlunos->lista[0].notas[1]);
  }

  fclose(arquivo);
}

void carregaListaAlunos(listaAlunos_t* listaAlunos) {

  FILE* arquivo;

  arquivo = fopen(NOME_ARQUIVO_DADO, "rb");
  if (arquivo == NULL) {
    // Deu pau
    return;
  }

  fread(&(listaAlunos->numeroAlunos), sizeof(int), 1, arquivo);
  listaAlunos->lista = malloc(sizeof(aluno_t) * listaAlunos->numeroAlunos);
  fread(listaAlunos->lista, sizeof(aluno_t), listaAlunos->numeroAlunos, arquivo);

  fclose(arquivo);
}

void carregaListaAlunos_TXT(listaAlunos_t* listaAlunos) {

  int i;
  FILE* arquivo;
  char lixo;

  arquivo = fopen(NOME_ARQUIVO_DADO_TXT, "r");
  if (arquivo == NULL) {
    // Deu pau
    return;
  }

  fscanf(arquivo,"%d%c", &(listaAlunos->numeroAlunos), &lixo);
  listaAlunos->lista = malloc(sizeof(aluno_t) * listaAlunos->numeroAlunos);


  for (i = 0; i < listaAlunos->numeroAlunos; i++) {
    fgets(listaAlunos->lista[i].nome, NOME_TAMANHO_MAXIMO, arquivo);
    listaAlunos->lista[i].nome[strlen(listaAlunos->lista[i].nome) - 1] = '\0';
    fscanf(arquivo, "%f %f%c", &(listaAlunos->lista[i].notas[0]),
                               &(listaAlunos->lista[i].notas[1]),
                               &lixo);
  }

  fclose(arquivo);
}


int main(int argc, char** argv) {

  listaAlunos_t listaAlunos = { NULL, 0 };
  char opcao, lixo;
  aluno_t alunoTmp;


  // Carrega os dados dos alunos do arquivo
  carregaListaAlunos(&listaAlunos);

  // IMprime a lista de alunos carregadas
  imprimeListaAlunos(&listaAlunos);

  // Iteração com o usuário para obter mais registros
  for (;;) {

    printf("Deseja inserir mais registro? [s,n]: ");
    scanf("%c%c", &opcao, &lixo);

    if (opcao == 's' || opcao == 'S') {
      leAluno(&alunoTmp);
      insereAlunoLista(&listaAlunos, &alunoTmp);
    } else {
      break;
    }
  }

  // Imprimir os dados completos
  imprimeListaAlunos(&listaAlunos);

  // Salvar os novos dados
  salvaListaAlunos(&listaAlunos);

  // Salva em um arquivo a média dos alunos
  salvaArquivoMedias(&listaAlunos);
  salvaArquivoMedias_TXT(&listaAlunos);

  // Liberar a memória
  free(listaAlunos.lista);
 
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}
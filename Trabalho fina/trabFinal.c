#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/***Constantes***/
#define OK 0
#define FALHA 1

#define TAM_TEL 11+1
#define TAM_CPF 12+1
#define TAM_NOME 30+1
#define TAM_END 45+1

/*************Estruturas**************/

//Estrutura de cada contato na agenda
typedef struct contato {
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    char end[TAM_END];
    char tel[TAM_TEL];

} contato_t;

//Estrutura da Agenda em si
typedef struct agenda{
    int qnt;
    contato_t * lista;

} agenda_t;

/************************Funções Arquivo Binário*************************/

//lê os dados da agenda de um arquivo binário
void leAgendaBIN(agenda_t * agenda){
        FILE * arqAgenda;
        arqAgenda = fopen("agenda.bin", "rb");
        if(arqAgenda != NULL){
            fread(&(agenda->qnt), sizeof(int), 1, arqAgenda);
            agenda->lista =  realloc (agenda->lista, (agenda->qnt) * sizeof(contato_t));
            fread(agenda->lista, sizeof(contato_t), agenda->qnt, arqAgenda);

            fclose(arqAgenda);
        }else{
        perror("Deu ruim, pai");
    }
}

//Salva a agenda em um arquivo binário
void salvaAgendaBIN(agenda_t * agenda){
    FILE * arqAgenda;
    arqAgenda = fopen("agenda.bin", "wb");
    if(arqAgenda != NULL){
        fwrite(&(agenda->qnt), sizeof(int), 1, arqAgenda);
        fwrite(agenda->lista, sizeof(contato_t), agenda->qnt, arqAgenda);

        fclose(arqAgenda);
    }else{
        perror("Deu ruim pai");
    }
}

//Inicializa o arquivo caso não exista, não faz nada caso exista.
void abreAgendaBIN(){
    FILE * arqAgenda;
    arqAgenda = fopen("agenda.bin", "ab");
    if(arqAgenda != NULL){
        fclose(arqAgenda);
    }
}

/*******************************Funções String******************************/

/*Se o caractere da string encontrado for "\n", então ele substitui por "\0"
Assim elimina o "\n" automatico do fgets(), para não atrapalhar a tabela*/
void tiraBarraN(char str[]){

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
        }
    }
        
}

//Coloca toda a string em letras minusculas para serem comparadas igualmente
void normalizaString(char str[]){
    for(int i = 0; i < strlen(str); i++){
            str[i] = tolower(str[i]);
        }
}

//Imprime Cabeçalho da Agenda
void imprimeCabecalho(){
    printf("| %-11s | %-31s | %-45s | %-13s |\n", "CPF", "NOME", "ENDERECO", "TELEFONE");
}

//Se já houver o CPF cadastrato, retorna FALHA, se não houver, retorna OK
int checaCPF(agenda_t * agenda, char cpf[]){

    for(int i = 0; i < agenda->qnt; i++){
        if(strcmp(agenda->lista[i].cpf, cpf) == 0 || strcmp("0", cpf) == 0 ){
            printf("\nCPF ja cadastrado ou Invalido!!! Tente novamente com outro CPF\n");
            return FALHA;
        }
    }

    return OK;
}

/*****************Funções principais****************/

//Insere um contato na agenda
void cadastraContato(agenda_t * agenda){
    char cpf[TAM_CPF];
    int atual;

    printf("CPF: ");
    fgets(cpf, TAM_CPF, stdin);
    tiraBarraN(cpf);

    if(checaCPF(agenda, cpf) == OK ){

        agenda->qnt++;
        atual = (agenda->qnt)-1;

        if(agenda->qnt > 1){
            agenda->lista = (contato_t*) realloc(agenda->lista, (agenda->qnt) * sizeof(contato_t));
        }

        strcpy(agenda->lista[atual].cpf, cpf);

        printf("Nome: ");
        fgets(agenda->lista[atual].nome, TAM_NOME, stdin);
        tiraBarraN(agenda->lista[atual].nome);

        printf("Endereco: ");
        fgets(agenda->lista[atual].end, TAM_END, stdin);
        tiraBarraN(agenda->lista[atual].end);

        printf("Telefone: ");
        fgets(agenda->lista[atual].tel, TAM_TEL, stdin);
        tiraBarraN(agenda->lista[atual].tel);
    }
    
    salvaAgendaBIN(agenda);
    
}

/*Lista todos os contatos válidos inseridos
**Função estética para criação de tabela*/
void listagemContatos(agenda_t * agenda){

    imprimeCabecalho();
    for(int i = 1; i < agenda->qnt; i++){
        printf("| %-11s | %-31s | %-45s | %-13s |\n", agenda->lista[i].cpf, 
                                                      agenda->lista[i].nome, 
                                                      agenda->lista[i].end, 
                                                      agenda->lista[i].tel);
    }
    printf("\n");
}

//Busca contato por parte do nome dele
void buscaContatosNome(agenda_t * agenda){

    char pesquisa[TAM_NOME];
    char compara[TAM_NOME];

    printf("Informe parte do nome que deseja procurar: ");
    fgets(pesquisa, TAM_NOME, stdin);
    tiraBarraN(pesquisa);

    //Imprime Contatos que contém a string inserida
    imprimeCabecalho();
    for(int i = 0; i < agenda->qnt; i++){

        strcpy(compara, agenda->lista[i].nome);

        normalizaString(compara);
        normalizaString(pesquisa);

        //strstr é uma função que encontra se uma string está inserida na outra (1 <- 2) do segundo para o primeiro
        if(strstr(compara, pesquisa)){
            printf("| %-11s | %-31s | %-45s | %-13s |\n", agenda->lista[i].cpf, 
                                                          agenda->lista[i].nome, 
                                                          agenda->lista[i].end, 
                                                          agenda->lista[i].tel);
        }
    }
    printf("\n");
}

//Ordena os contatos pela ordem crescente dos numeros de CPF
void ordenaContatosCPF(agenda_t * agenda){

    contato_t temporario;

    for(int i = 0; i < agenda->qnt; i++){
        for(int j = i; j < agenda->qnt; j++){

            if(strcmp(agenda->lista[i].cpf, agenda->lista[j].cpf) > 0){
                temporario = agenda->lista[i];
                agenda->lista[i] = agenda->lista[j];
                agenda->lista[j] = temporario;
            }

        }
    }

    //Imprime na ordem atual, mas não modifica o arquivo
    listagemContatos(agenda);
}

//Ordena contatos pela ordem alfabética do nome
void ordenaContatosNome(agenda_t * agenda){

    contato_t temporario;
    char testaNome1[TAM_NOME];
    char testaNome2[TAM_NOME];

    for(int i = 0; i < agenda->qnt; i++){
        for(int j = i; j < agenda->qnt; j++){

            strcpy(testaNome1, agenda->lista[i].nome);
            strcpy(testaNome2, agenda->lista[j].nome);

            normalizaString(testaNome1);
            normalizaString(testaNome2);

            if(strcmp(testaNome1, testaNome2) > 0){
                temporario = agenda->lista[i];
                agenda->lista[i] = agenda->lista[j];
                agenda->lista[j] = temporario;
            }
        }
    }
    //Imprime na ordem atual, mas não modifica o arquivo
    listagemContatos(agenda);

}

int main(int argc, char ** argv){

    char lixo;
    int op;

    //Inicializa Agenda
    agenda_t * agenda;
    agenda = (agenda_t*) malloc(1 * sizeof(agenda_t));
    agenda->qnt = 1;
    agenda->lista = (contato_t*) calloc(agenda->qnt, sizeof(contato_t));

    abreAgendaBIN();

    //Estrutura de Duração do programa. Encerra quando entra 0
    do{
        leAgendaBIN(agenda);
        
        printf("1- Cadastrar novo contato\n2- Listar Contatos\n3- Buscar Contato por parte do nome\n4- Ordenar Contatos por CPF\n5- Ordenar Contatos por Nome\n0- Sair\nOption: ");
        scanf("%d%c", &op, &lixo);

        switch(op){
            case 1: cadastraContato(agenda);
            break;
            case 2: listagemContatos(agenda);
            break;
            case 3: buscaContatosNome(agenda);
            break;
            case 4: ordenaContatosCPF(agenda);
            break;
            case 5: ordenaContatosNome(agenda);
            break;
        }
        
    }while(op != 0);

    free(agenda->lista);
    free(agenda);

    return OK;
}
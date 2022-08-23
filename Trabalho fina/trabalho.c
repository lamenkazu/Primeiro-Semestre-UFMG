#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define OK 0
#define FALHA 1

#define TAM_NOME 30+1
#define TAM_END 50+1
#define TAM_TEL 11+1


//Estrutura de cada contato na agenda
typedef struct contato {
    long long int cpf;
    char nome[TAM_NOME];
    char end[TAM_END];
    char tel[TAM_TEL];

} contato_t;

//Estrutura da Agenda em si
typedef struct agenda{
    contato_t * lista;
    int qnt;

} agenda_t;

//lê os dados da agenda de um arquivo binário
void leAgendaBIN(agenda_t * agenda){
        FILE * arqAgenda;
        arqAgenda = fopen("agenda.bin", "rb");
        if(arqAgenda != NULL){
            fread(&(agenda->qnt), sizeof(int), 1, arqAgenda);
            agenda->lista =  realloc (agenda->lista, (agenda->qnt) * sizeof(contato_t));
            fread(agenda->lista, sizeof(contato_t), agenda->qnt, arqAgenda);

            fclose(arqAgenda);
        }
}

/*Se o caractere da string encontrado for "\n", então ele substitui por "\0"
Assim elimina o "\n" automatico do fgets(), para não atrapalhar a tabela*/
void tiraBarraN(agenda_t * agenda){


        for(int i = 0; agenda->lista[agenda->qnt-1].nome[i] != '\0'; i++){
            if(agenda->lista[agenda->qnt-1].nome[i] == '\n'){
                agenda->lista[agenda->qnt-1].nome[i] = '\0';
            }
        }

        for(int i = 0; agenda->lista[agenda->qnt-1].end[i] != '\0'; i++){
            if(agenda->lista[agenda->qnt-1].end[i] == '\n'){
                agenda->lista[agenda->qnt-1].end[i] = '\0';
            }
        }

        for(int i = 0; agenda->lista[agenda->qnt-1].tel[i] != '\0'; i++){
            if(agenda->lista[agenda->qnt-1].tel[i] == '\n'){
                agenda->lista[agenda->qnt-1].tel[i] = '\0';
            }
        }



}

//Se já houver o CPF cadastrato, retorna FALHA, se não houver, retorna OK
int checaCPF(agenda_t * agenda, int cpf){

    for(int i = 0; i < agenda->qnt; i++){
        if(agenda->lista[i].cpf == cpf){
            printf("\nCPF ja cadastrado ou Invalido!!! Tente novamente com outro CPF\n");
            return FALHA;
        }
    }

    return OK;
}

//Salva a agenda em um arquivo binário
void salvaAgendaBIN(agenda_t * agenda){
    FILE * arqAgenda;
    arqAgenda = fopen("agenda.bin", "wb");
    if(arqAgenda != NULL){
        fwrite(&(agenda->qnt), sizeof(long long int), 1, arqAgenda);
        fwrite(agenda->lista, sizeof(contato_t), agenda->qnt, arqAgenda);

        fclose(arqAgenda);
    }else{
        perror("Deu ruim pai");
    }
}

//Insere um contato na agenda
void cadastraContato(agenda_t * agenda){

    char lixo;
    int cpf;

    printf("CPF: ");
    scanf("%d%c", &cpf, &lixo);

    if(checaCPF(agenda, cpf) == OK ){

        agenda->qnt++;

        if(agenda->qnt > 1){
            agenda->lista = (contato_t*) realloc(agenda->lista, (agenda->qnt) * sizeof(contato_t));
        }

        agenda->lista[agenda->qnt-1].cpf = cpf;

        printf("Nome: ");
        fgets(agenda->lista[agenda->qnt-1].nome, TAM_NOME, stdin);

        printf("Endereco: ");
        fgets(agenda->lista[agenda->qnt-1].end, TAM_END, stdin);

        printf("Telefone: ");
        fgets(agenda->lista[agenda->qnt-1].tel, TAM_TEL, stdin);
    }

    tiraBarraN(agenda);
    
    salvaAgendaBIN(agenda);
    
}

//Lista todos os contatos válidos inseridos
void listagemContatos(agenda_t * agenda){
    

    //Função estética para criação de tabela

    printf("| %-11s | %-31s | %-30s | %-20s |\n", "CPF", "NOME", "ENDERECO", "TELEFONE");
    
    for(int i = 0; i < agenda->qnt; i++){
        if(agenda->lista[i].cpf != 0){
            printf("| %-11d | %-31s | %-30s | %-20s |\n", agenda->lista[i].cpf, agenda->lista[i].nome, agenda->lista[i].end, agenda->lista[i].tel);
        }
       
    }

    printf("\n");

}

//Ordena os contatos pela ordem crescente dos numeros de CPF
void ordenaContatosCPF(agenda_t * agenda){

    contato_t temporario;

    for(int i = 0; i < agenda->qnt; i++){
        for(int j = i; j < agenda->qnt; j++){

            if(agenda->lista[i].cpf > agenda->lista[j].cpf){
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
    for(int i = 0; i < agenda->qnt; i++){
        for(int j = i; j < agenda->qnt; j++){

            for(int k = 0; k < TAM_NOME; k++){
                agenda->lista[i].nome[k] = tolower(agenda->lista[i].nome[k]);
            }

            for(int k = 0; k < TAM_NOME; k++){
                agenda->lista[j].nome[k] = tolower(agenda->lista[j].nome[k]);
            }

            if(strcmp(agenda->lista[i].nome, agenda->lista[j].nome) > 0){
                temporario = agenda->lista[i];
                agenda->lista[i] = agenda->lista[j];
                agenda->lista[j] = temporario;
            }
        }
    }
    //Imprime na ordem atual, mas não modifica o arquivo
    listagemContatos(agenda);

}

//Busca contato por parte do nome dele
void buscaContatosNome(agenda_t * agenda){

    char pesquisa[TAM_NOME];
    char compara[TAM_NOME];

    printf("Informe parte do nome que deseja procurar: ");
    fgets(pesquisa, TAM_NOME, stdin);
    for(int i = 0; pesquisa[i] != '\0'; i++){
            if(pesquisa[i] == '\n'){
                pesquisa[i] = '\0';
            }
    }

    //Imprime Contatos que contém a string inserida
    printf("| %-11s | %-31s | %-30s | %-20s |\n", "CPF", "NOME", "ENDERECO", "TELEFONE");
    for(int i = 0; i < agenda->qnt; i++){
        strcpy(compara, agenda->lista[i].nome);
        for(int i = 0; i < strlen(compara); i++){
            compara[i] = tolower(compara[i]);
        }

        for(int i = 0; i < strlen(pesquisa); i++){
            pesquisa[i] = tolower(pesquisa[i]);
        }
        if(strstr(compara, pesquisa)){
            printf("| %-11d | %-31s | %-30s | %-20s |\n", agenda->lista[i].cpf, agenda->lista[i].nome, agenda->lista[i].end, agenda->lista[i].tel);
        }
    }
    printf("\n");
}


int main(int argc, char ** argv){

    char lixo;
    int op;

    //Inicializa Agenda
    agenda_t * agenda;
    agenda = (agenda_t*) malloc(1 * sizeof(agenda_t));
    agenda->qnt = 1;

    //Inicializa Lista de Contatos da agenda
    contato_t * lista;
    lista = (contato_t*) calloc(agenda->qnt, sizeof(contato_t));
    agenda->lista = lista;

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

    free(lista);
    free(agenda);


    return OK;
}
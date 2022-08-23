#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0

#define TAMANHO_NOME (30+1)
#define TAMANHO_END (30+1)
#define TAMANHO_TEL (11+1)

//typedef bool_t;
#define TRUE (1==1)
#define FALSE !TRUE


typedef struct agenda {

    //Formato da Agenda Criada

    int id;
    char nome[TAMANHO_NOME];
    char end[TAMANHO_END];
    char tel[TAMANHO_TEL];

    /* char * não funciona, está sendo substituido
    char * nome;
    char * end;
    char * tel;
    */
} contato;


void tiraBarraN(contato * lista, int qnt){

        //Se o caractere da string encontrado for um \n, então ele substitui por \0
        //Assim elimina o \n automatico do fgets(), para não atrapalhar a tabela

        for(int i = 0; lista[qnt-1].nome[i] != '\0'; i++){
            if(lista[qnt-1].nome[i] == '\n'){
                lista[qnt-1].nome[i] = '\0';
            }
        }

        for(int i = 0; lista[qnt-1].end[i] != '\0'; i++){
            if(lista[qnt-1].end[i] == '\n'){
                lista[qnt-1].end[i] = '\0';
            }
        }

        for(int i = 0; lista[qnt-1].tel[i] != '\0'; i++){
            if(lista[qnt-1].tel[i] == '\n'){
                lista[qnt-1].tel[i] = '\0';
            }
        }

}

void cadastraContato(contato * lista, int qnt){

    if(qnt>1){ //Apenas altera tamanho do vetor se não for o primeiro valor
        lista = (contato*) realloc(lista, qnt * sizeof(contato));
    }

        /* malloc dos char * 
        lista[qnt-1].nome = (char*) malloc(TAMANHO_NOME * sizeof(char));
        lista[qnt-1].end = (char*) malloc(TAMANHO_END * sizeof(char));
        lista[qnt-1].tel = (char*) malloc(TAMANHO_TEL * sizeof(char));
        */

        //Recebe Nome endereço e telefone do contato
        printf("\nInforme seu nome: ");
        fgets((lista[qnt-1].nome), TAMANHO_NOME, stdin);
        printf("Informe endereco do contato: ");
        fgets((lista[qnt-1].end), TAMANHO_END, stdin);
        printf("Informe telefone do contato: ");
        fgets((lista[qnt-1].tel), TAMANHO_TEL, stdin);

       //Gera ID do contato adicionado
        lista[qnt-1].id = (qnt-1) + 100; 

        //Função Estética para a tabelação
        tiraBarraN(lista, qnt);
        
}

void listagemContatos(contato * lista, int qnt){

    //Função estética para criação de tabela

    printf("| %-4s | %-31s | %-20s | %-20s |\n", "ID", "NOME", "ENDERECO", "TELEFONE");
    
    for(int i = 0; i < qnt-1; i++){
        printf("| %-4d | %-31s | %-20s | %-20s |\n", lista[i].id, lista[i].nome, lista[i].end, lista[i].tel);
    }

    printf("\n");
    
}

void buscaContatosNome(contato * lista, int qnt){

    char pesquisa[TAMANHO_NOME];
    char compara[TAMANHO_NOME];

    printf("Informe parte do nome que quer buscar: ");
    fgets(pesquisa, TAMANHO_NOME, stdin);

    for(int i = 0; pesquisa[i] != '\0'; i++){
            if(pesquisa[i] == '\n'){
                pesquisa[i] = '\0';
            }
    }

    printf("| %-4s | %-31s | %-20s | %-20s |\n", "ID", "NOME", "ENDERECO", "TELEFONE");
    for(int i = 0; i < qnt-1; i++){

        strcpy(compara, lista[i].nome);
        for(int i = 0; i < strlen(compara); i++){
             compara[i] = tolower(compara[i]);
        }

        for(int i = 0; i < strlen(pesquisa); i++){
             pesquisa[i] = tolower(pesquisa[i]);
        }

        if(strstr(compara, pesquisa)){
            printf("| %-4d | %-31s | %-20s | %-20s |\n", lista[i].id, lista[i].nome, lista[i].end, lista[i].tel);
        }
    }

}

/*void buscaContatosId(contato * lista, int qnt){

}*/

int main(int argc, char ** argv){

    char lixo;
    int op, qnt=1;
    contato *lista;
    lista = (contato*) calloc(qnt, sizeof(contato));

    do{
        printf("1- Cadastrar novo contato\n2- Listar Contatos\n3- Buscar Contato por parte do nome\n0- Sair\nOption: ");
        scanf("%d%c", &op, &lixo);

        switch(op){
            case 1: 
                    cadastraContato(lista, qnt);
                    qnt++;
            break;
            case 2: listagemContatos(lista, qnt);
            break;
            case 3: 

                    buscaContatosNome(lista, qnt);
            break;
        }
        
    }while(op != 0);


    //Libera memoria alocada durante o programa
    for(int i = 0; i < qnt; i++){
        free(lista[i].nome);
        free(lista[i].end);
        free(lista[i].tel);
    }
    free(lista);

    return OK;
}
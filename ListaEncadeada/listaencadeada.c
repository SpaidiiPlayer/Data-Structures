#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

/*
*   O Objetivo do código é fazer uma lista encadeada em c que contenha:
*   Inserção no inicio, Inserção no final, Inserção ordenada,
*   Remoção no inicio, Remoção no fim, Liberação da lista e Exibição da Lista.
*   
*   Utilizando alocação dinâmica.
*/

struct no{
    struct no *prox;
    int dado;
};

//Funcao que insere dado no inicio.
void insereInicio(int numero, no **lista){
    no *novo = malloc(sizeof(no));  //Pergunta se pode alocar na memoria
    if(novo){                       //se sim
        
        novo->dado = numero;             //Insere o valor

        novo->prox = *lista;             //Novo proximo recebe o começo da lista

        *lista = novo;                   //Começo da lista passa ser o novo.

    } else {                        //se não pode alocar memoria
        printf("\nNao foi possivel alocar memoria");
    }
}


//Funcao que insere dado no fim.
void insereFim(int x, no **lista){
    no *novo = malloc(sizeof(no));
    no *aux;

    if(novo){

        novo->prox = NULL;          //Novo proximo é Null, já que ele está sendo inserido no final
        novo->dado = x;             //Insere o dado

        if(!*lista){                //se a lista estiver vazia
            *lista = novo;              
            return;
        }
        
        aux = *lista;

        while(aux->prox){           //Percorre a lista até chegar no seu fim
            aux = aux->prox;
        }
        aux->prox = novo;

    } else {
        printf("\nNao foi possivel alocar memoria");
    }
}


//Funcao que insere dado de forma ordenada.
void insereOrdenado(int numero, no **lista){
    no *novo = malloc(sizeof(no));
    no *aux = *lista;
    if(novo){
        novo->dado = numero;
        novo->prox = NULL;    
        if(!*lista){                    //Caso a lista esteja vazia
            *lista = novo;
            return;
        }
        if(numero < (*lista)->dado){    //caso o numero seja menor que o primeiro item na lista, ele sera inserido no começo
            novo->prox = *lista;
            *lista = novo;
            return;
        }

            while( aux->prox && aux->prox->dado < numero){    //percorre e só para quando encontrar um numero maior ou quando chegar ao fim da lista
                
                aux = aux->prox;
                
            }

            if(aux->prox){      //se tiver proximo é porque encontrou um numero maior durante o while
                novo->prox = aux->prox;
                aux->prox = novo;
                return;
            }
            aux->prox = novo;   //Caso contrario apenas é adicionado no fim

    } else {
            printf("\nNao foi possivel alocar na memoria");
    }
}


//Funcao que remove o dado inicial da lista
void removeInicio(no **lista){

    if(!*lista){                //Caso a lista esteja vazia
        printf("\nA lista ja está vazia");
        return;
    }

    *lista = (*lista)->prox;
}



//Funcao que remove o dado final da lista
void removeFim(no **lista){

    no *aux = *lista;
    no *auxAnterior;

    if(!*lista){                //Caso a lista esteja vazia
        printf("\nA lista ja está vazia");
        return;
    }

    if(!(*lista)->prox){        //caso a lista só tenha um item
        *lista = NULL;
        free(aux);
        return;
    }

    while(aux->prox){           //percorre a lista até chegar no final
        auxAnterior = aux;
        aux = aux->prox;
    }
    auxAnterior->prox = NULL;   //remove o fim da lista
    free(aux);
}



//Funcao libera a lista da alocação
void liberalista(no** lista){
    no *aux = *lista;           
    while(aux){         
        no* aux2 = aux->prox;       //armazena o proximo
        free(aux);                  //libera o dado
        aux = aux2;                 //o auxiliador recebe o proximo
    }
}



//Funcao que exibe a lista
void exibelista(no** lista){
    no *aux = *lista;
    if(!*lista){                    //caso a lista esteja vazia
        printf("\nLista vazia\n");
        return;
    }
    while(aux->prox){               //Enquanto haver proximo
        printf("%d ", aux->dado);   //Será exibido o dado
        aux = aux->prox;
    }
    printf("%d ", aux->dado);       //Mostrando o ultimo dado
}




//Main
void main(){
    no* lista = NULL;
    int opcao, dado;

    //Menu
    do{
        printf("\nEscolha uma opcao valida:\n");
        printf("1) Inserir no comeco \n2) Inserir no fim \n3) Inserir ordenado \n4) Remover inicio \n5) Remover final \n6) Exibir Lista \n0) Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                    liberalista(&lista);
                    printf("Saindo...");
                break;
            case 1:
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &dado);
                    insereInicio(dado, &lista);
                break;
            case 2:
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &dado);
                    insereFim(dado, &lista);
                break;
            case 3:
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &dado);
                    insereOrdenado(dado, &lista);
                break;
            case 4:
                    printf("Removendo inicio...");
                    removeInicio(&lista);
                break;
            case 5:
                    printf("Removendo fim...");
                    removeFim(&lista);
                break;
            case 6:
                    printf("=-=-=-=Lista=-=-=-=\n");
                    exibelista(&lista);
                break;

            default:
                    printf("Digite uma opcao VALIDA.");
                break;
        }

    }while(opcao!=0);

    return;
}
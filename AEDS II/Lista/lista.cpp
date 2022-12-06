/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

#include "lista.h"

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista* inicia_lista() {
	tLista* tmp = new (tLista);
	tmp->tam = 0;
	tmp->lista = NULL;

        cout << "-A lista foi iniciada."<<endl;
	return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista * encerra_lista(tLista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @return verdareiro se o elemento foi encontrado.
 */
no * busca(tLista * ptlista, int valor) {
    no *aux, *no1 = NULL;

    aux = ptlista->lista;
    while(aux && aux->valor != valor)
        aux = aux->prox;
    if(aux)
        no1 = aux;
    return no1;
}

/**
 * Realiza a insercao do elemento no início da lista ligada.
 * @param valor a ser inserido.
 */
void insere_inicio(tLista * ptlista, int valor){
    no *novo = new (no);
    if(novo){
        novo->valor=valor;
        novo->prox=ptlista->lista;
        ptlista->lista=novo;
        ptlista->tam++;
    }
    else
        printf("Erro ao inserir no inicio.\n");
}

/**
 * Realiza a insercao do elemento no fim da lista ligada.
 * @param valor a ser inserido.
 */
void insere_fim(tLista * ptlista, int valor){
    no *aux, *novo = new(no);
    if(novo){
        novo->valor=valor;
        novo->prox=NULL;
        if(ptlista->lista==NULL)
            ptlista->lista=novo;
        else{
            aux=ptlista->lista;
            while(aux->prox)
                aux=aux->prox;
            aux->prox=novo;
        }
        ptlista->tam++;
    }
    else
        printf("Erro ao inserir no fim.\n");
}

/**
 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_inicio(tLista * ptlista){
    if(ptlista->lista==NULL){
        printf("Lista já está vazia\n");
        return NULL;
    }else{
        no *tmp = ptlista->lista;
        ptlista->lista=tmp->prox;
        return tmp;
    }
    
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_fim(tLista * ptlista){
    if(ptlista->lista==NULL){
        printf("Lista ja vazia\n\n");
        return NULL;
    }else{
        no *ultimo = ptlista->lista;
        no *penultimo = ptlista->lista;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo=ultimo->prox;
        }
        penultimo->prox = NULL;
        return ultimo;
    }
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista * ptlista){
    no *no1 = ptlista->lista;
    printf("\n\tLista tam %d: ", ptlista->tam);
    while(no1){
        printf("%d ", no1->valor);
        no1=no1->prox;
    }
    printf("\n\n");
}


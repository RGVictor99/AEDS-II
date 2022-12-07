#include <iostream>
#include <stdlib.h>

using namespace std;

// estrututa nó
typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

// estrutura árvore com um ponteiro para um nó
typedef struct
{
    No *raiz;
    int tam;
} ArvB;

/*  Assinatura do procedimento inserirDireita()
    necessário pois é utilizado no procedimento inserirEsquerda,
    antes deste ser criado
*/
void inserirDireita(No *no, int valor);

void inOrder(No *atual)
{
    if (atual != NULL)
    {
        inOrder(atual->esquerda);
        cout << atual->conteudo << " ";
        inOrder(atual->direita);
    }
}
void posOrder(No *atual)
{
    if (atual != NULL)
    {
        posOrder(atual->esquerda);
        posOrder(atual->direita);
        cout << atual->conteudo << " ";
    }
}
void preOrder(No *atual)
{
    if (atual != NULL)
    {
        cout << atual->conteudo << " ";
        preOrder(atual->esquerda);
        preOrder(atual->direita);
    }
}

// procedimento para inserir um elemento na subárvore esquerda
void inserirEsquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }
    else
    {
        if (valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        if (valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}

// procedimento para inserir um elemento na subárvore direita
void inserirDireita(No *no, int valor)
{
    if (no->direita == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }
    else
    {
        if (valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if (valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
}

/*  nova versão para a inserção, mais resumida
    perceba que agora é uma função
*/
No *inserirNovaVersao(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else
    {
        if (valor < raiz->conteudo)
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        if (valor > raiz->conteudo)
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        return raiz;
    }
}

// função que retorna o tamanho de uma árvore
int tamanho(No *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

// função para buscar um elemento na árvore
int buscar(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        if (raiz->conteudo == chave)
            return 1;
        else
        {
            if (chave < raiz->conteudo)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}
/*  faz a impressão da árvore em ordem crescente
    esquerda - raiz - direita
*/
void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esquerda);
        cout << raiz->conteudo << " ";
        imprimir(raiz->direita);
    }
}

// função para a remoção de um nó
No *remover(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        cout << "Valor nao encontrado!" << endl;
        return NULL;
    }
    else
    {
        if (raiz->conteudo == chave)
        {
            // remove nós folhas (nós sem filhos)
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                return NULL;
            }
            else
            {
                // remover nós que possuem apenas 1 filho
                if (raiz->esquerda == NULL || raiz->direita == NULL)
                {
                    No *aux;
                    if (raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else
                {
                    No *aux = raiz->esquerda;
                    while (aux->direita != NULL)
                        aux = aux->direita;
                    raiz->conteudo = aux->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
            }
        }
        else
        {
            if (chave < raiz->conteudo)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

// ffunção principal
int main()
{
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    No *raiz = NULL;

    do
    {
        cout << "\n0 - sair\n1 - inserir\n2 - imprimir\n3 - Buscar\n4 - Remover\n";
        cin >> op;

        switch (op)
        {
        case 0:
            cout << "\nSaindo...\n";
            break;
        case 1:
            cout << "Digite um valor: ";
            cin >> valor;
            raiz = inserirNovaVersao(raiz, valor); // não precisa da estrutura ArvB
            // inserir(&arv, valor);// para utilizar esta inserção, comente a anterior
            break;
        case 2:
            cout << "\nImpressao da arvore binaria:\n";
            imprimir(raiz);
            cout << endl;
            cout << "Tamanho: " << tamanho(raiz) << endl;
            cout << "Em-ordem: ";
            inOrder(raiz);
            cout << endl;
            cout << "Pós-ordem: ";
            posOrder(raiz);
            cout << endl;
            cout << "Pré-ordem: ";
            preOrder(raiz);
            cout << endl;
            break;
        case 3:
            cout << "Qual valor deseja buscar? ";
            cin >> valor;
            cout << "Resultado da busca: " << buscar(raiz, valor) << endl;
            break;
        case 4:
            cout << "Digite um valor a ser removido: ";
            cin >> valor;
            raiz = remover(raiz, valor);
            break;
        default:
            cout << "\nOpcao invalida...\n";
        }
    } while (op != 0);
}
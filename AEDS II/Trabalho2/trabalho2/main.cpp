/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: JOSÉ ARGEMIRO DOS REIS NETO - 2021.1.08.011
 *         VICTOR RIBEIRO GONCALEZ - 2021.1.08.023
 *
 * Created on 30 de novembro de 2022, 11:37
 */

#include <iostream>
#include <fstream>

using namespace std;
typedef struct info_
{
    string modelo;
    string marca;
    string tipo;
    int ano;
    int quilometragem;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    string placa;
    int preco;
}info;

typedef struct no_
{
    info * dados;
    no_ * prox;
}no;

typedef struct cabeca
{
    no_ * inicio;
    int tam;
    no_ * fim;
}cabecalho;


cabecalho* inicia_lista () 
{
    cabecalho * tmp = new cabecalho;
    tmp->inicio = NULL;
    tmp->tam = 0;
    tmp->fim = NULL;
    return tmp;
}

/**
 * @brief Faz uma busca na lista encadeada ordenada 
 * 
 * @param ptlista cabeça da lista
 * @param placa do veiculo 
 * @param ant ponteiro de ponteiro que guarda o nó anterior ao da placa quando encontrada
 * @param pont NULL se o veiculo não esta na lista ou aponta para o veiculo se esta na lista
 */
void busca_lista(cabecalho * ptlista, string placa, no**ant, no**pont) 
{
    no * ptr = ptlista->inicio;
    *pont = NULL;
    *ant = ptlista->inicio;
    while (ptr != NULL) {
        if (ptr->dados->placa < placa) {
            *ant = ptr;
            ptr = ptr->prox;
        } else {
            if (ptr->dados->placa == placa) {
                *pont = ptr;
            } 
            ptr = NULL;
        }
    }
}
/**
 * @brief Insere um veiculo no inicio da lista
 * 
 * @param ptlista cabeça da lista
 * @param dados do veiculo a ser inserido 
 */
void insere_inicio(cabecalho * ptlista, info * dados)
{
    no * tmp = new no;

    tmp->dados = dados;

    if (ptlista->tam == 0) {
        tmp->prox = NULL;
        ptlista->inicio = tmp;
        ptlista->fim = tmp;
    } else {
        tmp->prox = ptlista->inicio;
        ptlista->inicio = tmp;
    }
    ptlista->tam++;
}
/**
 * @brief Insere um veiculo no fim da lista
 * 
 * @param ptlista cabeça da lista
 * @param dados do veiculo a ser inserido 
 */ 
void insere_fim(cabecalho * ptlista, info * dados)
{
    no * tmp = new no;

    tmp->dados = dados;

    if (ptlista->tam == 0) {
        tmp->prox = NULL;
        ptlista->inicio = tmp;
        ptlista->fim = tmp;
    } else {
        tmp->prox = NULL;
        (ptlista->fim)->prox = tmp;
        ptlista->fim = tmp;
    }
    ptlista->tam++;
}
/**
 * @brief Insere um veiculo na lista de forma ordenada utilizado a função de busca, para evitar percorrer toda a lista no caso do veiculo ser o ultimo a função insere_inicio e insere_fim são utilizadas
 * 
 * @param ptlista cabeça da lista
 * @param dados do veiculo a ser inserido 
 * @return 0 no caso de sucesso e -1 no fracasso
 */
int insere_lista(cabecalho * ptlista, info * dados) 
{
    no * ant;
    no * pont;

    int retorno = -1;

    if (ptlista->inicio == NULL || ptlista->inicio->dados->placa > dados->placa) {
        insere_inicio(ptlista, dados);
        retorno = 0;
    } else if (ptlista->fim->dados->placa < dados->placa) {
        insere_fim(ptlista, dados);
        retorno = 0;
    } else {
        busca_lista(ptlista, dados->placa, &ant, &pont);

        if (pont == NULL) {
            no * tmp = new no;
            tmp->dados = dados;
            tmp->prox = ant->prox;
            ant->prox = tmp;
            ptlista->tam++;   
            retorno = 0; 
        }    
    }
    return retorno;
}
/**
 * @brief Remove um veiculo do inicio da lista
 * 
 * @param ptlista cabeça da lista
 * @param dados do veiculo a ser removido
 */
no * remove_inicio(cabecalho * ptlista)
{
    if (ptlista->tam == 1) {
        no * tmp = ptlista->inicio;
        ptlista->inicio = NULL;
        ptlista->fim = NULL;
        delete tmp;
    } else if (ptlista->tam > 1) {
        no * tmp = ptlista->inicio;
        ptlista->inicio = tmp->prox;
        delete tmp; 
    }
    ptlista->tam--;
}
/**
 * @brief Remove um veiculo do fim da lista
 * 
 * @param ptlista cabeça da lista
 * @param dados do veiculo a ser removido
 */
no * remove_fim(cabecalho * ptlista)
{
    if (ptlista->tam == 1) {
        no * tmp = ptlista->inicio;
        ptlista->inicio = NULL;
        ptlista->fim = NULL;
        delete tmp;
    } else if (ptlista->tam > 1) {
        no * tmp = ptlista->inicio;
        while (tmp->prox != ptlista->fim) {
            tmp = tmp->prox;
        }
        delete tmp->prox; 
        tmp->prox = NULL;
        ptlista->fim = tmp;
    }
    ptlista->tam--;
}
/**
 * @brief Remove um veiculo na lista de forma ordenada utilizado a função de busca, para evitar percorrer toda a lista no caso do veiculo ser o ultimo a função remove_inicio e remove_fim são utilizadas
 * 
 * @param ptlista cabeça da lista
 * @param dados do veiculo a ser inserido 
 * @return 0 no caso de sucesso e -1 no fracasso
 */
info * remove_lista(cabecalho * ptlista, string placa) 
{
    no * ant;
    no * pont;

    info * recuperado = NULL;

    if (ptlista->inicio->dados->placa == placa) {
        recuperado = ptlista->inicio->dados;
        remove_inicio(ptlista);
    } else if (ptlista->fim->dados->placa == placa) {
        recuperado = ptlista->fim->dados;
        remove_fim(ptlista);
    } else {
        busca_lista(ptlista, placa, &ant, &pont);  

        if (pont != NULL) {
            ant->prox = pont->prox;
            recuperado = pont->dados;
            ptlista->tam--;
            delete pont;
        }  
    }    
    return recuperado;
}

/**
 * @brief Cria e le as informações de um novo veiculo
 * 
 * @return A struct com as informações do veiculo
*/
info * cria_dados()
{
    info * tmp = new info;
    cout << "modelo: ";
    cin >> tmp->modelo;
    cout << "marca: ";
    cin >> tmp->marca;
    cout << "tipo: ";
    cin >> tmp->tipo;
    cout << "ano: ";
    cin >> tmp->ano;
    cout << "KM: ";
    cin >> tmp->quilometragem;
    cout << "potencia: ";
    cin >> tmp->potencia;
    cout << "combustivel: ";
    cin >> tmp->combustivel;
    cout << "cambio: ";
    cin >> tmp->cambio;
    cout << "direcao: ";
    cin >> tmp->direcao;
    cout << "cor: ";
    cin >> tmp->cor;
    cout << "portas: ";
    cin >> tmp->portas;
    cout << "placa: ";
    cin >> tmp->placa;
    cout << "valor: ";
    cin >> tmp->preco;
    return tmp;
}

void imprime_lista(cabecalho * ptlista) 
{
    no * tmp = ptlista->inicio;
    while (tmp != NULL) {
        cout << tmp->dados->modelo << " ";
        cout << tmp->dados->marca << " ";
        cout << tmp->dados->tipo << " ";
        cout << tmp->dados->ano << " ";
        cout << tmp->dados->quilometragem << " ";
        cout << tmp->dados->potencia << " ";
        cout << tmp->dados->combustivel << " ";
        cout << tmp->dados->cambio << " ";
        cout << tmp->dados->direcao << " ";
        cout << tmp->dados->cor << " ";
        cout << tmp->dados->portas << " ";       
        cout << tmp->dados->placa << " ";
        cout << tmp->dados->preco << ".00;";
        cout << endl;
        tmp = tmp->prox;
    }
    cout << endl << endl;
}
/**
 * @brief le o arquivo do banco de dados e a cada leitura já insere de forma ordenada na lista
 * 
 * @param ptlista cabeça da lista
*/
void le_arq(cabecalho * ptlista)
{
    string line;
    ifstream dados("BD_veiculos.txt");
    if (dados.is_open())
    {
        while ( !dados.eof() )
        {
            info * tmp = new info;
            float potencia;
            dados >> tmp->modelo;
            dados >> tmp->marca;
            dados >> tmp->tipo;
            dados >> tmp->ano;
            dados >> tmp->quilometragem;
            dados >> tmp->potencia;
            dados >> tmp->combustivel;
            dados >> tmp->cambio;
            dados >> tmp->direcao;
            dados >> tmp->cor;
            dados >> tmp->portas;
            dados >> tmp->placa;
            dados >> tmp->preco;
            insere_lista(ptlista, tmp);
        }
        dados.close();
    }
}

void encerra_lista(cabecalho * ptlista)
{
    no * ant;
    no * ptr;
    if (ptlista->inicio != NULL) {
        ant = ptlista->inicio;
        ptr = (ptlista->inicio)->prox;
        while (ptr != NULL) {
            delete ant;
            ant = ptr;
            ptr = ptr->prox;
        }
        delete ant;     
        ptlista->tam = 0;
        ptlista->inicio = NULL;
        ptlista->fim = NULL;           
    } else {
        delete ptlista;
    }
}

/**
 * 
 * @param dados
 * @param operador_busca
 * @param param_busca_string
 * @return 
 */
int verifica_busca(info * dados, int operador_busca, string param_busca_string)
{
    int verifica = -1;
        switch(operador_busca)
        {   
        case 0:
            if (dados->cambio == param_busca_string) {
                verifica = 0;
            }
            break;    
        case 1:
            if (dados->direcao == param_busca_string) {
                verifica = 0;
            }
            break; 
    }
    return verifica;
}
/**
 * @brief percorre a lista buscando os que possuem cambio automatico
 * 
 * @param ptlista lista encadeada
 * @param ptfila fila que guarda os veiculos
*/
void gera_fila(cabecalho * ptlista, cabecalho * ptfila)
{
    no * tmp = ptlista->inicio;

    while (tmp != NULL) {
        if(tmp->dados->cambio == "Automático")
            insere_fim(ptfila, tmp->dados);
        tmp = tmp->prox;
    }
}
/**
 * @brief percorre a lista buscando os que possuem direção hidraulica
 * 
 * @param ptlista lista encadeada
 * @param ptfila pilha que guarda os veiculos
*/
void gera_pilha(cabecalho * ptlista, cabecalho * ptpilha)
{
    no * tmp = ptlista->inicio;

    while (tmp != NULL) {
        if(tmp->dados->direcao == "Hidráulica")
            insere_inicio(ptpilha, tmp->dados);
        tmp = tmp->prox;
    }
}

int main (void) 
{
    cabecalho * lista = inicia_lista();
    cabecalho * pilha = inicia_lista();
    cabecalho * fila = inicia_lista();
    le_arq(lista);
    
    int param, tipo;
    string placa;
    info * dados = new info;

    cout << "Bem vindo!" << endl;

    do{
        cout << endl << "========================================" << endl;
        cout << "1 - Insere novo nó" << endl;
        cout << "2 - Remove nó" << endl;
        cout << "3 - Busca por fila/pilha" << endl;
        cout << "4 - Relatorio da lista" << endl;
        cout << "5 - Fechar o programa" << endl;
        cout << "========================================" << endl;
        cin >> param;
        switch (param)
        {
        case 1:
            dados = cria_dados();
            cout << "nó inserido" << endl;
            insere_lista(lista, dados);
            break;
        case 2:
            cout << "Digite a placa a ser removida: ";
            cin >> placa;
            dados = remove_lista(lista, placa);
            break;
        case 3:
            cout << "(0) fila (1) Pilha" << endl;
            cin >> tipo;

            if(tipo == 0){
                gera_fila(lista, fila);
                imprime_lista(fila);
            } else {
                gera_pilha(lista, pilha);
                imprime_lista(pilha);
            }
            break;
        case 4:
            imprime_lista(lista);
            break;
        case 5:
            cout << endl << "Consulta encerrada." << endl;
            break;
        default:
            cout << "Digite um valor valido!" << endl;
            break;
        }
    } while (param != 5);
    
    encerra_lista(lista);
    encerra_lista(pilha);
    encerra_lista(fila);
    delete lista;
    delete pilha;
    delete fila;
    
    return 0;
}
#ifndef PILHA_H
#define PILHA_H
#include "lista.h"

typedef tLista tFila;

inline tFila* inicia_fila(){
    return inicia_lista();
}

inline tFila * encerra_pilha(tFila * p){
    return encerra_lista(p);
}

inline void push (tFila *p, int valor){
    insere_inicio(p,valor);
}
inline no * pop(tFila *p){
    return remove_inicio(p);
}
#endif /* pilha_H */


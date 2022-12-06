/* 
 * File:   main.cpp
 * Author: flavio, paulo
 *
 * Created on January 26, 2021, 11:00 AM
 */

#include <iostream>
#include <stdlib.h>
#include "fila.h"

using namespace std;

tFila* fila1;

/*
 * 
 */
int main() {
    no * p;
   fila1 = inicia_fila();

    push(fila1, 5);
    cout<<"push pilha 1: ";
    imprime(fila1);

    push(fila1, 10);
    cout<<"push pilha 2: ";
    imprime(fila1);

    push(fila1, 15);
    cout<<"push pilha 3: ";
    imprime(fila1);

   p = pop(fila1);
   cout<<"pop pilha1"<<p->valor <<endl;

}
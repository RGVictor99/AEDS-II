

#include <iostream>
#include <stdlib.h>
#include "pilha.h"

using namespace std;

tPilha * pilha1;

/*
 * 
 */
int main() {
    no * p;
    pilha1 = inicia_pilha();

    push(pilha1, 5);
    cout<<"push pilha 1: ";
    imprime(pilha1);

    push(pilha1, 10);
    cout<<"push pilha 2: ";
    imprime(pilha1);

    push(pilha1, 15);
    cout<<"push pilha 3: ";
    imprime(pilha1);

   p = pop(pilha1);
   cout<<"pop pilha1"<<p->valor <<endl;

}
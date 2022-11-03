#include <iostream>
#include "ordena.h"

using namespace std;

void imprimevetor(int *v){
    for (int *p = v; p < v+10; p++)
        cout << " " << *p;
    cout << endl;
}

int main (int argc, char**argv){
    
    cout << endl << " Métodos de Ordenação" << endl << endl;

    int vb0[10] = {0,1,2,3,4,5,6,7,8,9}; // ordenado
    int vb1[10] = {5,8,2,0,6,9,1,4,3,7}; // desordenado
    int vb2[10] = {9,8,7,6,5,4,3,2,1,0}; // inverso

    /*cout << " Blubble sort, vetor ordenado: " << endl;
    imprimevetor(vb0);
    bubblesort(vb0);
    imprimevetor(vb0);
    cout << "-----------------------------------" << endl;
    cout << " Blubble sort, vetor desordenado: " << endl;
    imprimevetor(vb1);
    bubblesort(vb1);
    imprimevetor(vb1);
    cout << "-----------------------------------" << endl;
    cout << " Blubble sort, vetor inverso: " << endl;
    imprimevetor(vb2);
    bubblesort(vb2);
    imprimevetor(vb2);
*/

/*  cout << " Insertion sort, vetor ordenado: " << endl;
    imprimevetor(vb0);
    insertionsort(vb0);
    imprimevetor(vb0);
    cout << "-----------------------------------" << endl;
    cout << " Insertion sort, vetor desordenado: " << endl;
    imprimevetor(vb1);
    insertionsort(vb1);
    imprimevetor(vb1);
    cout << "-----------------------------------" << endl;
    cout << " Insertion sort, vetor inverso: " << endl;
    imprimevetor(vb2);
    insertionsort(vb2);
    imprimevetor(vb2);
*/

    cout << " Selection sort, vetor ordenado: " << endl;
    imprimevetor(vb0);
    selectionsort(vb0);
    imprimevetor(vb0);
    cout << "-----------------------------------" << endl;
    cout << " Selection sort, vetor desordenado: " << endl;
    imprimevetor(vb1);
    selectionsort(vb1);
    imprimevetor(vb1);
    cout << "-----------------------------------" << endl;
    cout << " Selection sort, vetor inverso: " << endl;
    imprimevetor(vb2);
    selectionsort(vb2);
    imprimevetor(vb2);
}
#include <iostream>

using namespace std;

int x = 11, y = 22, z = 33;
int *p;

int v[] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59};

/* m[5][5] = {{0, 1, 2, 3, 4}, 
            {10, 11, 12, 13, 14}, 
            {20, 21, 22, 23, 24},
            {30, 31, 32, 33, 34},
            {40, 41, 42, 43, 44}};
*/


// Função que troca dois valores

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    
}
int main (int argc, char**argv){

   /* cout << "Aritmética de Ponteiros" << endl;
    cout << endl << "Variáveis" << endl; //printf ("\n\t Variáveis \n")

    cout << " X: " << x << " y: " << y << " z: " << z << endl;
    cout << " &x: " << &x << " &y: " << &y << " &z: <<" << &z << endl;

    p = &x;
    cout << " p: " << p << " *p: " << *p << endl;
    p++;
    cout << " p: " << p << " *p: " << *p << endl;
    p++;
    cout << " p: " << p << " *p: " << *p << endl;

    /*
    p -= 2;
    cout << " p: " << p << " *p: " << *p << endl;
    */

   /*cout << endl << "Vetores" << endl;
   for (int i  = 0; i < 10; i++){
    cout << " i: " << i << " v[i]: " << v[i] << " &v[i]: " << &v[i] << endl;
   }

   cout << endl;

   for (int i  = 0; i < 10; i++){
    cout << " i: " << i << " *(v+i): " << *(v+i) << " (v+i): " << (v+i) << endl;
   }

   cout << endl << "Ponteiros com Vetores" << endl;
   for (p = v; p < v + 10; p++){
    cout << " *p: " << *p << " p: " << p << endl;
   }
*/
cout << "Antes da função " << x << " " << y << endl;
troca(&x, &y);
cout << "Depois da função " << x << " " << y << endl;
}
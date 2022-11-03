#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int inst = 0, tamanho;
int *z;

/*void HeapSort(int n, int v[])
{
}*/

void debug(int p,int r, int v[] ){
    inst++;
    cout <<endl<<" "<<inst<<"ª instânca p = "<<p<<" r = "<<r<<" -> ";
    for (int * z = v; z<v+tamanho;z++)
        cout << *z << " ";
}
int* inicializa(int tam){
    //int *v = (int *)malloc(tam*sizeof(int));
    int *v = new int[tam];
    int *p;
    srand(time(NULL));
    for (p=v;p<v+tam;p++){
        *p=rand() % 100;
    }
    return v;
}

void intercala1 (int p, int q, int r, int v[]){
    int *w;
    w = (int *)malloc((r-p) * sizeof (int));
    int i = p, j = q;
    int k = 0;
    while (i < q && j <r){
        if(v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i<q)
        w[k++] = v[i++];
    while(j<r)
        w[k++] = v[j++];
    for(i=p;i<r; ++i)
        v[i] = w[i-p];
    free (w);
}

void MergeSort (int p, int r, int v[]) {
    if (p < r-1){
        int q = (p+r)/2;
        MergeSort (p,q,v);
        MergeSort (q,r,v);
        intercala1(p,q,r,v);
    }
}

int separa (int v[], int p, int r){
    int c = v[r];
    int temp, j = p;
    for (int k = p;k<r;k++){
        if(v[k] <=c){
            temp = v[j];
            v[j] = v[k];
            v[k] = temp;
            ++j;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void QuickSort(int v[], int p, int r){
    if(p<r){
        int j = separa(v,p,r);
        QuickSort(v,p,j-1);
        QuickSort(v,j+1,r);
    }
    //debug(0,10,v);
}

int main(int argc, char **argv)
{
    int *v;
    //int v[] = {0, 3, 4, 6, 1, 2, 5, 7, 8, 9};
    //int a[4] = {0, 3, 4, 7};
    //int b[6] = {1, 2, 5, 6, 8, 9};
    //int c[10];
    //int i = 0, j = 0, k = 0;
    //int *p;
    //a[i] b[j] c[k]

   /* while (i < 4 && j < 6){
        if(a[i] < b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    if (i < 4)
        while (i < 4){
            c[k++] = a[i++];
        }
    if (j < 6)
        while(j < 6){
            c[k++] = b[j++];
        }
    */
   v = inicializa(10);
   //MergeSort(0,10,v);
   QuickSort(v,0,9);
   cout << "{  ";
    for(int k = 0; k < 10; k++){
        cout << v[k] << " ";
    }
    cout << "}";
    delete [] v;
    //free(v);
}   
void bubblesort(int *v){
    int aux;
    for (int *p = v+9; p > v; p--)
        for (int *q = v; q < p; q++)
            if (*q > *(q+1)){
                aux = *q;
                *q = *(q+1);
                *(q+1) = aux;
            }
}

void insertionsort(int *v){
    int aux, *q;
    for (int *p = v+1; p < v+10; p++){
        aux = *p;
        q = p - 1;
        while (q >= v && *q > aux){
            *(q+1) = *q;
            q--;
        }
        *(q+1) = aux;
    }
}

void selectionsort(int *v){
    int aux, *min;
    for (int *p = v; p < v+10; p++){
        min = p;
        aux = *p;
        for(int *q = p + 1;q < v+10;q++)
            if (*q < aux){
                aux = *q;
                min = q;
            }
        *min = *p;
        *p = aux;
    }
}
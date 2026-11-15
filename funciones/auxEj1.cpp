int cartelMax(int* placas, int max){
    int i = max;
    while (i>=0){
        if(placas[i]>0) return i;
        i --;
    }
    return -1;
}

int largoSolucion(int* placas, int max){
    int largo= 0;
    bool esImpar = false;
    for(int i=0; i<=max; i++){
        largo += (placas[i]/2)*2;
        if (placas[i]%2 != 0) esImpar = true;
    }
    if (esImpar) largo++;
    return largo;
}


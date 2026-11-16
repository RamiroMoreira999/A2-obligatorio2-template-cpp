void mergeComparo(long long* llegada, long long* aux, long long mitad, long long posI, long long posF){ 
    long long i = posI;
    long long j = mitad + 1;
    long long k = posI;

    while (i <= mitad && j <= posF) {
        if (llegada[i] < llegada[j]) {
            aux[k] = llegada[i];
            k++;
            i++;
        } else {
            aux[k] = llegada[j];
            k++;
            j++;
        }
    }

    while (i <= mitad){
        aux[k] = llegada[i];
        k++;
        i++;
    }
        
    while (j <= posF){
        aux[k] = llegada[j];
        k++;
        j++;
    }     

    for (int x = posI; x <= posF; x++){
        llegada[x] = aux[x];
    }
    
}


long long comparo(long long* llegada, long long* aux, long long posI, long long posF){
    
    if (posI >= posF) return 0;
    
    long long mitad= (posI+posF)/2;

    long long izq = comparo (llegada, aux, posI, mitad);
    long long der = comparo (llegada, aux, mitad+1, posF);

    long long cruzados = 0;
    int j = mitad + 1;

    for (int i = posI; i <= mitad; i++) {
        while (j <= posF && llegada[i] > 2 * llegada[j]) j++;

        cruzados += j - (mitad + 1);
    }

    mergeComparo(llegada,aux,mitad,posI,posF);

    return izq + der + cruzados;

}
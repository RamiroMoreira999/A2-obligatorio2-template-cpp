#include <cstdint>

void mergeComparo(int64_t* llegada, int64_t* aux, int64_t mitad, int64_t posI, int64_t posF){ 
    int64_t i = posI;
    int64_t j = mitad + 1;
    int64_t k = posI;

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


int64_t comparo(int64_t* llegada, int64_t* aux, int64_t posI, int64_t posF){
    
    if (posI >= posF) return 0;
    
    int64_t mitad= (posI+posF)/2;

    int64_t izq = comparo (llegada, aux, posI, mitad);
    int64_t der = comparo (llegada, aux, mitad+1, posF);

    int64_t cruzados = 0;
    int j = mitad + 1;

    for (int i = posI; i <= mitad; i++) {
        while (j <= posF && llegada[i] > 2 * llegada[j]) j++;

        cruzados += j - (mitad + 1);
    }

    mergeComparo(llegada,aux,mitad,posI,posF);

    return izq + der + cruzados;

}
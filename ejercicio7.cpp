#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "funciones/auxEj7.cpp"
#include <cstdint>


int main(){
    int64_t cantRemontadasE=0;
    int64_t  n;
    std:: cin >> n;
    int64_t * llegada = new long long [n]();
    for(int i=0; i<n; i++){
        int64_t corredor;
        std:: cin >> corredor;
        llegada[i] = corredor;
    }

    int64_t  izq=0;
    int64_t der=n-1;

    int64_t * aux = new long long[n]();

    cantRemontadasE = comparo(llegada, aux, izq, der);

    std::cout << cantRemontadasE <<std::endl;

    

    // TODO
    return 0;
}
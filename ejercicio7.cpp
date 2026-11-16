#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "funciones/auxEj7.cpp"



int main(){
    long long cantRemontadasE=0;
    long long n;
    std:: cin >> n;
    long long* llegada = new long long [n]();
    for(int i=0; i<n; i++){
        int corredor;
        std:: cin >> corredor;
        llegada[i] = corredor;
    }

    long long izq=0;
    long long der=n-1;

    long long* aux = new long long[n]();

    cantRemontadasE = comparo(llegada, aux, izq, der);

    std::cout << cantRemontadasE <<std::endl;

    

    // TODO
    return 0;
}
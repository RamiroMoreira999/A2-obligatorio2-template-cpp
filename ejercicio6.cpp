#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./funciones/auxEj1.cpp"


int main(){

    int n;
    std:: cin >> n;
    int* placas = new int[1001](); 
    int max = 0;
    for(int i = 0; i<n; i++){
        int numero;
        std::cin >> numero;
        placas[numero]++;
        if (numero > max) max = numero;
    } 
    int largoPlaca = largoSolucion(placas, max);
    int* ret = new int[largoPlaca](); 
    int i = max;
    int der= largoPlaca-1;
    int izq = 0;
    while ( i>=0 ){
        int cant = placas [i];
        if (cant>=2){
            ret[izq] = i;
            ret [der] = i;
            izq++;
            der--;
            placas[i]-=2;
        }

        else{
            i--;
        }
    }
    if (izq==der) ret[izq] = cartelMax(placas, max);

    for(int i=0; i < largoPlaca; i++){
        std::cout << ret[i];

        if(i < largoPlaca - 1) std::cout << " ";
    }

    

    // TODO
    return 0;
}
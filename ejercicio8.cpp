#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "auxEj8.cpp"

int main(){
    
    int n;
    int pesoHeladera;
    std::cin >> n;
    std::cin >> pesoHeladera;
    int* maxPorCategoria= new int[4]();

    for (int i = 0; i < 4; i++) {
        std::cin >> maxPorCategoria[i];
    }

    int* pesos = new int[n]();
    int* satisfacciones = new int[n]();
    int* categorias = new int[n]();

    for (int i = 0; i < n; i++) {    
        std::cin >> pesos[i];
        std::cin >> satisfacciones[i];
        std::cin >> categorias[i];
    }

    int resultado = mejorCompra(pesos, satisfacciones, categorias, n, pesoHeladera, maxPorCategoria);

    std::cout << resultado << std::endl;

   
    // TODO
    return 0;
}

#include <cassert>
#include <string>
#include <iostream>
#include <limits>


int tab[101][1001][4][4][4][4];

int mejorCompra(int* pesos, int* satisfacciones, int* categorias, int cantProductos, int pesoHeladera, int* maxPorCategoria){
    tab[0][0][0][0][0][0]= 0;
    for (int i = 1; i <= cantProductos; i++){
        int peso = pesos[i];
        int satisfaccion = satisfacciones[i];
        int categoria = categorias[i];

        for (int w = 0; w <= pesoHeladera; w++){

            for (int a = 0; a <= maxPorCategoria[0]; a++){

                for (int c = 0; c <= maxPorCategoria[1]; c++){

                    for (int b = 0; b <= maxPorCategoria[2]; b++){

                        for (int v = 0; v <= maxPorCategoria[3]; v++){

                            // opción 1: no comprar el producto i
                            int mejor = tab[i - 1][w][a][c][b][v];

                            // opción 2: comprarlo, si entra y queda lugar en su categoría
                            int cupo[4] = {a, c, b, v};
                            if (peso <= w && cupo[categoria] > 0)
                            {
                                cupo[categoria]--;
                                int comprandolo = tab[i - 1][w - peso][cupo[0]][cupo[1]][cupo[2]][cupo[3]] + satisfaccion;
                                if (comprandolo > mejor)
                                {
                                    mejor = comprandolo;
                                }
                            }

                            tab[i][w][a][c][b][v] = mejor;

                        }
                    }
                }
            }
        }
        
    }
    return tab[cantProductos][pesoHeladera][maxPorCategoria[0]][maxPorCategoria[1]][maxPorCategoria[2]][maxPorCategoria[3]];
}


int main(){
    
    // TODO
    return 0;
}
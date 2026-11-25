#include <string>
#include <iostream>
#include <limits>
#include "funciones/auxEj10.cpp"

using namespace std;

int main()
{
    int t;
    std::cin >> t;

    for (int a = 0; a < t; a++)
    {
        std::cin >> cantSumandos;
        for (int k = 0; k <= cantSumandos; k++)
        {
            std::cin >> palabras[k]; // los K sumandos y, al final, el resultado
        }

        resolverAcertijo();

        if (!haySolucion)
        {
            std::cout << "imposible" << std::endl;
        }
        else
        {
            for (int k = 1; k <= cantSumandos; k++)
            {
                if (k > 1) std::cout << " + ";
                std::cout << mejor[k];
            }
            std::cout << " = " << mejor[0] << std::endl;
        }
    }

    return 0;
}
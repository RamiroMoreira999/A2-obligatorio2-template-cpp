#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./funciones/auxEj9.cpp"



int main(){

    int k;
    std:: cin>> k;
    int* tiros = new int[k];
    int* likes = new int[k];

    for (int i=0; i<k; i++){
        std::cin >> tiros[i];
    }

    for (int i=0; i<k; i++){
        std::cin >> likes[i];
    }

    bool bailo =false;
    int numRonda=0;
    int ventaja=0;

    int res = maxLikes(tiros, likes, k, bailo, numRonda, ventaja);

    std:: cout << res;


    // TODO
    return 0;
}
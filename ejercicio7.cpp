#include <cassert>
#include <string>
#include <iostream>
#include <limits>

long long comparo(long long* llegada, long long* aux, int posI, int posF){
    
    if (posI >= posF) return 0;
    
    long long mitad= (posI+posF)/2;

    int izq = comparo (llegada, aux, posI, mitad);
    int der = comparo (llegada, aux, mitad+1, posF);




}


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



    

    // TODO
    return 0;
}
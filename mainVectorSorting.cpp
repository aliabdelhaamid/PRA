#include "vectorSorting.h"

using namespace std;

int main(){
    int n; cin >> n;
   
    vectorSorting v1(n);
    v1.input();
    v1.sort();
    v1.print();

    
    return 0;
}

/*
 Instrucciones

Coinstruye una clase en C++ para implementar una red de ordenación para un vector de longitud arbitraria. La clase tendrá al menos

    dos atributos
        un vector de enteros
        el tamaño del vector, que se indicará en el constructor
    métodos
        constructor y destructor
        input(): para proporcionar el contenido del vector
        sort(): para aplicar la red de ordenación asociada
        print(): para imprimir el contenido del vector.
        swap(): método que implementa un circuito de intercambio individual
*/
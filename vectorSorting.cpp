#include "vectorSorting.h"
using namespace std;

vectorSorting::vectorSorting(int n)
{
    size = n;
    lista.resize(n);
}

vectorSorting::~vectorSorting()
{
}

void vectorSorting::input()
{
    cout << "Introduce números: ";
    for (int i = 0; i < size; i++)
        cin >> lista[i];
    size = lista.size();
}
void vectorSorting::sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (lista[j] > lista[j + 1])
                this->swap(lista[j], lista[j + 1]);
        }
    }
}
    
void vectorSorting::print()
{  
    cout << "Resultado: ";
    for (int i = 0; i < size; i++)
        cout << lista[i] << " ";
    cout << endl;
}
    
void vectorSorting::swap(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

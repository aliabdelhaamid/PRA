#include <iostream>
#include <vector>

using namespace std;
// soles servix pa llistes ordenaes
int binariSergg(int n[], int tam){
    if (n[tam - 1] == 0) return 0;
    else if (n[0]) return tam;
    return binariSergg(n, tam/2) + binariSergg(&n[tam/2], tam - tam/2);
    // en un int* o int[], cuando en una llamada a la recursion haces n + tam o &n[tam] estas moviendo el puntero al indice d
}
int main(){
    int v[] = {0, 0, 0, 0, 1, 1, 1};
    
    int res = binariSergg(v, 7);
    
    cout << "El numero total de unos presents es " << res << endl;

    return 0;
}
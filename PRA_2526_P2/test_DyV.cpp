#include "DyV.h"
using namespace std;

template <typename T>

int main(){

	vector <T> v1;

	cout << "Dame el tamaño del vector: ";
	int n; cin >> n;

	cout << "Dame números/palabras para guardarlas en el vector v:";
	for(int i = 0; i < n; i++) cin >> v1[i]; 
	BusquedaBinaria(2, &v, 0, v.size());


    vector <T> v2;

    cout << "Dame el tamaño del vector: ";
    int m; cin >> m;

    cout << "Dame números para guardarlas en el vector v2:";
    for(int i = 0; i < n; i++) cin >> v2[i];
	QuickSort(&v, 0, v.size());

	return 0;
}

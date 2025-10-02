#include "DyV.h"
using namespace std;

int main(){

	vector <int> v1;

	cout << "Dame el tamaño del vector: ";
	int n; cin >> n;

	cout << "Dame números/palabras para guardarlas en el vector v1:";
	for(int i = 0; i < n; i++) cin >> v1[i]; 
	int a; cout << "Dame el número a buscar: "; cin >> a;
	BusquedaBinaria(a, v1, 0, n - 1);

        vector <float> v2;

        cout << "Dame el tamaño del vector: ";
        int z; cin >> z;

        cout << "Dame números/palabras para guardarlas en el vector v2:";
        for(int i = 0; i < z; i++) cin >> v2[i];
		BusquedaBinaria(2.0f, v2, 0, z -1);

	vector <int> v3;

	cout << "Dame el tamaño del vector: ";
    	int m; cin >> m;

    	cout << "Dame números para guardarlas en el vector v3:";
    	for(int i = 0; i < m; i++) cin >> v3[i];
	QuickSort(v3, 0, m - 1);

	return 0;
}

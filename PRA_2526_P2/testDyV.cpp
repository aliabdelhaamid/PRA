#include "DyV.h"
using namespace std;

int main(){

	cout << "Dame el tamaño del vector: ";
	int n; cin >> n;
	vector <int> v1(n);

	cout << "Dame números/palabras para guardarlas en el vector v1:";
	for(int i = 0; i < n; i++){cin >> v1[i];}
	int a; cout << "Dame el número a buscar: "; cin >> a;
	cout << "\n";
	int res = BusquedaBinaria(a, v1, 0, n - 1);
	cout << "El numero esta en la posicion: " << res << endl;
	
    cout << "Dame el tamaño del vector: ";
    int z; cin >> z;
	
	vector <float> v2(z);
    cout << "Dame números/palabras para guardarlas en el vector v2:";
    
	for(int i = 0; i < z; i++) {cin >> v2[i];}
	float resF = BusquedaBinaria(2.0f, v2, 0, z - 1);
	cout << "El numero esta en la posicion: " << resF << endl;
	cout << "\n";

	cout << "Dame el tamaño del vector: ";
	int m; cin >> m;
	
	vector <int> v3(m);
	cout << "Dame números para guardarlas en el vector v3:";
	
	for(int i = 0; i < m; i++) {cin >> v3[i];}
	QuickSort(v3, 0, m - 1);

	cout << "\n";
	return 0;
}

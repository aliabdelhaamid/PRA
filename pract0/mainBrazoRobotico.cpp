#include "BrazoRobotico.h"

using namespace std;

int main(){
	double x,y,z;
	
	cout << "Dame coordenadas X,Y,Z: ";
	cin >> x >> y >> z;
	
	BrazoRobotico r1(x,y,z);
	r1.mover(3.2, 2.4, 6.7);
	r1.coger();
	
	if(r1.getIsSujetando()){
		cout << "Esta sujetandose" << endl;
	}
	cout << "El robot ahora esta en " << r1.getX() << " " << r1.getY() << " " << r1.getZ() << " " << endl;

	return 0;
}

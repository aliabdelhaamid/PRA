#include <iostream>
using namespace std;

class BrazoRobotico{
	private:
	double x,y,z;
	bool isSujetando;

	public:
	BrazoRobotico(double x, double y, double z);
	double getX();
	double getY();
	double getZ();
	bool getIsSujetando();

	void coger();
	void soltar();
	void mover(double x, double y, double z);
};

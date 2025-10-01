#include "BrazoRobotico.h"

BrazoRobotico::BrazoRobotico(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
	isSujetando = false;
}
double BrazoRobotico::getX(){
	return x;
}
double BrazoRobotico::getY(){
	return y;
}
double BrazoRobotico::getZ(){
	return z;
}

bool BrazoRobotico::getIsSujetando(){
	return isSujetando;
}

void BrazoRobotico::coger(){
	isSujetando = true;
}

void BrazoRobotico::soltar(){
	isSujetando = false;
}

void BrazoRobotico::mover(double x, double y, double z){
	this -> x += x;
	this -> y += y;
	this -> z += z;
}


/*Nova funcionalitat de les clases que acabe de descubrir*/
#include <iostream>
using namespace std;

class POO
{
private:
    int a, b;
public:
    POO(int a, int b);
    POO operator + (POO c2);
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
};

POO::POO(int a, int b)
{
    this->a = a;
    this->b = b;
}
POO POO::operator+(POO c2) {
    POO nuevaC(this->a + c2.a, this->b + c2.b);
    return nuevaC;
}

int main(){
    POO c1(23, 30);
    POO c2 = c1 + c1;
    cout << c2.getA() << " " << c2.getB() << endl;
    return 0;
}
/* 
    resum: puc gastar els operadors de + - * / << [] = == per a fer operacions amb atributs de les clases i anyadirles a altres clases
    operator soles acepta un parametre
*/

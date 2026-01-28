#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

struct camelCards
{
  string mano;
  int bet;
  string fuerza;
  camelCards *izquierda;
  camelCards *derecha;
};

map <char, int> orden = {
  {'A', 14},
  {'K', 13},
  {'Q', 12},
  {'J', 11},
  {'T', 10},
  {'9', 9},
  {'8', 8},
  {'7', 7},
  {'6', 6},
  {'5', 5},
  {'4', 4},
  {'3', 3},
  {'2', 2}
};

map <string, int> rangoFuerza = {     
  {"Cinco Iguales", 6}, 
  {"Póquer", 5},
  {"Full", 4},
  {"Trio", 3},
  {"Doble Pareja", 2},
  {"Pareja", 1},
  {"Carta Alta", 0}
};

bool isPoquer(string mano){
  map<char, int> frecuencia;
  for (size_t i = 0; i < mano.size(); i++)
  {
    frecuencia[mano[i]]++;
  }
  for (auto i = frecuencia.begin(); i != frecuencia.end(); ++i)
  {
    if (i->second == 4)
    {
      return true;
    }
  }
  return false;
}


string calcularFuerza(string mano){
  set <char> cartasUnicas;
  for (char c : mano) {
    cartasUnicas.insert(c); 
  }

  if (cartasUnicas.size() == 1)
  {
    return "Cinco Iguales";
  }
  else if(cartasUnicas.size() == 2){
    if(isPoquer(mano)){
      return "Póquer";
    }
    else {
      return "Full";
    }
  }
  else if(cartasUnicas.size() == 3){
    // Puede ser Trio (3 iguales) o Doble Pareja (2 iguales + 2 iguales)
    map<char, int> f;
    for(char c : mano) f[c]++;
    
    for(auto const& pair : f) {
        if(pair.second == 3) return "Trio";
    }
    return "Doble Pareja";
  }
  else if(cartasUnicas.size() == 4){
    return "Pareja";
  }
  else if(cartasUnicas.size() == 5){
    return "Carta Alta";
  }
}

void insertar(string mano, int bet, camelCards *&lista){
  if (lista == nullptr){
    lista = new camelCards();
    lista->mano = mano;
    lista->bet = bet;
    lista->fuerza = calcularFuerza(mano);
    lista->izquierda = nullptr;
    lista->derecha = nullptr;
    return;
  }
  else if(rangoFuerza[lista->fuerza] > rangoFuerza[calcularFuerza(mano)]){ // A la derecha
    insertar(mano, bet, lista->derecha);
  }
  else if(rangoFuerza[lista->fuerza] < rangoFuerza[calcularFuerza(mano)]){ // A la izquierda
    insertar(mano, bet, lista->izquierda);
  }/* Si son del mismo rango de fuerza, hay que mirar caracter a caracter */
  else{
    for (size_t i = 0; i < mano.size(); i++)
    {
      if(orden[lista->mano[i]] > orden[mano[i]]){
        insertar(mano, bet, lista->derecha);
        return;
      }
      else if(orden[lista->mano[i]] < orden[mano[i]]){
        insertar(mano, bet, lista->izquierda);
        return;
      }
    }
    
  }
}

void calcularResultado(camelCards *lista, int &ranking, long &total) {
  if (lista == nullptr) {
    return;
  }
  calcularResultado(lista->derecha, ranking, total);
  
  ranking++;
  total += lista->bet * ranking;;
  calcularResultado(lista->izquierda, ranking, total);
}

int main(){

  ifstream fichero("input.txt");

  if (!fichero.is_open()){ 
    throw runtime_error("No se encuentra el fichero\n");
  }

  camelCards *raiz = nullptr;
  string linea;
  
  while(getline(fichero, linea)){
    string mano;
    int bet;
    stringstream ss(linea);
    ss >> mano >> bet;

    insertar(mano, bet, raiz);
  }

  long total = 0;
  int ranking = 0;
  calcularResultado(raiz, ranking, total);
  cout << total << endl;
  return 0;
    
}


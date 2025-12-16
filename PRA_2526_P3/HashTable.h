#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2526_P1/ListLinked.h" 
using namespace std;

template <typename V>
class HashTable: public Dict<V> {

    private:
        // ...
	int n;
	int max;
	ListLinked<TableEntry<V> >* table;
	int h(string key){
		int res = 0;
		for(int i = 0; i < key.length(); i++){	
			res += key[i] - '0';
		}
		return res % max;
	}
	int h2(int hash_val){
		if(hash_val > max){
			return 0;
		}
		return hash_val + 1;
	}
	// table[i] es la cubeta es on hi han nodos amb informacio de clave->valor

    public:
        // ...
	void insert(string key, V value) override{
		int i = h(key);
		int pos = table[i].search(key);
		TableEntry<V> aux = TableEntry<V>(key, value);

		if(pos != -1){ // si la posicio ja esta ocupada
			int j = h2(i);
			int pos_nueva = table[j].search(key);
			if(pos_nueva == -1){ // si no esta ocupada
				table[j].append(aux);		
			}
			
		}
		else{
			table[i].append(aux); // tinc que recorrer tots els nodos de la posició i despres afegir 
		}
		n++;
	}
	V search(string key)override{
		int i = h(key);      
		int pos = table[i].search(key); // en la posicio i se suposa que esta key, si no esta fem un throw
		TableEntry<V> aux;
		if(pos == -1){ // si no sa trobat
			int j = h2(i);
			int pos_nueva = table[j].search(key);
			if(pos_nueva != -1){
				aux = table[j].get(pos_nueva);
			}
		}
		else{
			aux = table[i].get(pos);
		}
		return aux.value;
	}
    V remove(string key)override{
		int i = h(key);
		int pos = table[i].search(key);
        	TableEntry<V> aux;

		if(pos == -1){ // si no sa trobat
                        int j = h2(i);
                        int pos_nueva = table[j].search(key);
                	if(pos_nueva != -1){
                        	aux = table[j].get(pos_nueva);
                        	table[j].remove(pos_nueva);
			}
                 }
                 else{
                        aux = table[i].get(pos);
			table[i].remove(pos);
                 }
            
		n--;
		return aux.value;
		
	}
    int entries() override{
		return n;
	}
	
	HashTable(int size){
		table = new ListLinked<TableEntry<V> >[size];
		n = 0;
		max = size;
	}

	~HashTable(){
		delete[] table;		
	}

	int capacity(){	
		return max;
	}
	
	friend ostream& operator<<(std::ostream &out, HashTable<V> &th){
		
		out << "HashTable [entries: " << th.entries() << ", capacity: " << th.capacity() << "]" << endl;
		out << "==============" << endl << endl;

    	for (int i = 0; i < th.max; i++) { 
			out << "== Cubeta " << i << " ==" << endl << endl;
			out << th.table[i] << endl << endl; // utilitza el operator de TableEntry i ListLinked
    	}

		out << "==============" << endl;

    	return out;
	}
	
	V operator[](string key){
		return search(key);
	}
};

#endif

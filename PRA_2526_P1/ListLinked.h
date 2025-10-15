#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
 	Node<T>* first;
	
        int n;
	// tenim data y next
    public:

        ListLinked(){
		first = nullptr;
		n = 0;
	}
	~ListLinked(){
		Node<T>* aux = first;
		Node<T>* nextNode;
		
		while(aux != nullptr){ 
			nextNode = aux->next;
			delete aux;
			aux = nextNode;
		}
	}

	T operator[](int pos){
		return get(pos);
	}

	friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
		Node<T>* aux = list.first;
    out << "List => [";
    
    if (aux != nullptr) {
	out << endl << "    "<< aux->data << endl;
	aux = aux->next;
    }

    while (aux != nullptr) {
        out << "   " << aux->data << endl;
	aux = aux->next;
    }
    
    out << "]";
    return out;
	
}

void insert(int pos, T e) override{
	if(pos < 0 || pos > n) throw std::out_of_range("Posición fuera del rango de la array");
	if(pos == 0){
		Node<T>* aux = new Node<T>(e,first); 
		first = aux;
		n++;
	}
	else{
		Node<T>* prev = nullptr;
		Node<T>* aux = first;
		int i = 0;
		while(aux != nullptr && i < pos){
			prev = aux;
			aux = aux -> next;
			i++;
		}
		if(i == pos){
			prev->next = new Node<T>(e,aux); 
			n++;
		}	
	}
}

void append(T e) override{
	insert(n,e);
}
void prepend(T e) override {
	insert(0,e);
}
T get(int pos) override{
	if(pos < 0 || pos >= n) throw std::out_of_range("Posición fuera del rango de la array");
	Node<T>* aux = first;
	for(int i= 0; i < pos; i++) aux = aux->next;
	return aux->data;
        }
        int search(T e) override {
                Node<T>* aux = first;
		int i = 0;
		while(aux != nullptr && aux-> data != e){
			aux = aux-> next;
			i++;
		}
		if(aux != nullptr) return i;
		else return -1;
        }

        bool empty() override {
                if (n == 0) return true;
                else return false;
        }
        int size() override{
                return n;
        }

	T remove(int pos) override
	{
		if(pos < 0 || pos > n) throw out_of_range("No esta en el array");

		Node<T>* prev = nullptr;
    		Node<T>* aux = first;
		int i = 0;
    		while (aux != nullptr && i < pos) {
        		prev = aux;
        		aux = aux->next;
			i++;
   		}
		T res = 0;
    		if (aux != nullptr) {
        		if (aux == first) {
            			first = aux->next;
        		}
			else {
            			prev->next = aux->next;
        		}
			res = aux->data;
        		delete aux;
        		n--;
    		}
		return res;
	}   












};

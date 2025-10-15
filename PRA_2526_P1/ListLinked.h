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
		Node<T>* aux;
		for(int i = 0; i < n; i++){ 
			aux = first->next;
			delete first->data;
			first->data = aux;
		}
	}

	T operator[](int pos){
		get(pos);
	}

	friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
	out << list.first->data << endl;
	return out;
}

void insert(int pos, T e) override{
	if(pos < 0 || pos > n) throw std::out_of_range("Posición fuera del rango de la array");
	if(pos == 0){
		Node<T>* aux = new Node<T>(e,first); 
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
	insert(n + 1,e);
}
void prepend(T e) override {
	insert(0,e);
}
T get(int pos) override{
	if(pos < 0 || pos >= n) throw std::out_of_range("Posición fuera del rango de la array");
	Node<T>* aux = first;
	int i = 0;
	while(i < pos){
		i++;
		aux = aux->next;
	}
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













};

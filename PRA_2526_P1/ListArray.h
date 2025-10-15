#include <ostream>
#include "List.h"

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	void resize(int new_size)
	{
		T* pepe = new T[new_size];
		for(int i = 0; i < n; i++) pepe[i] = arr[i];
		
		delete[] arr;
		arr = pepe;
		max = new_size;
	}
	static const int MINSIZE = 2;
	
    public:
        // miembros públicos, incluidos los heredados de List<T>
	void insert(int pos, T e) override{
		if(pos < 0 || pos > n) throw std::out_of_range("Posición fuera del rango de la array");
		if(pos== 0) arr[0] = e;	
		else {
			for(int i = n - 1; i >= pos; i--) arr[i + 1] = arr[i];
			arr[pos] = e;
		}
		n++;
		resize(n);
	}    	
	void append(T e) override
	{
		insert(n,e);
	}
	void prepend(T e) override 
	{
		insert(0,e);
	}
	T get(int pos) override
	{
		if(pos < 0 || pos >= n) throw std::out_of_range("Posición fuera del rango de la array");
		return arr[pos];
	}
	int search(T e) override
	{
		for(int i = 0; i < n; i++) if(arr[i] == e) return i;
		return -1;
	}
	
	bool empty() override 
	{
		if (n == 0) return true;
		else return false;
	}
	int size() override{
		return n;
	}
	ListArray(){
		
		arr = new T[MINSIZE];	
		n = 0;
		max = MINSIZE;
	}
	~ListArray(){
		delete[] arr;
	}
	T operator[](int pos){
		if(pos < 0 || pos > n) throw std::out_of_range("Posición fuera del rango de la array");
            return arr[pos];
	}
	friend ostream& operator<<(ostream &out, const ListArray<T> &list){
		out << "List => [" << endl;
		for(int i = 0; i < list.n; i ++) out << "   "<< list.arr[i] << endl;
		out << "]";
		return out;
	}
	T remove(int pos) override
	{
		if(pos < 0 || pos >= n) throw std::out_of_range("Posición fuera del rango de la array");
		T res = arr[pos];
		for(int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
		n--;
		return res;
	}
};

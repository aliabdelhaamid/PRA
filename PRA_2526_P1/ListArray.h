#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	void resize(int new_size{
		T* pepe = new pepe[new_size];
		for(int i = 0; i < n; i++) pepe[i] = arr[i];
		delete[] arr;
		arr = pepe;
		max = new_size;
	}
	T* arr;
	int max;
	int n;
	static const int MINSIZE;
    public:
        // miembros públicos, incluidos los heredados de List<T>
	void insert(int pos, T e) override{
		if(pos > n || pos < MINSIZE ) throw std::out_of_range;
		arr[pos] = e;
	}    	
	void append(T e) override{
		arr[n + 1] = e;
	}
	void prepend(T e) override {
	
	}
	T get(int pos) override{
		if(pos > n || pos < MINSIZE ) throw std::out_of_range;
		return arr[pos];
	}
	bool empty() override {
		if (n = 0) return true;
		else return false;
	}
	int size() override{
		return n;
	}
	ListArray(){
		T* arr = new arr[MINSIZE];	
		MINSIZE = 2;
	}
	~ListArray(){
	delete[] arr;
	}
	T operator[](int pos);
	friend std::iostream& operator<<(std::iostream &out, const ListArray<T> &list){
	
	}
};

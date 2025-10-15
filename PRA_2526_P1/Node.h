#include <ostream>

using namespace std;

template <typename T> 
class Node {
    public:
        // miembros públicos
	T data;
	Node<T>* next;
 	Node(T data, Node<T>* next=nullptr){
		this->data = data;
		this->next = next;
	}

	friend ostream& operator<<(ostream &out, const Node<T> &node)
	{
		out << node->data << endl;
		return out;
	}   
};

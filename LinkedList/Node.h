 #ifndef NODE_H
#define NODE_H
#include <stddef.h>
/** define a singly linked list node */
template<class T>
struct Node {
	//data fields
	T data; //stores some data in the node
	Node<T>* next; //stores pointer to the next node in the list

	//constructor
	Node(const T&, Node<T>* = NULL);
};


//constructor
template<class T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next) {}

#endif
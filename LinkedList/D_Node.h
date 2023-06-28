#ifndef D_NODE_H
#define D_NODE_H
#include <stddef.h>

/** A doubly-linked list node */
template<class T>
struct D_Node {
	//data fields
	T data; //stores some data in the node
	D_Node<T>* next; //stores a pointer to the next node in the list
	D_Node<T>* prev; //stores a pointer to the previous node in the list

	//constructor
	D_Node(const T&, D_Node<T>* = NULL, D_Node<T>* = NULL);
};

//constructor
template<class T>
D_Node<T>::D_Node(const T&, D_Node<T>* next, D_Node<T>* prev) :data(data), next(next), prev(prev) {}
#endif
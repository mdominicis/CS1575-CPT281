#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>>
#include <sstream>
#include <string>

using std::ostringstream;
using std::ostream;
using std::string;

template<class T>
struct BTNode
{
	//Data fields
	T data;
	BTNode<T>* left;//stores pointer to left child
	BTNode<T>* right;//stores pointer to right child

	//constructor
	BTNode(const T&, BTNode<T>* = NULL, BTNode<T>* = NULL);

	//destructor
	virtual ~BTNode();//avoid warning messages

	//class member function
	virtual string to_string() const;
};

//constructor
template <class T>
BTNode<T>::BTNode(const T& data , BTNode<T>* left, BTNode<T>* right):data(data),left(left),right(right){  }

//destructor
template <class T>
BTNode<T>::~BTNode(){  }

//to_string function
template <class T>
string BTNode<T>::to_string() const{
	ostringstream oss;
	oss << data;
	return oss.str();
}

//stream insertion operator
template<class T>
ostream& operator <<(ostream& out, const BTNode<T>* node){
	return out << node->to_string();
}


#endif

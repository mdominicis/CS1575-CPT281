#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include <sstream>
#include <string>
#include <stddef.h>
#include <exception>

using std::ostringstream;
using std::string;
template<class T>
class List_Queue
{
public:
	//constructors
	List_Queue();//default constructors
	List_Queue(const List_Queue<T>&);

	//destructor
	~List_Queue();

	//class member functions
	const List_Queue<T>& operator = (const List_Queue<T>&);
	size_t size() const; //returns num of items in queue
	bool empty() const; //returns true if empty, false otherwise
	T& front(); //returns the item at the front of the queue lvalue
	const T& front() const; //returns the item at the front of the queue rvalue
	void push(const T&); //adds an item to the rear end of the queue
	void pop(); //removes item at the front of the queue

	//test purpose only
	string to_string() const; //outputs the queue as a string

private:
	//a singly linked list node
	struct Node
	{
		//data fields
		T data;
		Node* next;
		Node(const T&);
	};

	//data fields of List_Queue
	Node* head;
	Node* tail;
	size_t num_of_items;

	//private class member function
	void clear(); //removes all the items stored in the queue
};

template <class T>
string List_Queue<T>::to_string() const{
	ostringstream oss;
	oss << '[';
	Node* p = head;
	while(p){
		oss << p->data;
		if (p != tail) { oss << ", "; }
		p = p->next;
	}
	oss << ']' << " Size:"<<size();
	return oss.str();
}


template <class T>
const List_Queue<T>& List_Queue<T>::operator=(const List_Queue<T>& rhs){
	if (this != &rhs){
		clear();
		num_of_items = rhs.num_of_items;
		if(num_of_items>0){
			head = tail = new Node(rhs.head->data);
			Node* q = rhs.head->next;
			while(q!=NULL){
				tail->next = new Node(q->data);
				tail = tail->next;
				q = q->next;
			}
		}
	}
	return *this;
}


template <class T>
void List_Queue<T>::pop(){
	if (empty()) { throw std::exception("Attempt to remove item from empty queue."); }
	Node* to_be_deleted = head;
	if (size() == 1) { head = tail = NULL; }
	else { head = head->next; }
	delete to_be_deleted;
	num_of_items--;
}


template <class T>
void List_Queue<T>::push(const T&item){
	if (empty()) { head = tail = new Node(item); }
	else{
		tail->next = new Node(item);
		tail = tail->next;
	}
	num_of_items++;
}


template <class T>
const T& List_Queue<T>::front() const{
	if (empty()) { throw std::exception("Attempt to acces item in empty queue."); }
	return head->data;
}

template <class T>
T& List_Queue<T>::front(){
	if (empty()) { throw std::exception("Attempt to acces item in empty queue."); }
	return head->data;
}


template <class T>
bool List_Queue<T>::empty() const { return !num_of_items; }


template <class T>
size_t List_Queue<T>::size() const { return num_of_items; }


template <class T>
List_Queue<T>::~List_Queue() { clear(); }


template <class T>
List_Queue<T>::List_Queue(const List_Queue<T>& other) :head(NULL), tail(NULL) { *this = other; }


template <class T>
List_Queue<T>::List_Queue():head(NULL),tail(NULL),num_of_items(0){}

template <class T>
void List_Queue<T>::clear(){
	while(head){
		Node* to_be_deleted = head;
		head = head->next;
		delete to_be_deleted;
	}
	tail = NULL;
	num_of_items = 0;
}


template <class T>
List_Queue<T>::Node::Node(const T& theData): data(theData), next(NULL){}

#endif
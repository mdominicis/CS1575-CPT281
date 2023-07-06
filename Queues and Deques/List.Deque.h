#ifndef LIST_DEQUE_H
#define LIST_DEQUE_H

#include <sstream>
#include <string>
#include <stddef.h>
#include <exception>

using std::ostringstream;
using std::string;

template<class T>
class List_Deque {
public:
	//constructors
	List_Deque(); //default constructor
	List_Deque(const List_Deque<T>&);//copy constructor

	//destructor
	~List_Deque();

	//class member functions
	const List_Deque<T>& operator = (const List_Deque<T>&);//deep copy assignment operator
	size_t size() const; //returns num of items in deque
	bool empty() const; //true if empty, false if now
	T& front(); //returns item at front end of deque lvalue
	const T& front() const; //returns item at front end of deque rvalue
	T& back(); //returns item at rear end of deque lvalue
	const T& back() const; //returns item at rear end of deque rvalue
	void push_front(const T&); //Adds an item to the front end of the deque
	void push_back(const T&); //adds an item to the rear end of the deque
	void pop_front(); //removes item at front end of deque
	void pop_back(); //removes item at rear end of deque

	//test purpose only
	string to_string() const; //outputs the queue as a string

private:
	//a doubly linked list node
	struct DNode
	{
		//data fields of DNode
		T data;
		DNode* next;
		DNode* prev;
		//constructor of DNode
		DNode(const T&);
	};

	//data fields of List_Deque
	DNode* head;
	DNode* tail;
	size_t num_of_items;

	//private class member function
	void clear(); //removes all the items stored in the Deque
};

template <class T>
string List_Deque<T>::to_string() const {
	ostringstream oss;
	oss << '[';
	DNode* p = head;
	while (p) {
		oss << p->data;
		if (p != tail) { oss << ", "; }
		p = p->next;
	}
	oss << ']' << " Size:" << size();
	return oss.str();
}

template <class T>
void List_Deque<T>::pop_back(){
	if (empty()) { throw std::exception("Attempt to remove item from empty deque."); }
	DNode* to_be_deleted = tail;
	if (size() == 1) { head = tail = NULL; }
	else{
		tail = tail->prev;
		tail->next = NULL;
	}
	num_of_items--;
	delete to_be_deleted;
}


template <class T>
void List_Deque<T>::pop_front(){
	if (empty()) { throw std::exception("Attempt to remove item from empty deque."); }
	DNode* to_be_deleted = head;
	if (size() == 1) { head = tail = NULL; }
	else{
		head = head->next;
		head->prev = NULL;
	}
	num_of_items--;
	delete to_be_deleted;
}


template <class T>
void List_Deque<T>::push_back(const T& item){
	if (empty()) { head = tail = new DNode(item); }
	else{
		tail->next = new DNode(item);
		tail->next->prev = tail;
		tail = tail->next;
	}
	num_of_items++;
}


template <class T>
void List_Deque<T>::push_front(const T& item){
	if (empty()) { head = tail = new DNode(item); }
	else{
		head->prev = new DNode(item);
		head->prev->next = head;
		head = head->prev;
	}
	num_of_items++;
}

template <class T>
const T& List_Deque<T>::back() const{
	if (empty()) { throw std::exception("Attempt to access item in empty deque."); }
	return tail->data;
}

template <class T>
T& List_Deque<T>::back(){
	if (empty()) { throw std::exception("Attempt to access item in empty deque."); }
	return tail->data;
}


template <class T>
const T& List_Deque<T>::front() const{
	if (empty()) { throw std::exception("Attempt to access item in empty deque."); }
	return head->data;
}

template <class T>
T& List_Deque<T>::front(){
	if (empty()) { throw std::exception("Attempt to access item in empty deque."); }
	return head->data;
}


template <class T>
bool List_Deque<T>::empty() const { return !num_of_items; }

template <class T>
size_t List_Deque<T>::size() const { return num_of_items; }


template <class T>
const List_Deque<T>& List_Deque<T>::operator=(const List_Deque<T>&rhs){
	if(this!=&rhs){
		clear();
		num_of_items = rhs.num_of_items;
		if(num_of_items){
			head = tail = new DNode(rhs.head->data);
			DNode* q = rhs.head->next;
			while(q){
				tail->next = new DNode(q->data);
				tail->next->prev = tail;
				tail = tail->next;
				q = q->next;
			}
		}
	}
	return *this;
}


template <class T>
List_Deque<T>::~List_Deque() { clear(); }


template <class T>
List_Deque<T>::List_Deque(const List_Deque<T>& other) : head(NULL), tail(NULL) { *this = other; }


template <class T>
List_Deque<T>::List_Deque():head(NULL),tail(NULL),num_of_items(0){}


template <class T>
void List_Deque<T>::clear(){
	while(head!=NULL){
		DNode* to_be_deleted = head;
		head = head->next;
		delete to_be_deleted;
	}
	tail = NULL;
	num_of_items = 0;
}


template <class T>
List_Deque<T>::DNode::DNode(const T& theData) :data(theData),next(NULL),prev(NULL) {}


#endif
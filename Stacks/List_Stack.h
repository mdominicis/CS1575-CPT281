#ifndef LIST_STACK_H
#define LIST_STACK_H
#include <stddef.h>
#include <exception>
template<class T>
class List_Stack
{
public:
	//constructors
	//constructors
	List_Stack();//default constructor
	List_Stack(const List_Stack<T>&);//copy constructor

	//Destructor
	virtual ~List_Stack();

	//class member functions
	const List_Stack<T>& operator = (const List_Stack<T>&);
	size_t size() const;
	bool empty() const;
	T& top(); //lvalue
	const T& top() const; //rvalue
	void push(const T&);
	void pop();
protected:
	struct Node
	{
		//Data fields
		T data;
		Node* next; //singly linked list
		//constructor
		Node(const T&);
	};

	//data fields
	Node* head;
	size_t num_of_items;

	//class member function
	void clear();
};

template <class T>
void List_Stack<T>::pop(){
	if (empty()) { throw std::exception("Attempt to remove item from empty stack."); }
	Node* to_be_deleted = head;
	head = head->next;
	delete to_be_deleted;
	num_of_items--;
}


template <class T>
void List_Stack<T>::push(const T& item){
	Node* newTop = new Node(item);
	newTop->next = head;
	head = newTop;
	num_of_items++;
}


template <class T>
const T& List_Stack<T>::top() const{
	if (empty()) { throw std::exception("Attempt to access item in empty stack;"); }
	return head->data;
}

template <class T>
T& List_Stack<T>::top(){
	if(empty()){ throw std::exception("Attempt to access item in empty stack;"); }
	return head->data;
}


template <class T>
bool List_Stack<T>::empty() const { return !num_of_items; }


template <class T>
size_t List_Stack<T>::size() const{ return num_of_items; }


template <class T>
const List_Stack<T>& List_Stack<T>::operator=(const List_Stack<T>&rhs){
	if(this!=&rhs){
		clear();
		num_of_items = rhs.num_of_items;
		if(num_of_items){
			head = new Node(rhs.head->data);
			Node* p = head;
			Node q = rhs.head->next;
			while(q){
				p->next = new Node(q.data);
				p = p->next;
				q = q->next;
			}
		}
	}
	return *this;
}


template <class T>
List_Stack<T>::~List_Stack() { clear(); }

template <class T>
void List_Stack<T>::clear(){
	while(head){
		Node* p = head;
		head = head->next;
		delete p;
	}
	num_of_items = 0;
}


template <class T>
List_Stack<T>::List_Stack(const List_Stack<T>& other){
	head = NULL;
	*this = other;
}


template <class T>
List_Stack<T>::List_Stack():head(NULL), num_of_items(0){}

template <class T>
List_Stack<T>::Node::Node(const T& theData):data(theData),next(NULL){}
#endif
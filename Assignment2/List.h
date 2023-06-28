#ifndef LIST_H
#define LIST_H
#include <iostream>
using std::ostream;
using std::exception;
/** A doubly-linked list without iterators*/
template<class T>
class List {
public:
	//constructors
	List(); //default constructor
	List(const List<T>&);//copy constructor
	//destructor
	virtual ~List();

	//operator
	const List<T>& operator=(const List<T>&); //deep copy assignment operator
	template<class E>
	friend ostream& operator << (ostream&, const List<E>&); //stream insertion operator

	// Class-member functions
	size_t size() const;  // Returns the number of elements in the list.
	bool empty() const;  // Tests whether the list is empty.
	T& front();  // Returns a reference (lvalue) to the first element in the list.
	const T& front() const;  // Returns a const reference (rvalue) to the first element in the list.
	T& back();  // Returns a reference (lvalue) to the last element in the list.
	const T& back() const;  // Returns a const reference (rvalue) to the last element in the list.
	void push_front(const T&);  // Inserts an element to the front end of the list.
	void push_back(const T&);  // Inserts an element to the rear end of the list.
	void pop_front();  // Deletes an element from the front end of the list.
	void pop_back();  // Deletes an element from the rear end of the list.
	void clear();  // Deletes all the nodes.

	class iterator; //{iterator} is an internal class in {List}

	iterator begin() const; //generates an iterator at the beginning of the list
	iterator end() const;
	iterator insert(iterator&, const T&); //inserts a value at the position represented by the iterator
	iterator erase(iterator&); //removes the value at the position represented by an iterator
	iterator find(const T&); //returns an iterator positioned at the first occurence of a value
private:
	/**a doubly linked list node*/
	struct D_Node {
		//data fields
		T data; //stores some data in the node
		D_Node* next; //stores a pointer to the next node in the list
		D_Node* prev; //stores a pointer to the previous node in the list

		//constructor
		D_Node(const T&, D_Node* = NULL, D_Node* = NULL);

	};
	//data fields
	D_Node* head; //stores a pointer to the first node in the list
	D_Node* tail; //stores a pointer to the last node in the list
	size_t num_of_items; //stores number of nodes in the list
};

//stream insertion operator
template<class T>
ostream& operator << (ostream& out, const List<T>& li) {
	typename List<T>::D_Node* current = li.head;
	while (current) {
		out << current->data;
		if (current->next) { out << " -> "; }
		current = current->next;
	}
	return out;
}


/** Deletes all the nodes.*/
template<class T>
void List<T>::clear() {
	while (!empty()) {
		pop_front();
	}
}//time complexity: O(n)

/**Deletes an element from the rear end of the list.
	@throws exception: list is empty
*/
template<class T>
void List<T>::pop_back() {
	if (empty()) { throw exception("Accessing empty list"); }
	D_Node* to_be_deleted = tail;
	if (num_of_items-- == 1) { head = tail = NULL; }
	else {
		tail = tail->prev;
		tail->next = NULL;
	}
	delete to_be_deleted;
}//time complexity O(1)

/**Deletes an element from the front end of the list.
	@throws exception: list is empty
*/
template<class T>
void List<T>::pop_front() {
	if (empty()) { throw exception("Accessing empty list"); }
	D_Node* to_be_deleted = head;
	if (num_of_items-- == 1) { head = tail = NULL; }
	else {
		head = head->next;
		head->prev = NULL;
	}
	delete to_be_deleted;
}//time complexity O(1)


/**Inserts an element to the rear end of the list.
	@param value: the element to insert to the list
*/
template <class T>
void List<T>::push_back(const T& value) {
	if (num_of_items++ == 0) { head = tail = new D_Node(value); }
	else {
		tail->next = new D_Node(value);
		tail->next->prev = tail;
		tail = tail->next;
	}
}//time complexity: O(1)

/**Inserts an element to the front end of the list.
	@param value: the element to insert to the list
*/
template <class T>
void List<T>::push_front(const T& value) {
	if (num_of_items++ == 0) { head = tail = new D_Node(value); }
	else {
		head->prev = new D_Node(value);
		head->prev->next = head;
		head = head->prev;
	}
}//time complexity: O(1)

/**Returns a reference (rvalue) to the last element in the list.
	@return: Returns a reference (rvalue) to the last element in the list.
	@throws exception: list is empty
*/
template <class T>
const T& List<T>::back() const {
	if (empty()) {
		throw exception("Accessing empty list.");
	}
	return tail->data;
	//time complexity: O(1)
}


/**Returns a reference (lvalue) to the last element in the list.
	@return: Returns a reference (lvalue) to the last element in the list.
	@throws exception: list is empty
*/
template <class T>
T& List<T>::back() {
	if (empty()) {
		throw exception("Accessing empty list.");
	}
	return tail->data;
	//time complexity: O(1)
}

/**Returns a reference (rvalue) to the first element in the list.
	@return: Returns a reference (rvalue) to the first element in the list.
	@throws exception: list is empty
*/
template <class T>
const T& List<T>::front() const {
	if (empty()) {
		throw exception("Accessing empty list.");
	}
	return head->data;
	//time complexity: O(1)
}

/**Returns a reference (lvalue) to the first element in the list.
	@return: Returns a reference (lvalue) to the first element in the list.
	@throws exception: list is empty
*/
template <class T>
T& List<T>::front() {
	if (empty()) {
		throw exception("Accessing empty list.");
	}
	return head->data;
	//time complexity: O(1)
}

/**tests whether the list is empty
	@return: {true} if the list is empty; {faslse} otherwise
*/
template <class T>
bool List<T>::empty() const { return !size(); }

/** returns the number of elements in the list
	@return: number of elements in the list
*/
template<class T>
size_t List<T>::size() const { return num_of_items; }//time complexity O(1)

//deep copy assignment operator
template<class T>
const List<T>& List<T>::operator=(const List<T>& rhs) {
	//step 1: avoid self assignment
	if (this != &rhs) {
		//Step 2: delete dynamic memory
		clear();
		//step 3: copy static data
		num_of_items = rhs.num_of_items;
		//step 4: copy dynamic data
		if (num_of_items) {
			head = tail = new D_Node(rhs.head->data);
			D_Node* q = rhs.head->next;
			while (q) {
				tail->next = new D_Node(q->data);
				tail->next->prev = tail;
				tail = tail->next;
				q = q->next;
			}
		}
	}
	//step 5 return
	return *this;
}

//destructor
template<class T>
List<T>::~List() {
	clear();
}

//copy constructor
template<class T>
List<T>::List(const List<T>& other) {
	head = tail = NULL;
	*this = other;
}


//default constructor
template<class T>
List<T>::List() :head(NULL), tail(NULL), num_of_items(0) {}

//constructor of D_Node struct
template<class T>
List<T>::D_Node::D_Node(const T& data, D_Node* next, D_Node* prev) : data(data), next(next), prev(prev) {}

template<class T>
class List<T>::iterator {
public:
	//constructor
	iterator(const List<T>*, D_Node*, size_t);

	//class member functions
	T& operator * (); //overloading the dereferencing operator ('*')
	T* operator -> (); //overloading the "->" operator
	iterator& operator ++ (); //overloading the prefix "++" operator to move iterator forward
	iterator operator ++ (int); //overloading the postfix "++" operator to move iterator forward
	iterator& operator --(); //overloading the prefix "--" operator to move iterator backward
	iterator operator -- (int); //overloading the postfix -- operator to move the iterator backward
	long long operator - (const iterator&) const; //finds the distance from another iterator
	bool operator == (const iterator&) const; //checking for equality
	bool operator != (const iterator&) const; //checking for inequality
private:
	//data fields
	const List<T>* parent; //a pointer pointing to the parent list
	D_Node* current; //a pointer pointing to the current node
	size_t dist; //distance from the beginning  of the list
	friend class List<T>;//the parent class can access the private section

};

template<class T>
List<T>::iterator::iterator(const List<T>* p, D_Node* cur, size_t d) :parent(p), current(cur), dist(d) {}

template<class T>
T& List<T>::iterator::operator * ()
{
	if (!current) {//Current node is NULL
		throw exception("Attempt to dereference NULL");
	}
	return current->data;
}

template<class T>
T* List<T>::iterator::operator -> () {
	if (!current) { //current node is NULL, iterator is at end of list
		throw exception("Attempt to address NULL");
	}
	return &(current->data);
}

/** advances the iterator
	@return: an iterator positioned right after the current iterator
	@throws exception: the current iterator is already at the end of the  list
 */
template<class T>
typename List<T>::iterator& List<T>::iterator::operator ++() {
	if (!current) { //current node is NULL, iterator is at end of list
		throw exception("Attempt to move iterator after end");
	}
	current = current->next;
	dist++;
	return *this;
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator ++(int) {
	iterator return_val = *this;
	++(*this);
	return return_val;
}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator --() {
	if (current == parent->head) {//iterator is already at the beginning of the list
		throw exception("Attempt to move iterator before beginning");
	}
	if (!current) { //iterator is at end of list
		current = parent->tail;
	}
	else {
		current = current->prev;
	}
	dist--;
	return *this;
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator -- (int) {
	iterator return_val = *this;
	--(*this);
	return return_val;
}

template<class T>
long long List<T>::iterator::operator - (const List<T>::iterator& other) const {
	return this->dist - other.dist;
}

template<class T>
bool List<T>::iterator::operator == (const List<T>::iterator& other) const {
	return !(*this - other); //if two iterators have distance 0 then they are equal
}

template<class T>
bool List<T>::iterator::operator != (const List<T>::iterator& other) const {
	return *this - other;
}

template <class T>
typename List<T>::iterator List<T>::begin() const {
	return iterator(this, head, 0);
}

template <class T>
typename List<T>::iterator List<T>::end() const {
	return iterator(this, NULL, size());
}

/**Inserts a value to the left of the iterator
	@returns: an iterator pointing to the newly inserted value
 */
template <class T>
typename List<T>::iterator List<T>::insert(iterator& pos, const T& value) {
	//if the new node will be the head of the list..
	if (pos == begin()) {
		push_front(value);
		return pos = begin();
	}
	//if the new node will be the tail of the list...
	if (pos == end()) {
		push_back(value);
		return pos = --end();
	}
	//inserts a new node in the middle of the list
	D_Node* new_node = new D_Node(value);
	new_node->next = pos.current;
	new_node->prev = pos.current->prev;
	new_node->next->prev = new_node;
	new_node->prev->next = new_node;
	num_of_items++;
	pos.current = pos.current->prev;
	return pos;
}

/**removes a value at the position represented by an iterator
	@returns: an iterator just past the node removed
*/
template<class T>
typename List<T>::iterator List<T>::erase(iterator& pos) {
	if (pos == end()) {//{pos} points to NULL
		throw exception("Attempt to remove NULL reference");
	}
	//if node being removed is head of the list
	if (pos == begin()) {
		pop_front();
		return pos = begin();
	}
	//if node being removed is tail of list
	if (pos == --end()) {
		pop_back();
		return pos = end();
	}
	//removes an item from the middle of the list
	D_Node* to_be_deleted = pos.current;
	pos.current = pos.current->next;
	to_be_deleted->next->prev = to_be_deleted->prev;
	to_be_deleted->prev->next = to_be_deleted->next;
	delete to_be_deleted;
	num_of_items--;
	return pos;
}

/**finds and returns an iterator positioned at the first occurrence of a value
 if the value does not appear in the list, then return an iterator positioned at the end of the list
 */
template<class T>
typename List<T>::iterator List<T>::find(const T& value) {
	iterator it = begin();
	while (it != end()) {
		if (*it == value) {
			break;
		}
		it++;
	}
	return it;
}














//Problem 6
//template<class T>
//class List<T>::Const_Iterator {
//public:
//	// Constructor
//	Const_Iterator(const List<T>*, const D_Node*, size_t);
//
//	// Class-member functions
//	const T& operator * () const;
//	const T* operator -> () const;
//	Const_Iterator& operator ++ ();
//	Const_Iterator operator ++ (int);
//	Const_Iterator& operator -- ();
//	Const_Iterator operator -- (int);
//	int operator - (const Const_Iterator&) const;
//	bool operator == (const Const_Iterator&) const;
//	bool operator != (const Const_Iterator&) const;
//
//private:
//	// Data fields
//	const List<T>* parent;
//	const D_Node* current;
//	size_t offset;
//
//	friend class List<T>;
//};



#endif
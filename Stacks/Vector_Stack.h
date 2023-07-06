#ifndef VECTOR_STACK_H
#define VECTOR_STACK_H

#include <exception>
#include <stddef.h>

template<class T>
class Vector_Stack
{
public:
	//constructors
	Vector_Stack();//default constructor
	Vector_Stack(const Vector_Stack<T>&);//copy constructor

	//Destructor
	~Vector_Stack();

	//class member functions
	const Vector_Stack<T>& operator = (const Vector_Stack<T>&);
	size_t size() const;
	bool empty() const;
	T& top();//lvalue
	const T& top() const;//rvalue
	void push(const T&);
	void pop();
private:
	//data fields
	T* arr;
	size_t capacity, num_of_items;
	static const size_t DEFAULT_CAPACITY;

	//class member function
	void reserve();
};

template <class T>
void Vector_Stack<T>::pop(){
	if (empty()) { throw std::exception("Attempt to remove item from empty stack"); }
	num_of_items--;
}

template <class T>
void Vector_Stack<T>::push(const T& item){
	if (size() == capacity) { reserve(); }
	arr[num_of_items++] = item;
}

template <class T>
void Vector_Stack<T>::reserve(){
	capacity *= 2;
	T* newArr = new T[capacity];
	for (size_t i = 0; i < num_of_items; i++) { newArr[i] = arr[i]; }
	delete[] arr;
	arr = newArr;
}

template <class T>
const T& Vector_Stack<T>::top() const{
	if (empty()) { throw std::exception("Attempt to access item in empty stack."); }
	return arr[size() - 1];
}

template <class T>
T& Vector_Stack<T>::top(){
	if (empty()) { throw std::exception("Attempt to access item in empty stack."); }
	return arr[size() - 1];
}

template <class T>
bool Vector_Stack<T>::empty() const { return !num_of_items; }

template <class T>
size_t Vector_Stack<T>::size() const { return num_of_items; }

template <class T>
const Vector_Stack<T>& Vector_Stack<T>::operator=(const Vector_Stack<T>& rhs){
	if(this!=&rhs){
		if(arr){
			delete[] arr;
			arr = NULL;
		}
		capacity = rhs.capacity;
		num_of_items = rhs.num_of_items;
		if(capacity){
			arr = new T[capacity];
			for (size_t i = 0; i < num_of_items; i++) { arr[i] = rhs.arr[i]; }
			return *this;
		}
	}
}

template <class T>
Vector_Stack<T>::~Vector_Stack(){
	if (arr) { delete[] arr; }
}


template <class T>
Vector_Stack<T>::Vector_Stack(const Vector_Stack<T>& other){
	arr = NULL;
	*this = other;
}

template <class T>
Vector_Stack<T>::Vector_Stack(){
	capacity = DEFAULT_CAPACITY;
	num_of_items = 0;
	arr = new T[capacity];
}

template<class T>
const size_t Vector_Stack<T>::DEFAULT_CAPACITY = 10;
#endif
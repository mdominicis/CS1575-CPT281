#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
#include <string>

using std::max;
using std::exception;
using std::ostream;

/**A vector class without iterators*/
template<class T>
class Vector{
    public:
        //Constructors
        Vector(); //Default constructor
        Vector(const Vector<T>&); //Copy constructor
        Vector(size_t); //Creates vector with intial size
        Vector(size_t, const T&); //Fills each cell in the vector with a specific value

        //Desctructor
        virtual ~Vector();

        //Operators
        const Vector<T>& operator = (const Vector<T>&); //Deep-copy assignment operator
        T& operator [] (size_t); //Subscript operator (left value)
        const T& operator [] (size_t) const; //Subscript operator (right value)

        //Class member functions
        T& at(size_t); // Returns a reference (lvalue) to the element at specified index
        const T& at(size_t) const; //Returns a const reference (rvalue) to the element at specified index
        size_t size() const; //Returns the numberof elements stored in the vector
        bool empty() const; //Tests whether the vector is empty
        T& front(); //Returns a reference (lvalue) to the first element in the vector
        const T& front() const; //Returns a reference (rvalue) to the first element in the vector
        T& back(); //Returns a reference (lvalue) to the last element in the vector
        const T& back() const; //Returns a reference (rvalue) to the last element in the vector
        void push_back(const T&); //Inserts an element to the rear end of the vector
        void pop_back(); //Deletes an element from the rear end of the vector
    private:
        //Data Fields
        static const size_t DEFAULT_CAPACITY; //Capacity of the vector if not specifed
        T* data; //Dynamic array storing the elements in the vector
        size_t capacity; //Length of the dynamic array
        size_t num_of_items; //Number of elements stored in the vector

        //Class member functions
        void resize(); //Doubles the capacity of the vector without changing current data
};

//stream insertion operator
template<class T>
ostream& operator <<(ostream& out,const Vector<T>& vec){
    out<<'[';
    for(size_t i=0;i<vec.size();i++){
        out<<vec.at(i);
        if(i!=vec.size()-1){
            out<<", ";
        }
    }
    out<<']';
    return out;
    //Time complexity O(n)
}

/** Deletes an element from the rear end of the vector*/
template<class T>
void Vector<T>::pop_back(){
    if(empty()){
        throw exception();
    }
    num_of_items--;
    //Time complexity O(1)
}

/** Inserts an element to the rear end of the vector
    @param value: new element to insert to the vector
*/
template<class T>
void Vector<T>::push_back(const T& value){
    if(size()==capacity){
        resize();
    }
    data[num_of_items++]=value;
    //Time complexity O(1)
}

template<class T>
void Vector<T>::resize(){
    capacity*=2;
    T* data2=new T[capacity];
    for(size_t i=0;i<size();i++){
        data2[i]=data[i];
    }
    delete data;
    data=data2;
    //Time complexity: O(n)
}

/** Returns a reference (rvalue) to the last element in the vector
    @return: a reference (rvalue) to the last element in the vector
*/
template<class T>
const T& Vector<T>::back() const{
    if (empty()){
        throw exception();
    }
    return at(size()-1);
    //Time complexity: O(1)
}

/** Returns a reference (lvalue) to the last element in the vector
    @return: a reference (lvalue) to the last element in the vector
*/
template<class T>
T& Vector<T>::back(){
    if (empty()){
        throw exception();
    }
    return at(size()-1);
    //Time complexity: O(1)
}

/** Returns a reference (rvalue) to the first element in the vector
    @return: a reference (rvalue) to the first element in the vector
*/
template<class T>
const T& Vector<T>::front() const{
    if (empty()){
        throw exception();
    }
    return at(0);
    //Time complexity: O(1)
}

/** Returns a reference (lvalue) to the first element in the vector
    @return: a reference (lvalue) to the first element in the vector
*/
template<class T>
T& Vector<T>::front(){
    if (empty()){
        throw exception();
    }
    return at(0);
    //Time complexity: O(1)
}

/** Tests whether the vector is empty
    @return: {true} if the vecotr is empty; {false} otherwise
*/
template<class T>
bool Vector<T>::empty() const{
    return !size();
    //Time complexity: O(1)
}

/** Returns the number of elements stored in the vector
    @return: number of elements stored in the vector
*/
template<class T>
size_t Vector<T>::size() const{
    return num_of_items;
    //Time complexity: O(1)
}

/** Returns a const reference (rvalue) to the element at specified index
    @param index: index of the element to access
    @return: a const reference (rvalue) to the element at specified index
*/
template<class T>
const T& Vector<T>::at(size_t index) const{
    if(index>=size()){
        throw exception();
    }
    return data[index];
    //Time complexity: O(1)
}

/** Returns a reference (lvalue) to the element at specified index
    @param index: index of the element to access
    @return: a reference (lvalue) to the element at specified index
*/
template<class T>
T& Vector<T>::at(size_t index){
    if(index>=size()){
        throw exception();;
    }
    return data[index];
    //Time complexity: O(1)
}

//Subscript operator (right value)
template <class T>
const T& Vector<T>::operator [] (size_t index) const{
    return data[index]; //time complexity O(1)
}

//Subscript operator (left value)
template <class T>
T& Vector<T>::operator [] (size_t index){
    return data[index]; //time complexity O(1)
}
//Constructor with initial size and initial filling values
template<class T>
Vector<T>::Vector(size_t initial_size, const T& filling_value):capacity(max(DEFAULT_CAPACITY,initial_size)), num_of_items(initial_size){
    data = new T[capacity];
    for(size_t i=0;i<num_of_items;i++){
        data[i]=filling_value;
    }
}

//Initial size constructor
template <class T>
Vector<T>::Vector(size_t initial_size):capacity(max(DEFAULT_CAPACITY,initial_size)), num_of_items(initial_size){
    data = new T[capacity];
}

//Destructor
template<class T>
Vector<T>::~Vector(){
    if(data){
        delete[] data;
    }
}

//Copy constructor
template<class T>
Vector<T>::Vector(const Vector<T>& other){
    data=NULL;
    *this=other;
}

//Deep-copy assignment operator
template<class T>
const Vector<T>& Vector<T>::operator = (const Vector<T>& rhs){
    //Step 1: Avoid self-assignment
    if(this!=&rhs){
        //Step 2: Delete dynamic data
        if(data){
            delete[] data;
            data=NULL;
        }
        //Step 3: Copy static data
        capacity=rhs.capacity;
        num_of_items=rhs.num_of_items;
        //Step 4: Copy dynamic data
        if(capacity){
            data=new T[capacity];
            for(size_t i=0;i<num_of_items;i++){
                data[i]=rhs.data[i];
            }
        }
    }
    //Step 5: Return
    return *this;
}

//Default constructor
template <class T>
Vector<T>::Vector():capacity(DEFAULT_CAPACITY), num_of_items(0){
    data  = new T[capacity];
}

//Sets the default capacity.
template<class T>
const size_t Vector<T>::DEFAULT_CAPACITY=10;
#endif
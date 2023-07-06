#ifndef TOP_TWO_STACK_H
#define TOP_TWO_STACK_H
#include "List_Stack.h"
/** A stack in which the top two elements are accessible */
template<class T>
class Top_Two_Stack : public List_Stack<T> {
public:
    // Class-member functions

    /** Returns the element next to the top element of the stack (lvalue).
        @return: element next to the top element
        @throws exception: stack contains only 0 or 1 element.
    */
    T& next_to_top();

    /** Returns the element next to the top element of the stack (rvalue).
        @return: element next to the top element
        @throws exception: stack contains only 0 or 1 element.
    */
    const T& next_to_top() const;

    /** Removes the element next to the top element of the stack.
        @throws exception: stack contains only 0 or 1 element.
    */
    void pop_next_to_top();
};

template <class T>
void Top_Two_Stack<T>::pop_next_to_top(){
    if (empty()||!top_node->next) { throw std::exception("Attempt to remove item from empty stack."); }
    Node* to_be_deleted = top_node->next;
    top_node->next = top_node->next->next;
    delete to_be_deleted;
    num_of_items--;
}

template <class T>
const T& Top_Two_Stack<T>::next_to_top() const{
    if (empty()||!top_node->next) { throw std::exception("Attempt to access item in empty stack;"); }
    return top_node->next->data;
}

template <class T>
T& Top_Two_Stack<T>::next_to_top(){
    if (empty()||!top_node->next) { throw std::exception("Attempt to access item in empty stack;"); }
    return top_node->next->data;
}

#endif
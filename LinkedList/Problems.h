#ifndef PROBLEMS_H
#define PROBLEMS_H

#include "Node.h"
/** Tests whether a singly-linked list is circular
	@param node: a pointer to a node in the list
	@return: {true} if the list is circular; {false} if the list is linear
*/
template <class T>
bool is_circular(Node<T>* node) {
	Node<T>* current = node;
	while (current) {
		current = current->next;
		if (current == node) {
			return true;
		}
	}
	return false;
	//time complexity: O(n) 
}


/** Returns the element stored in the middle node of a singly-linked list.
	@param head: a pointer to the head of the list
	@return: the element in the middle node of the list
*/
template <class T>
T middle_value(Node<T>* head) {
	//count num of items in linked list
	unsigned int count = 0;
	Node<T>* current = head;
	while (current) {
		count++;
		current = current->next;
	}
	//locate middle node
	current = head;
	for (unsigned int i = 0; i < count / 2; i++) {
		current = current->next;
	}
	return current->data;
	//time complexity: O(n) two passes
}


/** Returns the element stored in the middle node of a singly-linked list in one pass.
	@param head: a pointer to the head of the list
	@return: the element stored in the middle node of the list
*/
template <class T>
T middle_value_one_pass(Node<T>* head) {
	Node<T>* fast = head;//fast will advance in every iteration
	Node<T>* slow = head;//slow will advance in every even iteration
	bool is_even = false;
	while (fast) {
		fast = fast->next;
		if (is_even) {
			slow = slow->next;
		}
		is_even = !is_even;
	}
	return slow->data;
	//Time complexity: O(n)
}
#endif
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "BTNode.h"
#include <iostream>
#include <algorithm>
using std::max;
/** returns the height of a binary tree
 * \brief 
 * \tparam T 
 * \param root: a pointer to the root node of the binary tree
 * \return height of the binary tree
 */
template<class T>
unsigned int height(const BTNode<T>* root){
	//base case
	if (!root) { return 0; }
	//recurrence relation
	return max(height(root->left), height(root->right))+1;
}//time complexity: O(n)


/**tests whether a binary tree is full
 * \brief 
 * \tparam T 
 * \param root a pointer to the root node of a binary tree
 * \return {true} if the binary tree is full; {false} otherwise
 */
template<class T>
bool is_full(const BTNode<T>* root){
	//base case
	if (!root) { return true; } //an empty binary tree is full
	//test whether the root is full (has 0 or 2 non-NULL children)
	if ((bool)root->left + (bool)root->right == 1) { return false; }
	//recurrence relation
	return is_full(root->left) && is_full(root->right);
	//time complexity: O(n)
}

//preorder traversal
template <class T>
void preorder_traversal(const BTNode<T>* root, ostream& out){
	if(root){
		out << root << ' ';
		preorder_traversal(root->left, out);
		preorder_traversal(root->right, out);
	}
}//time complexity: O(n)

//inorder traversal
template<class T>
void inorder_traversal(const BTNode<T>* root, ostream& out){
	if(root){
		out << " ( ";
		inorder_traversal(root->left, out);
		out << ' ' << root << ' ';
		inorder_traversal(root->right, out);
		out << " ) ";
	}
}//time complexity: O(n)

//postorder traversal
template<class T>
void postorder_traversal(const BTNode<T>* root, ostream& out) {
	if (root) {
		postorder_traversal(root->left, out);
		postorder_traversal(root->right, out);
		out << root<< ' ';
	}
}//time complexity: O(n)

#endif
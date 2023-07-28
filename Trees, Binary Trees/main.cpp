#include "BTNode.h"
#include "Algorithms.h"
#include <iostream>

using namespace std;

int main(){
	BTNode<char>* root = new BTNode<char>('/');
	root->left = new BTNode<char>('*');
	root->right = new BTNode<char>('-');
	root->left->left = new BTNode<char>('5');
	root->left->right = new BTNode<char>('3');
	root->right->left = new BTNode<char>('6');
	root->right->right = new BTNode<char>('*');
	root->right->right->left = new BTNode<char>('2');
	root->right->right->right = new BTNode<char>('1');

	cout << "Preorder: ";
	preorder_traversal(root, cout);
	cout << endl;

	cout << "Inorder: ";
	inorder_traversal(root, cout);
	cout << endl;

	cout << "Postorder: ";
	postorder_traversal(root, cout);
	cout << endl;

	system("pause");
	return 0;
}
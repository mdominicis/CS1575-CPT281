#include "Solution.h"
#include <iostream>
using namespace std;




int main() {
    // Tree_Node* root = new Tree_Node(1);
    // root->left = new Tree_Node(2);
    // root->right = new Tree_Node(3);
    // root->left->left = new Tree_Node(4);
    // root->left->right = new Tree_Node(5);
    // root->left->right->right = new Tree_Node(6);
    // root->left->right->right->right = new Tree_Node(7);

    /*Tree_Node* root = new Tree_Node(22);
    root->left = new Tree_Node(20);
    root->left->left = new Tree_Node(12);
    root->right = new Tree_Node(29);
    root->left->right = new Tree_Node(28);*/

    Tree_Node* root = new Tree_Node(0);
    root->left = new Tree_Node(1);
    root->right = new Tree_Node(2);
    root->left->left = new Tree_Node(3);
    root->left->right = new Tree_Node(4);
    root->left->left->left = new Tree_Node(5);
    root->left->left->left->left = new Tree_Node(7);
    root->left->right->right = new Tree_Node(6);
    root->left->right->right->right = new Tree_Node(8);
    Solution x;
    cout << x.num_of_nodes(root) << endl;

    return 0;
}
//int main() {
    /*Tree_Node* root = new Tree_Node(1);
    root->left = new Tree_Node(2);
    root->right = new Tree_Node(3);
    root->left->left = new Tree_Node(4);
    root->left->right = new Tree_Node(5);
    root->left->right->right = new Tree_Node(6);
    printTree(root);
    cout << endl;

    Tree_Node* newNode = deep_copy(root);
    deleteTree(root);
    printTree(newNode);
    cout << endl;

    return 0;*/
    /*Tree_Node* root = new Tree_Node(0);
    root->left = new Tree_Node(1);
    root->right = new Tree_Node(2);
    root->left->left = new Tree_Node(3);
    root->left->right = new Tree_Node(4);
    root->left->left->left = new Tree_Node(5);
    root->left->left->left->left = new Tree_Node(7);
    root->left->right->right = new Tree_Node(6);
    root->left->right->right->right = new Tree_Node(8);
    cout << endl;

    Solution x;
    cout << x.diameter(root) << endl;*/

//}


//Problem 3
//int main() {
//    Tree_Node* root = new Tree_Node(1);
//    root->left = new Tree_Node(2);
//    root->right = new Tree_Node(3);
//    root->left->left = new Tree_Node(4);
//    root->left->right = new Tree_Node(5);
//    root->left->right->right = new Tree_Node(6);
//    Solution x;
//    cout << x.num_of_nodes(root) << endl;
//    return 0;
//}
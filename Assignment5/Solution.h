#ifndef SOLUTION_H
#define SOLUTION_H
#include <algorithm>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
using std::max;
struct Tree_Node {
    int val;
    Tree_Node* left, * right;
    Tree_Node(int val, Tree_Node* left = NULL, Tree_Node* right = NULL) :
        val(val), left(left), right(right) {}
};

//class Solution {
//public:
//    static bool isSorted(const Tree_Node* root,long long int min, long long int max){
//        if(!root){ return true; }
//        if(root->val>min&&root->val<max){
//            return isSorted(root->left,min,root->val) && isSorted(root->right,root->val,max);
//        }
//        else { return false; }
//    }
//    /** Tests whether a binary tree is a binary search tree.
//        @param root: a pointer to the root node of the binary tree
//        @return: {true} if the binary tree is binary search tree;
//                 {false} otherwise
//    */
//    static bool is_bst(const Tree_Node* root) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        long int min = INT_MIN;
//        long int max = INT_MAX;
//        return isSorted(root,min,max);
//    }
//};
//












//Question 5
//class Solution {
//public:
//    /** Calculates and returns the diameter of a binary tree.
//        @param root: a pointer to the root node of the binary tree
//        @return: calculated diameter of the binary tree
//    */
//	 static unsigned int diameter(Tree_Node* root){
//	 	if(!root){
//	 		return 0;
//        }
//	 	const unsigned int diamleft = diameter(root->left);
//	 	const unsigned int diamright = diameter(root->right);
//	 	const unsigned int diamtree = height(root->left) + height(root->right);
//        return max(max(diamleft, diamright), diamtree);
//    }
//private:
//     static unsigned int height(const Tree_Node* root) {
//        if (!root) {
//            return 0;
//        }
//     	const unsigned int left = height(root->left);
//     	const unsigned int right = height(root->right);
//     	return max(left, right) + 1;
//     }
//};



//Question 4
//class Solution {
//public:
//    /** Creates a deep copy of a binary tree.
//        @param root: a pointer to the root node of the binary tree
//        @return: a pointer to the root node of the deep copy
//    */
//    static Tree_Node* deep_copy(Tree_Node* root) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        if(!root){
//            return root;
//        }
//        Tree_Node* nodeCopy = new Tree_Node(root->val,NULL,NULL);
//        nodeCopy->left = deep_copy(root->left);
//        nodeCopy->right = deep_copy(root->right);
//        return nodeCopy;
//    }
//};

//Question 3
class Solution {
public:
    /** Returns the number of nodes in a binary tree.
        @param root: a pointer to the root node of the binary tree
        @return: number of nodes in the binary tree
    */
    static unsigned int num_of_nodes(Tree_Node* root) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        static unsigned int num = 0;
    	if (root) {
            num++;
    		num_of_nodes(root->left);
            num_of_nodes(root->right);
        }
        return num;
    }
};


#endif
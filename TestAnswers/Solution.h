#include <vector>
#include <stack>
#include <iostream>
using namespace std;





class Solution {
public:
    /** Generates a corrected character sequence from a raw sequence.
        @param raw: a string containing lowercase letters and * only
        @return: a corrected sequence from the input raw sequence
    */
    static string edit_text(const string& raw) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        vector<char>vec;
        for (int i = 0; i < raw.length(); i++) {
	        if(raw[i]=='*'){vec.pop_back();}
            else { vec.push_back(raw[i]); }
        }
        string actual="";
        for (int i = 0; i < vec.size();i++) {
            actual.push_back(vec.at(i));
        }
        return actual;
    }
};






//struct Tree_Node {
//	int val;
//	Tree_Node* left, * right;
//	Tree_Node(int val, Tree_Node* left = NULL, Tree_Node* right = NULL) :
//		val(val), left(left), right(right) {}
//};





//class Solution {
//public:
//	static int height(Tree_Node* root) {
//		if (!root) { return 0; }
//		return max(height(root->left), height(root->right)) + 1;
//	}
//	/** Tests whether a binary tree is height-balanced.
//		@param root: a pointer to the root of the input tree
//		@return: {true} if the input tree is balanced; {false} otherwise
//	*/
//	static bool is_balanced_tree(Tree_Node* root) {
//		// Please copy this code to Canvas answer textbox.
//		// Please add your code here to solve the problem.
//		if (!root) { return true; }
//		if((height(root->right)-height(root->left)<-1) || (height(root->right) - height(root->left) > 1)){
//			return false;
//		}
//		is_balanced_tree(root->left);
//		is_balanced_tree(root->right);
//	}
//};
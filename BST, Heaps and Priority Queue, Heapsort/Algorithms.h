#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stddef.h>
#include <exception>
#include <vector>
struct TreeNode
{
	//data fields
	int val;
	TreeNode* left;
	TreeNode* right;
	//constructor
	TreeNode(int x, TreeNode* left_child = NULL, TreeNode* right_child = NULL) :val(x), left(left_child), right(right_child){}
};

/**finds the min val in a binary search tree
 * \brief 
 * \param root the root node of a binary search tree
 * \return the minimum value
 */
int min_value(TreeNode* root){
	if (!root) { throw std::exception("Attempt to access keys in empty binary search tree."); }
	TreeNode* p = root;
	while (p->left) { p = p->left; }
	return p->val;
}//O(h)

/**finds the max val in a binary search tree
 * \brief
 * \param root the root node of a binary search tree
 * \return the max value
 */
int max_value(TreeNode* root) {
	if (!root) { throw std::exception("Attempt to access keys in empty binary search tree."); }
	TreeNode* p = root;
	while (p->right) { p = p->right; }
	return p->val;
}//O(h)

/**convers binary search tree to sorted vector
 * \brief 
 * \param root : root node of bstd
 * \param vec the output sorted vector
 */
void to_sorted_vector(TreeNode* root, std::vector<int>& vec){
	if(root){
		to_sorted_vector(root->left, vec);
		vec.push_back(root->val);
		to_sorted_vector(root->right, vec);
	}
}


/**
 * \brief converts a sorted vector (front index {start} to index {end}) into a binary search tree
 * \param vec a sorted vector
 * \param start the left index to convert
 * \param end the right index to convert
 * \return the root node of the binary search tree
 */
TreeNode* to_binary_search_tree(const std::vector<int>& vec,size_t start, size_t end){
	if (start > end) { return NULL; }
	size_t mid = (start + end) / 2;
	return new TreeNode(vec.at(mid), to_binary_search_tree(vec, start, mid - 1), to_binary_search_tree(vec, mid + 1, end));
}
//wrapper function
TreeNode* to_binary_search_tree(const std::vector<int>& vec){
	return to_binary_search_tree(vec, 0, vec.size() - 1);
}
#endif

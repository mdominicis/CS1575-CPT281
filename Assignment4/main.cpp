#include <iostream>
#include "Solution.h"
using namespace std;

int main(){
	Solution x;
	D_List_Node* head = new D_List_Node(1);
	head->next = new D_List_Node(2);
	head->next->next = new D_List_Node(3);
	head=x.reverse(head);
	cout << head->val;
	cout << head->next->prev->val;
	cout << head->next->next->val;
	//cout << x.hamming_dist(22,13);
}
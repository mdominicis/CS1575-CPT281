#include "Solution.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main() {
	D_List_Node* head = new D_List_Node(40);
	head->next = new D_List_Node(500);
	head->next->next = new D_List_Node(400);
	head->next->next->next = new D_List_Node(30);
	D_List_Node* current=Solution::deep_copy(head);
	while (current) {
		cout << current->val;
		current = current->next;
	}





	/*List_Node* head = new List_Node(40);
	head->next = new List_Node(500);
	head->next->next = new List_Node(400);
	head->next->next->next = new List_Node(30);*/
	/*problem 3
	 *vector<int>test=Solution::max_and_second_max(head);
	for(auto x:test){
		cout << x << endl;
	}*/
	/*problem 2
	 *Solution::remove_first_occurrence(head, 40);
	List_Node* current = head;
	while(current){
		cout << current->val;
		current = current->next;
	}
	cout << endl;*/
	/*Question 4
	 *list<string>li = { "Tom","Dick","Harry","Sam" };
	list<string>::iterator it = li.begin();
	it++;
	it++;

	it++;


	it = li.insert(it, "Lisa");

	it --;
	it--;

	it = li.erase(it);
	
	
	
	cout << *(it++)<<endl;
	cout << *it<<endl;
	for (list<string>::iterator i = li.begin(); i != li.end(); i++) {
		cout << *i;
	}
	cout << endl;*/

	/*Question 5
	vector<char>vec = { 'x','y','z','w'};
	vector<char>::iterator it = vec.begin();
	it++;
	it++;
	it++;
	it=vec.insert(it,'m');
	it -= 2;
	it=vec.erase(it);
	cout << *(it++);
	cout << *(it);

	cout << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	return 0;*/
}
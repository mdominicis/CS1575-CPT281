#include "Solution.h"
#include <iostream>
#include <queue>

using namespace std;



int main(){
	Solution x;
	queue<int>q;
	q.push(3);
	q.push(3);
	q.push(3);
	/*q.push(1);
	q.push(3);
	q.push(2);
	q.push(5);
	q.push(3);
	q.push(5);
	q.push(4);*/
	x.remove_max(q);
	int y = q.size();
	for(int i=0;i<y;i++){
		cout << q.front();
		q.pop();
	}

	/*Solution x;
	List_Node* head=new List_Node(1);
	head->next = new List_Node(2);
	cout<<(x.is_palindromic(head)?"True":"False");*/
	/*unsigned int x = 11;
	Solution y;
	cout<<y.to_binary(11);*/
}
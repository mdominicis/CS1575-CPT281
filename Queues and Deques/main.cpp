#include "List_Queue.h"
#include "List.Deque.h"
#include <iostream>

using namespace std;

int main(){

	List_Deque<int> D;
	D.push_back(5);
	D.push_back(8);
	D.push_front(11);
	D.push_front(20);
	D.pop_back();
	D.pop_front();
	cout << D.to_string() << endl;


	/*List_Queue<int> Q;
	Q.push(5);
	Q.push(11);
	Q.push(3);
	Q.push(4);
	Q.pop();
	cout << Q.to_string() << endl;*/
	system("pause");
	return 0;
}
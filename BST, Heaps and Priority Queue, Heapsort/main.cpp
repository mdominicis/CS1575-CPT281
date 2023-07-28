#include <iostream>
#include <queue>
#include "Priority_Queue.h"

using namespace std;

int main(){
	Priority_Queue<int> qu; 
	qu.push(3);
	qu.push(0);
	qu.push(5);

	cout << qu.top() << endl;
	qu.pop();
	cout << qu.top() << endl;
	qu.pop();
	cout << qu.top() << endl;
	qu.pop();

	system("pause");
	return 0;
}
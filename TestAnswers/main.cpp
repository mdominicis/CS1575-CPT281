#include "Solution.h"
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main(){
	Solution x;
	/*Tree_Node* head = new Tree_Node(1);
	head->left = new Tree_Node(2);
	head->left->left = new Tree_Node(4);
	head->left->left->left = new Tree_Node(6);
	head->right = new Tree_Node(3);
	head->right->right = new Tree_Node(5);
	head->right->right->right = new Tree_Node(7);
	
	bool test=x.is_balanced_tree(head);
	if(test){
		cout << "True";
	}
	else{
		cout << "False";
	}*/
	/*string test =  x.edit_text("dsyi*u***au*yu");
	cout << test;*/
	string line;
	map<string, set<int>>m;
	int counter = 0;
	while (getline(test,line)){
		istringstream iss(line);

	}

	return 0;
}

/*
initialize map with the key being a word and the value being the a set of the line numbers that word is on

set a counter to 0

set a word to an empty string

while there are words in stream
	take in word
	if a word is a new line
		add 1 to counter
	endif
	else if 	
		take in word with no punctuation
		add word to map key, and add the current value of counter to the set of indexes
	endif
endwhile
for length of map
	for length of set
		print out key from map
		print out item in set corresponding to index of for loop
		go to next value in set
	endfor
	go to next key in map
endfor
*/
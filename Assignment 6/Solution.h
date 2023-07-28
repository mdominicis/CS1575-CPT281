#ifndef SOLUTION_H
#define SOLUTION_H

#include <list>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    /** Returns the first missing letter in alphabetical order.
        @param s: a string containing lowercase English letters only
        @return: first missing letter in the string
    */
    static char first_missing_letter(const string& s) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        set<char> alphabet = { 'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        set<char> str;
        for(char c:s){
            str.insert(c);
        }
        set<char> difference;
    	set_difference(
            alphabet.begin(), alphabet.end(),
            str.begin(), str.end(),
            inserter(difference, difference.end())
        );
        return !difference.empty() ? *difference.begin() : ' ';
    }
};
//Question 4
//struct List_Node {
//    int val;
//    List_Node* next;
//    List_Node(int val, List_Node* next = NULL) : val(val), next(next) {}
//};
//class Solution {
//public:
//    /** Tests whether a singly-linked list has cycle.
//        @param head: a pointer to the head node of the linked list
//        @return: {true} if a cycle is found; {false} otherwise
//    */
//    static bool has_cycle(List_Node* head) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        unordered_set<List_Node*> us;
//        List_Node* current = head;
//        while(current){
//        	if (!us.insert(current).second) { return true; }
//            current = current->next;
//        }
//        return false;
//    }
//};
//Question 2
//class Solution {
//public:
//    /** Finds the weight of the last stone.
//        @param weights: weights of stones
//        @return: weight of the last stone; or {0} if no stone left
//    */
//    static unsigned int last_weight(const vector<unsigned int>& weights) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        priority_queue<unsigned int> pq(weights.begin(), weights.end());
//        while(pq.size()>1){
//            unsigned int max1 = pq.top();
//            pq.pop();
//            unsigned int max2 = pq.top();
//            pq.pop();
//            if(max1!=max2){
//                pq.push(max1 - max2);
//            }
//        }
//        if(!pq.empty()){
//            return pq.top();
//        }
//        return 0;
//    }
//};














//class Solution {
//public:
//    /** Finds the path from the root to a node with specified label
//        in an infinite binary tree of natural numbers.
//        @param label: label of the last node of the path
//        @return: labels of nodes in the path
//    */
//    static list<unsigned int> path(unsigned int label) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        list<unsigned int> li;
//        li.push_front(label);
//    	while(label>0){
//            if (!(label & 1)) {
//                label = label / 2 - 1;
//            }
//            else if ((label & 1) && label > 0) {
//                label = (label - 1) / 2;
//            }
//            li.push_front(label);
//        }
//        return li;
//    }
//};

#endif
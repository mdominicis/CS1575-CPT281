#ifndef SOLUTION_H
#define SOLUTION_H

#include <stack>
#include <queue>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::to_string;
using std::queue;



class Solution {
public:
    /** Removes all the maximum values from a queue.
        @param q: a non-empty queue of integers
    */
    static void remove_max(queue<int>& q) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        queue<int> temp = q;
        int max = INT_MIN;
        int num_items = 0;
        while (!empty(temp)){
	        if(max<temp.front()){
                max = temp.front();
	        }
            temp.pop();
            num_items++;
        }
        for(int i=0;i<num_items;i++){
            int num = q.front();
            q.pop();
            if(num!=max){
                q.push(num);
            }
        }
    }
};



//struct List_Node {
//    int val;
//    List_Node* next;
//    List_Node(int val) : val(val), next(NULL) {}
//};
//
//class Solution {
//public:
//    /** Tests whether a singly-linked list is a palindrome.
//        @param head: a pointer to the head node of the list
//        @return: {true} if the list is palindromic; {false} otherwise
//    */
//    static bool is_palindromic(List_Node* head) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        List_Node* current = head;
//        stack<int>stk;
//        while (current){
//            stk.push(current->val);
//            current = current->next;
//        }
//        current = head;
//        while(current){
//	        if(current->val!=stk.top()){
//                return false;
//	        }
//            stk.pop();
//            current = current->next;
//        }
//
//        return true;
//    }
//};


//class Solution {
//public:
//    /** Converts a decimal number to binary using a stack.
//        @param dec_num: a non-negative integer
//        @return: a string of zeroes and ones
//    */
//    static string to_binary(unsigned int dec_num) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        stack<unsigned int> stk;
//        string str;
//        if(!dec_num){
//            return "0";
//        }
//        while (dec_num != 0){
//            stk.push(dec_num%2);
//        	dec_num /= 2;
//        }
//        while(!stk.empty()){
//            str += to_string(stk.top());
//            stk.pop();
//        }
//        return str;
//    }
//};
#endif
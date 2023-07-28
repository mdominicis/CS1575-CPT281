#ifndef SOLUTION_H
#define SOLUTION_H
#include <cstddef>
//Q1
//struct List_Node {
//    int val;
//    List_Node* next;
//    List_Node(int val) : val(val), next(NULL) {}
//};
//class Solution {
//public:
//    /** Recursively reverses a singly-linked list.
//        @param head: a pointer to the head node of the input list
//        @return: a pointer to the head node of the reversed list
//    */
//    static List_Node* reverse(List_Node* head) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        if(!head||!head->next){ return head; }
//        List_Node* newHead = reverse(head->next);
//        head->next->next = head;
//        head->next = NULL;
//        return newHead;
//    }
//};
//
//Q2
struct D_List_Node {
    int val;
    D_List_Node* next, * prev;
    D_List_Node(int val) : val(val), next(NULL), prev(NULL) {}
};
class Solution {
public:
    /** Recursively reverses a doubly-linked list.
        @param head: a pointer to the head node of the input list
        @return: a pointer to the head node of the reversed list
    */
    static D_List_Node* reverse(D_List_Node* head) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        if (!head) { return head; }
        if(!head->next){
            head->prev = NULL;  // This step is critical.
            return head;
        }
        D_List_Node* temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        if (!head->prev) { return head; }
    	return reverse(head->prev);
    }
};

//Q4
//class Solution {
//public:
//    /** Finds the Hamming distance of two integers.
//        @param num_1: first integer
//        @param num_2: second integer
//        @return: Hamming distance of the two integers
//    */
//    static unsigned int hamming_dist(int num_1, int num_2) {
//        // Please copy this code to Canvas answer textbox.
//        // Please add your code here to solve the problem.
//        int ham = num_1 ^ num_2;
//        int count = 0;
//        while (ham){
//            count += ham & 1;
//            ham >>= 1;
//        }
//        return count;
//    }
//};
#endif
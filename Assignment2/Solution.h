#ifndef SOLUTION_H
#define SOLUTION_H
#include <algorithm>
#include <stddef.h>
#include<limits.h>
#include <vector>
using namespace std;
struct D_List_Node {
    int val;
    D_List_Node* next, * prev;
    D_List_Node(int val) : val(val), next(NULL), prev(NULL) {}
};
struct List_Node {
    int val;
    List_Node* next;
    List_Node(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    /** Creates a deep copy of a doubly-linked list.
        @param head: a pointer to the head node of the original list
        @return: a pointer to the head node of the deep copy
    */
    static D_List_Node* deep_copy(D_List_Node* head) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        D_List_Node* headCopy = new D_List_Node(head->val);
        D_List_Node* current = head->next;
        D_List_Node* copytracker = headCopy;
        while (current) {
            D_List_Node* addToCopy = new D_List_Node(current->val);
            copytracker->next = addToCopy;
            addToCopy->prev = copytracker;
            copytracker = addToCopy;
            current = current->next;
        }

        return headCopy;
    }




    /** Removes the first occurrence of a value from a singly-linked list.
        @param head: a pointer to the head node of the list
        @param target: value to search (and remove) in the list
    */
    static void remove_first_occurrence(List_Node* head, int target) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        List_Node* current = head;
        while (current->next && current->next->val != target){
            current = current->next;
        }
        List_Node* to_be_deleted = current->next;
        current->next = current->next->next;
        delete to_be_deleted;
    }



    /** Returns the max and 2nd max elements in a linked list.
        @param head: a pointer to the head of the linked list
        @return: a vector containing the max and 2nd max elements
    */
    static vector<int> max_and_second_max(List_Node* head) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        vector<int>maxes = { head->val,head->next->val };
        List_Node* current = head;
        while(current){
            if (maxes.at(1) > maxes.at(0)) { std::swap(maxes.at(0), maxes.at(1)); }
            if(current->val>maxes.at(1)){
                maxes.pop_back();
                maxes.push_back(current->val);
            }
            current = current->next;
        }
        return maxes;
    }



};

#endif SOLUTION_H
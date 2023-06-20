#include <iostream>
#include "Vector.h"

using namespace std;
static string remove_vowels(const string& s);
int main(){
    string input="datastructures";
    cout<<remove_vowels(input)<<endl;
    Vector<int> test;
    test.push_back(2);
    test.push_back(4);
    test.push_back(7);
    test.push_back(9);
    test.push_back(10);
    test.push_back(13);
    test.push_back(20);
    cout<<test<<endl;
    cout<<test.find(20)<<endl;
    return 0;
}

static string remove_vowels(const string& s) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.
        string noVowels="";
        for(size_t i=0;i<s.length();i++){
            if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'){
                noVowels.push_back(s[i]);
            }
        }
        return noVowels;
    }
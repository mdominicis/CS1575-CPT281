#ifndef STACK_ALGORITHMS_H
#define STACK_ALGORITHMS_H
#include "List_Stack.h"
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
using std::vector;
using std::string;
using std::istringstream;
using std::stoi;

/**Reverses an array of integers. */
void reverse_arr(vector<int>&vec){
	List_Stack<int> stk;
	for (size_t i = 0; i < vec.size(); i++) { stk.push(vec.at(i)); }
	for (size_t j = 0; j < vec.size(); j++){
		vec[j] = stk.top();
		stk.pop();
	}
}

/** tests whether a string is palindromic
@returns: {true} if the string is palindromic; {false} otherwise
 */
bool is_palindromic(const string& str){
	List_Stack<char> stk;
	for (size_t i = 0; i < str.size(); i++) { stk.push(str[i]); }
	string reversed_str;
	while(!stk.empty()){
		reversed_str += stk.top();
		stk.pop();
	}
	return reversed_str == str;
}

/**Tests whether parentheses are balanced in an expression.
 @returns: {true} if parentheses are balances; {false} if otherwise
*/

bool is_balanced(const string& exp){
	List_Stack<char> stk;
	for (size_t i = 0; i < exp.size(); i++) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') { stk.push(exp[i]); }
		if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
			if (stk.empty()) { return false; }
			if (exp[i] == ')' && stk.top() != '(') { return false; }
			if (exp[i] == ']' && stk.top() != '[') { return false; }
			if (exp[i] == '}' && stk.top() != '{') { return false; }
			stk.pop();
		}
	}
	return stk.empty();
}

/**evaluates a postfix expression
	@returns: evaluation result
	*/
int eval_postfix(const string& postfix){
	istringstream iss(postfix);
	List_Stack<int> stk;
	string token; //current token
	while(iss>>token){
		if (isdigit(token[0])) { stk.push(stoi(token)); }
		else{
			int right = stk.top();
			stk.pop();
			int left = stk.top();
			stk.pop();
			if (token == "+") { stk.push(left + right); }
			if (token == "-") { stk.push(left - right); }
			if (token == "*") { stk.push(left * right); }
			if (token == "/") { stk.push(left / right); }
		}
	}
	return stk.top();
}

/**gets the relative precedence of some operators
	@returns: relative precedence
*/

int precedence(const string& oper){
	if (oper == "*" || oper == "/") { return 2; }
	if (oper == "+" || oper == "-") { return 1; }
	return -1;
}

/**converts infix expression to postfix expression*/

string infix_to_postfix(const string& infix_exp){
	istringstream iss(infix_exp);
	List_Stack<string> stk;
	string token, result;
	while(iss>>token){
		if (isdigit(token[0])) { result += " " + token; }
		else if (token == "(") { stk.push(token); }
		else if(token=="+"||token=="-"||token=="*"||token=="/"){
			while(!stk.empty()&&stk.top()!="("&&precedence(token)<=precedence(stk.top())){
				result += " " + stk.top();
				stk.pop();
			}
			stk.push(token);
		}
		else{
			while(stk.top()!="("){
				result += " " + stk.top();
				stk.pop();
			}
			stk.pop();
		}
	}
	while(!stk.empty()){
		result += " " + stk.top();
		stk.pop();
	}
	return result.substr(1);
}

#endif
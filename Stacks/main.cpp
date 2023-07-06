#include "Stack_Algorithms.h"
#include <iostream>
#include <vector>
using namespace std;
int main(){
	/*vector<int>vec = { 1,2,3,4,5 };
	reverse_arr(vec);
	cout << '[';
	for(size_t i = 0;i<vec.size();i++){
		cout << vec.at(i);
		if (i != vec.size() - 1) { cout << ", "; }
	}
	cout << ']'<<endl;*/

	/*string str = "raceacar";
	bool result = is_palindromic(str);
	cout << (result ? "True" : "False");*/

	/*string exp = "{a[b[b](c)]c}";
	bool result_3 = is_balanced(exp);
	cout<< (result_3 ? "True" : "False");*/

	/*string postfix_exp = "3 4 7 * 2 / +";
	int result_4 = eval_postfix(postfix_exp);
	cout << result_4 << endl;*/

	string infix_exp = "( 3 + 2 ) * 5 - ( 3 - 2 )";
	string infix_exp2 = " 2 - 3 * ( ( 2 - 1 ) / 5 )";
	int result_5 = eval_postfix(infix_to_postfix(infix_exp2));
	cout << infix_to_postfix(infix_exp2)<<endl;

	system("pause");
	return 0;
}
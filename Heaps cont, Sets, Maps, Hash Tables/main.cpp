#include "Heapsort.h"
#include "excercise.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){

	map<string, string> m;
	m["Dayu"] = "Wang";
	m["Rex"] = "McKanry";
	m["Deepika"] = "Jagmohan";

	/*for(map<string,string>::const_iterator it=m.begin();it!=m.end();it++){
		cout << it->first << ' ' << it->second<<endl;
	}*/

	/*for(pair<string,string> p:m){
		cout << p.first << ' ' << p.second << endl;
	}*/

	bool test_1 = m.find("Dayu") != m.end();
	bool test_2 = m.find("Josh") != m.end();
	cout << "Key \"Dayu\" " << (test_1 ? "exists." : "does not exist.") << endl;
	cout << "Key \"Josh\" " << (test_2 ? "exists." : "does not exist.") << endl;

	//vector<unsigned int> vec = { 3,10,8,20,6,8,20,10,2,5,4,7,10 };
	//unsigned int result = average_top_five(vec);
	//cout << result<<endl;
	/*Heapsort::sort(vec);*/
	//for(int i=0;i<vec.size();i++){
	//	cout << vec.at(i);
	//}
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "List.h"
using namespace std;
int main()
{
	//{string} supports iterators
	string s = "Hello World";
	for(string::iterator it=s.begin();it!=s.end();it++){
		cout << *it << ' ';
	}
	cout << endl;
	//{vector} supports iterators
	vector<int> vec = { 1,2,3,4,5 };
	for(vector<int>::iterator it=vec.begin(); it!=vec.end();it++){
		cout << *it << ' ';
	}
	cout << endl;


	//{list} supports iterators
	list<int> bo = { 11,12,13,14,15 };
	for(list<int>::iterator it=bo.begin();it!=bo.end();it++){
		cout << *it << ' ';
	}
	cout << endl;

	//List<int>li;
	//li.push_back(1);
	//li.push_back(2);
	//li.push_back(3);
	//li.push_back(4);


	//List<int>::iterator iter = li.begin();
	//li.insert(iter, 0);
	//iter++;
	//++iter;
	//li.insert(iter, 100);
	//iter++;
	//++iter;
	//li.erase(iter);
	//li.erase(iter);

	//iter = li.find(100);
	//li.erase(iter);

	////iterate through {li}
	//for(List<int>::iterator it=li.begin();it!=li.end();it++){
	//	cout << *it << ' ';
	//}
	//cout << endl;

	//for (List<int>::iterator it = --li.end(); it != li.begin(); it--) {
	//	cout << *it << ' ';
	//	if(it==++li.begin()){
	//		cout << *(--it) << endl;
	//		break;
	//	}
	//}
	//cout << endl;


	//iter = li.find(100);
	//li.erase(iter);





	//searching
	list<string>li_2 = { "Dayu", "Wang", "Fei", "Wu" };
	list<string>::iterator it_1 = find(li_2.begin(), li_2.end(), "Fei");

	//sorting
	vector<int> arr = { 8,7,6,5,4,2,0,-10 };
	sort(arr.begin(), arr.end());
	for(vector<int>::iterator it=arr.begin();it!=arr.end();it++){
		cout << *it << ' ';
	}
	cout << endl;






	system("pause");
	return 0;
}


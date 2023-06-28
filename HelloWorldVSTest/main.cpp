#include "Ordered_Vector.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main() {
    Vector<char> vec(9, 'x');
    vec.push_back('y');
    vec.push_back('z');
    vec.pop_back();

    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << endl;
    }

    cout << vec << endl;
    system("pause");
    return 0;
}
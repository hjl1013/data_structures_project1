#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include "stack.hpp"

using namespace std;

int main() {

    //You can check if your code works well.

    cout<<__cplusplus<<endl;

    Stack<int> s;

    cout<<boolalpha;
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    
    s.push(10);
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    cout<<s.pop()<<endl;

    pair<char,char> p = make_pair('(',')');
    vector<pair<char,char>> v;
    v.push_back(p);

    string a = "(3))";
    cout<<checkParentheses(a, v)<<endl;
	
    // My Code
    cout << checkParentheses("(3(567()))", v) << endl;
    cout << checkParentheses("(3(567())))))))", v) << endl;
    cout << calculate("1+2*3") << endl;
    cout << calculate("+1*(2+3)") << endl;
    cout << calculate("-2+(-3-2*4)*3") << endl;

    cout << calculate("12.345-10*(1-2)") << endl;

    return 0;

}

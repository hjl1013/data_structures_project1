#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "stack.hpp"

using namespace std;

bool checkParentheses(const string& line, const vector<pair<char,char>>& pairs){
    //TODO
    Stack<char> parentheses;
    for (int i = 0; i < line.length(); i++) {
        for (auto pair : pairs) {
            if (line[i] == pair.first) {
                parentheses.push(line[i]);
                break;
            }
            else if (line[i] == pair.second) {
                if (!parentheses.isEmpty() && parentheses.pop() == pair.first) {
                    break;
                }
                else {
                    return false;
                }
            }
        }
    }
    if (parentheses.isEmpty()) {
        return true;
    }
    else {
        return false;
    }
}

float calculate(const string& line){
    //TODO
    Stack<float> numbers;
    Stack<char> operators;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '+' || line[i] == '-') {
            if (i == 0 || line[i - 1] == '(') {
                numbers.push(0);
            }
            while (!operators.isEmpty() && operators.top() != '(') {
                float b = numbers.pop();
                float a = numbers.pop();
                numbers.push(operate(a, b, operators.pop()));
            }
            operators.push(line[i]);
        }
        else if (line[i] == '*' || line[i] == '/' || line[i] == '(') {
            operators.push(line[i]);
        }
        else if (line[i] == ')') {
            while (operators.top() != '(') {
                float b = numbers.pop();
                float a = numbers.pop();
                numbers.push(operate(a, b, operators.pop()));
            }
            operators.pop();
        }
        else {
            float factor = 1;
            bool decimal = false;
	    numbers.push(0);
            while (true) {
                if ('0' <= line[i] && line[i] <= '9') {
                    if (!decimal) {
                        numbers.push(numbers.pop() * 10 + line[i] - '0');
                    }
                    else {
                        factor /= 10;
                        numbers.push(numbers.pop() + (line[i] - '0') * factor);
                    }
                }
                else if (line[i] == '.') {
                    decimal = true;
                }
                else {
		    i--;
                    break;
                }
		i++;
            }
        }
    }
    
    while(!operators.isEmpty()){
	    float b = numbers.pop();
	    float a = numbers.pop();
	    numbers.push(operate(a, b, operators.pop()));
    }

    return numbers.top();
}

// str?????? operator?? ?????? ????
float operate(float a, float b, char op) {
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else if (op == '*') {
        return a * b;
    }
    else {
        return a / b;
    }
}

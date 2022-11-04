#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "stack.hpp"

using namespace std;

bool checkParentheses(const string& line, const vector<pair<char,char>>& pairs){
    //TODO
    Stack<char> parentheses;
    for (int i = 0; i < line.length; i++) {
        for (auto pair : pairs) {
            if (line[i] == pair[0]) {
                parentheses.push(line[i]);
                break;
            }
            else if (line[i] == pair[1]) {
                if (parentheses.pop() == pair[0]) {
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

    for (int i = 0; i < line.length; i++) {
        if (line[i] == '+' || line[i] == '-') {
            if (i == 0 || line[i - 1] == '(') {
                numbers.push(0);
            }
            while (!operators.isEmpty() || operators.top() != '(') {
                b = numbers.pop();
                a = numbers.pop();
                numbers.push(operate(a, b, operators.pop()));
            }
            operators.push(line[i]);
        }
        else if (line[i] == '*' || line[i] == '/' || line[i] == '(') {
            operators.push(line[i]);
        }
        else if (line[i] == ')') {
            while (operators.top() != '(') {
                b = numbers.pop();
                a = numbers.pop();
                numbers.push(operate(a, b, operators.pop()));
            }
            operators.pop();
        }
        else {
            numbers.push(line[i]);
        }
    }
    return numbers.top();
}

// str형태의 operator의 연산을 수행
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
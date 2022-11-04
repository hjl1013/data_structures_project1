#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Stack{
    private: 
        int current;
        int size;
        T * array;

    public:
        Stack<T> (int _size = 16)
        {   
            current = -1;
            size = _size;
            array = new T[_size];
        }
        ~Stack()
        {
            delete[] array;
        }    

        bool isEmpty() const;
        bool isFull() const;
        T top() const;
        T pop();
        void push(const T& item);
};

template <typename T>
bool Stack<T>::isEmpty() const{
    //TODO
    return current == -1;
}

template <typename T>
bool Stack<T>::isFull() const{
    //TODO
    return current == size - 1;
}

template <typename T>
T Stack<T>::top() const{
    //TODO
    return array[current];
}

template <typename T>
T Stack<T>::pop(){
    //TODO
    return array[current--];
}

template <typename T>
void Stack<T>::push(const T& item){
    if (isFull()){
	    T *new_array = new T[2 * size];
	    for (int i = 0; i < size; i++){
		    new_array[i] = array[i];
	    }
	    array = new_array;
	    size *= 2;
    }
    array[++current] = item;
    return;
}

bool checkParentheses(const string& line, const vector<pair<char,char>>& pairs);
float calculate(const string& line);

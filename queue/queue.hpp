#include <iostream>

template <typename T>
struct Item{
    T value;
    int priority;
};

template <typename T>
class Queue{
    private:
        int front;
        int rear;
        bool empty;
        int size;
        Item<T> *array;

    public:
        Queue<T>(int _size = 16)
        {
            front = 0;
            rear = _size - 1;
            empty = true;
            size = _size;
            array = new Item<T>[_size];
        }
        ~Queue(){
            delete[] array;
        }

        void enqueue(const T& value, int priority);
        int top();
        T dequeue();        
        bool isFull();
};

template <typename T>
void Queue<T>::enqueue(const T& value, int priority){
    if (isFull()) {
        Item<T> *new_array = new Item<T>[size * 2];
        for (int i = 0; i < size; i++) {
            new_array[i] = array[(front + i) % size];
        }
        array = new_array;
        front = 0;
        rear = size - 1;
        size *= 2;
    }
    rear = (rear + 1) % size;
    array[rear].value = value;
    array[rear].priority = priority;
    
    if (empty) empty = false;
    /*
    for (int i = 0; i < size; i++){
	    std::cout << array[i].value << " ";
    }
    std::cout << std::endl
    */;
    return;
}

template <typename T>
int Queue<T>::top(){
    //TODO
    //returning the array index of the highest priority item
    int max_idx = front;
    for (int i = (front + 1) % size; i != (rear + 1) % size; i = (i + 1) % size) {
        if (array[max_idx].priority < array[i].priority) {
            max_idx = i;
        }
    }

    return max_idx;
}

template <typename T>
T Queue<T>::dequeue(){
    //empty 잘 관리해주기
    //TODO
    int max_idx = top();
    T max_val = array[max_idx].value;
    for (int i = max_idx; i != front; i = (i + size - 1) % size) {
        array[i] = array[(i + size - 1) % size];
    }

    if (front == rear) {
        empty = true;
    }
    front = (front + 1) % size;
    /*
    for (int i = 0; i < size; i++) {
	    std::cout << array[i].value << " ";
    }
    std::cout << std::endl
    */;
    return max_val;
}

template <typename T>
bool Queue<T>::isFull(){
    if (!empty && (rear + 1) % size == front){
	    return true;
    }
    else{
	    return false;
    }
}

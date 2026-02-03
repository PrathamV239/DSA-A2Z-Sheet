#include <iostream>
using namespace std;

class Stack{

    private:
    int* arr;
    int capacity;
    int topIndex;


    public:

    Stack(int size = 100){
    capacity = size;
    arr = new int[capacity];
    topIndex = -1;
    }

    ~Stack(){
        delete [] arr;
    }

    void push(int x){
        if (topIndex >= capacity -1){
            cout << "The Stack is full:\n";
            return;
        }
        arr[++topIndex] = x;

    }

    int pop(){
        if(isEmpty()){
            cout<< "The Stack is empty\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty(){
        return topIndex == -1;

    }

};


int main (){

    Stack s;
    s.push (10);
    s.push(20);
    s.push(30);

cout << "Top: " << s.top() << endl;     // 30
    cout << "Pop: " << s.pop() << endl;     // 30
    cout << "Top: " << s.top() << endl;     // 20
    cout << "Empty? " << s.isEmpty() << endl; // false
    
    return 0;

}
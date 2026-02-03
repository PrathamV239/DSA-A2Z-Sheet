#include <iostream>

using namespace std;

class Stack{

private:
    int* arr;
    int capacity;
    int topIndex;

public: 
    Stack(int size = 1000){
    int capacity = size;
    arr = new int[capacity];
    topIndex = -1;
}

    ~Stack(){
        delete []arr;
    }

    void push (int x){
        if(topIndex >= capacity-1){
            cout<< "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    int pop(){
        if (isEmpty()){
            cout<<"Stack underflow\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top(){
        if(isEmpty()){
            cout<< "Stack Underflow\n";
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
    s.push(10);
    s.push(30);
    s.push(40);

    cout << "Top: " << s.top() << endl;    
    cout << "Pop: " << s.pop() << endl;     
    cout << "Top: " << s.top() << endl;     
    cout << "Empty? " << s.isEmpty() << endl; 
    
    return 0;

}
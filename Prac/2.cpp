#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> st1, st2;
    
public:
    void push(int x) {
        // Move all elements to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Push new element to st1
        st1.push(x);
        
        // Move all elements back to st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if (st1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        
        int front = st1.top();
        st1.pop();
        return front;
    }
    
    int peek() {
        if (st1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return st1.top();
    }
    
    bool isEmpty() {
        return st1.empty();
    }
};

int main() {
    Queue q;
    
    q.push(4);
    q.push(8);
    q.push(3);
    
    cout << "Front: " << q.peek() << endl;   // 4 (oldest)
    cout << "Pop: " << q.pop() << endl;      // 4
    cout << "Front: " << q.peek() << endl;   // 8
    cout << "Empty? " << q.isEmpty() << endl; // false
    
    return 0;
}

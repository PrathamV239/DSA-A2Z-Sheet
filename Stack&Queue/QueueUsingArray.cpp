#include <iostream>
using namespace std;

class Queue{

    private :
        int* arr;
        int currSize, maxSize;
        int front, rear;


    public:

    Queue(int size = 10){
        maxSize = size;
        arr = new int [maxSize];
        front = -1;
        rear = -1 ;
        currSize = 0;
    }

    ~Queue(){
        delete [] arr;
    }

    void push (int x){
        if (currSize == maxSize){
            cout << "Queue is full\n";
            return;
        }
        if (rear == -1){
            front = rear = 0;
        }
        else {
            rear = (rear +1) % maxSize;
        }
        currSize++;
        arr[rear] = x;

    }


    int pop(){
        if(front == -1){
            cout << " Queue is empty\n";
            return -1;
        }
        int popped = arr[front];
        if(currSize == 1){
            front = rear = -1;
        }
        else {
            front = (front + 1) % maxSize;
        }

        currSize --;
        return popped;
        
    }

    int peek(){
        if (front == -1){
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        return currSize ==0;
    }


};


int main (){


     Queue q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Front: " << q.peek() << endl;      // 10
    cout << "Pop: " << q.pop() << endl;         // 10
    cout << "Front: " << q.peek() << endl;      // 20

    cout << "Empty? " << q.isEmpty() << endl;   // false
    
    return 0;
}
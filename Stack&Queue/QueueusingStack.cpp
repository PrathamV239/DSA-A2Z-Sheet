#include <iostream>
#include <stack>
using namespace std;

class Queue{
private:
  stack <int> s1, s2;

 public: 
  void push(int x){
    while (!s1.empty()){
      s2.push(s1.top());
      s1.pop();

    }
    s1.push(x);


    while (!s2.empty()){

      s1.push(s2.top());
      s2.pop();

    }
  } 


  int pop(){

    if(s1.empty()){
      cout<< "Queue is empty\n";
      return -1;
    }

    int front = s1.top();
    s1.pop();
    return front;
  }

   int peek() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }
    
    bool isEmpty() {
        return s1.empty();
    }

};



int main(){


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
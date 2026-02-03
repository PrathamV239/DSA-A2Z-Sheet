#include <iostream>
#include <queue>

using namespace std;

class Stack {

private:
  queue<int> q;


public :
  void push(int x){
    int size = q.size();
    q.push(x);
    for (int i = 0; i < size; i++){
      q.push(q.front());
      q.pop();
    }
  }

  int pop(){
    int top = q.front();
    q.pop();
    return top;
  }

  int top(){
    return q.front ();
  }

  bool isEmpty(){
    return q.empty();
  }

};


int main (){

   Stack st;
    
    st.push(4);
    st.push(8);
    
    cout << "Top: " << st.top() << endl;     // 8
    cout << "Pop: " << st.pop() << endl;     // 8
    cout << "Top: " << st.top() << endl;     // 4
    cout << "Empty? " << st.isEmpty() << endl; // false

 return 0;

}
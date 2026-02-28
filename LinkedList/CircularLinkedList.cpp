#include <iostream>
using namespace std;


struct Node{

  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr){}
  Node(int val, Node* nextNode) : data (val), next(nextNode){}

};

class CircularLL{

private : 
  Node * tail;

public: 
  CircularLL() : tail(nullptr){}

  void traverse (){

    Node * current = tail->next;
    do{
      cout<< current->data<< " ";
      current = current ->next;   

    }
    while (current != tail->next);
    cout << endl;
  } 


  // Node* Insert(int val){

  //   Node* newNode = new Node(val);

  //   if (tail == nullptr){
  //     newNode = tail;
  //   }


  // }

  Node* InsertAfter(int val, int index){

    Node* newNode = new Node(val);

    if (tail == nullptr){
      newNode = tail;
      return tail;
    }

    Node* current = tail->next;
    int cntr =0;

    while (cntr != index){
      current = current ->next;
      cntr++;
    }

    newNode->next = current -> next;
    current ->next = newNode;
return tail;
  }


  Node* InsertAt(int val, int index){

    Node* newNode = new Node(val);

    if (tail == nullptr) {
      newNode = tail;
      return tail;
    }

    Node* current = tail ->next;
    int cntr= 0;

    while (cntr != index-1)
    {
      current= current -> next;
      cntr ++;\
    }
    newNode-> next= current->next;
    current ->next = newNode;

    return tail;

  }

  Node* InsertAtEnd(int val){

     Node* newNode = new Node(val);
    if(tail == nullptr){
      tail = newNode;
      tail->next = tail;
      return tail;
    }
   
    newNode -> next = tail->next;
    tail->next = newNode;
    tail = newNode;
    return tail;
    
  }

  Node* InsertAtBeginning(int val){

    Node* newNode = new Node(val);

if (tail == nullptr){
  tail = newNode;
  newNode->next = newNode;
  return tail;
}

  newNode ->next = tail ->next;
  tail->next= newNode;
    return tail;

  }


int deleteVal(int val){

  if (tail == nullptr){
    return -1;
  }


Node* current = tail;
do {

if(current->next->data == val){
  if(current ->next == tail){
    tail = current;
  }
  Node* temp = current ->next;
  current ->next = temp->next;
  delete temp;
  return val;
  }
  current = current->next;

}while (current != tail);


}

 
};
int main(){

  CircularLL list;
   list.InsertAtEnd(10);
   list.InsertAtEnd(20);
   list.InsertAtEnd(30);
  list.traverse();
   list.InsertAtBeginning(0);


   list.InsertAfter(55,2);
      list.traverse();

         list.InsertAt(34,2);
      list.traverse();
list.deleteVal(0);
list.traverse();
  return -1;

}
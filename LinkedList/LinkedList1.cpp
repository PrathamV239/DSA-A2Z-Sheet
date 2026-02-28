#include <iostream>
#include <stack>

using namespace std;

struct Node {

int data;
Node* next;

Node(int val, Node* nextNode): data(val), next(nextNode){}
Node(int val): data(val), next(nullptr){}

};

class LinkedList{
private :
  Node* head;

public:   
  LinkedList(): head(nullptr){}

  void traverse(){

    Node* current ;
    current = head;
    while (current != nullptr){
      cout<< current-> data << " ";
      current = current -> next;
    }
    cout << endl;
    
  }


  Node* insert(int val){

    if (head == nullptr){
      Node* newNode = new Node(val);
      head = newNode;
      return head;
    }

    Node* newNode = new Node(val);
    Node* current = head;

    while (current -> next != nullptr){
      current= current -> next;
    }
    current -> next = newNode;
    return head;
  }


  Node* InsertAtBegining(int val){

    Node* newNode = new Node(val);

    if (head == nullptr){
      head = newNode;
      return head;
    }

    newNode->next = head;
    head = newNode;
    return head;
  }

  Node* Search(int val){

    Node* current = head;
    while (current != nullptr){

      if (current -> data == val) return current;
      current = current-> next ;

    }
    return nullptr;
  }


  int findLength (){

    Node* current = head;
    int cntr = 0;
    while (current != nullptr){
      current = current -> next;
      cntr++;
    }
return cntr;
  }

  Node* InsertAtPosi(int val, int index){
    Node* newNode = new Node(val);
    Node* current = head;

    int cntr =0;
    while(cntr != index){
      if(current -> next == nullptr) return head;
      current = current-> next;
      cntr++;
    }
    newNode -> next = current -> next;
    current -> next = newNode;

  }

  Node* InsertAfterPosi(int val, int index){

    Node* newNode = new Node(val);
    Node* current = head;

    int cntr = 0;
    if (index ==0){
      newNode -> next = head;
      head = newNode;
    }

    while (cntr != index-1){
      if(current->next == nullptr) return head;
      current = current-> next;
      cntr ++;
    }

    newNode-> next = current-> next;
    current->next = newNode;
       cout << endl;
  return head;
  }



int deleteVal(int val){
  if (head == nullptr){
    return -1;

  }
  if (head -> data == val){
    Node* temp = head;
    head = head ->next;
    delete temp;
    return val;
  }

  Node*current = head;
  while (current ->next != nullptr){
    if(current->next->data == val){
      Node*temp = current->next;
      current->next = temp->next;
      delete temp;
      return val;
    }
    current = current->next;
  }
return -1;
}

};


int main(){

  LinkedList list;
  list.insert(10);
  list.insert(20);
  list.insert(30);
  list.InsertAtBegining(5);
  list.InsertAtPosi(40,2);
  list.InsertAfterPosi(50,3);
  list.traverse();
  list.deleteVal(40);
  list.traverse();
}
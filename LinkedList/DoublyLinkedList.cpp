#include <iostream>
using namespace std;

struct Node{

  int data;
  Node* prev;
  Node* next;
  
  Node (int val) : data(val), next(nullptr), prev(nullptr){}
};

class LinkedList{

  private: Node* head;

  public: 
    LinkedList(): head(nullptr){}


    void traverse(){
      Node* curr = head;
      while (curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
      }
      cout << endl;
    }


    Node* insert(int val){

      if(head == nullptr){
        head = new Node(val);
        return head;
      }

      Node* curr = head;
      while (curr-> next!= nullptr){
        curr= curr-> next;
      }
      Node* newNode = new Node(val);
      curr-> next = newNode;
      newNode -> prev = curr; 

      return head;
    }


    Node* InsertionAtBegining(int val){
      Node* newNode = new Node (val);

      if (head != nullptr){
       head-> prev = newNode;
      }

      newNode-> next = head;
      head = newNode;
      return head;
    }


    Node* InsertAtPosi(int val, int index){

    Node* newNode = new Node(val);
    Node* current = head;
    int cntr = 0;

    while (index != cntr){
      if(current-> next == nullptr) return head;
      current = current ->next;
      cntr++;
    }
    newNode -> next = current -> next;
    current-> next-> prev = newNode;
    current -> next = newNode ;
    newNode -> prev = current ;

    }

    Node* deleteVal(int val){

      if (head == nullptr){
        return nullptr;

      }

      if (head-> data == val){
        Node* temp = head;
        head = head-> next;
        
        if (head -> next != nullptr){
          head->prev = nullptr;
        }

        delete temp;
        return head;

      }

       Node* curr = head;
      while (curr -> next != nullptr ){
     
          if (curr -> next -> data == val){
            Node* temp = curr-> next;
            curr-> next = temp -> next;

            if(temp -> next != nullptr){
              temp -> next-> prev = curr;
            }

            delete temp;
            return head;
          }
          curr = curr-> next;
      }
return head;

    }


};




int main(){

   LinkedList list;
    
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.InsertionAtBegining(0);

    
    list.traverse();  // Output: 0 1 2 3
    
   list.InsertAtPosi(6,0);
    
    list.traverse();  // Output: 0 1 2
    
    
  
    
    return 0;

}
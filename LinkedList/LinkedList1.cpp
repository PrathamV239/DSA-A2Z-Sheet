#include <iostream>
#include <stack>
using namespace std;

struct Node
{
  int data;
  Node *next;
  int index;
  Node(int val) : data(val), next(nullptr) {}
  Node(int val, Node *nextNode) : data(val), next(nextNode) {}
  Node(int val, int index) : data(val), index(index)
  {
  }
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void traverse()
  {
    Node *current = head;
    while (current != nullptr)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  Node *insert(int val)
  {
    if (head == nullptr)
    {
      head = new Node(val);
      return head;
    }

    Node *newNode = new Node(val);
    Node *current = head;

    while (current->next != nullptr)
    {
      current = current->next;
    }

    current->next = newNode;
    return head;
  }

  Node *insertAtBeginning(int val)
  {
    Node *newNode = new Node(val, head);
    head = newNode;
    return head;
  }

  Node *searchForValue(int val)
  {
    Node *current = head;

    while (current != nullptr)
    {
      if (current->data == val)
      {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  int findLength()
  {
    Node *current = head;
    int count = 0;
    while (current != nullptr)
    {
      count++;
      current = current->next;
    }
    return count;
  }

  Node *InsertAtPosi(int val, int index)
  {
    Node *current = head;
    Node *newNode = new Node(val);

    int cntr = 0;
    while (cntr != index)
    {
      if (current->next == nullptr)
        return head;
      current = current->next;
      cntr++;
    }
    newNode->next = current->next;
    current->next = newNode;
  }

  Node *InsertPosi(int val, int index)
  {

    Node *current = head;
    Node *newNode = new Node(val);
    int cntr = 0;
        if (index == 0){
        newNode -> next = head;
        head = newNode;
      }
    while (cntr != index - 1)
    {
      if (current->next == nullptr)return head;
      current = current->next;
      cntr++;
    }

    newNode->next = current->next;
    current->next = newNode;

    cout << endl;
  }

  Node* ReversePrint(){
     Node* current = head;
     stack<int> st;

     while (current != nullptr){
      st.push(current->data);
    
      current = current -> next;
      }
       cout << st.top()<< " ";
       st.pop();

    
  }



  // Fixed to match DLL logic pattern
  int deleteNode(int val)
  {
    if (head == nullptr)
    {
      return -1; // list is empty
    }

    // Delete head node
    if (head->data == val)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      return val;
    }

    // Delete middle or last node (same logic as DLL)
    Node *current = head;
    while (current->next != nullptr)
    {
      if (current->next->data == val)
      {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        return val;
      }
      current = current->next;
    }

    return -1; // value not found
  }
};

int main()
{
  cout << "=== Test 1: Basic Operations ===" << endl;
  LinkedList list;

  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insertAtBeginning(0);

  list.traverse(); // Output: 0 1 2 3

  // list.InsertPosi(7, 0);


list.ReversePrint();
// list.traverse();
  return 0;
}
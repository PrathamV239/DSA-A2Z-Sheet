#include <iostream>
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





};
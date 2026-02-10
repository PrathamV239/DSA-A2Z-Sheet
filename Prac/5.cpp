#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node* nextNode) : data(val), next(nextNode) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void traverse() {
        Node* current = head;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    Node* insert(int val) {
        Node* newNode = new Node(val, NULL);
        if(head == nullptr) {
            head = newNode;
            return head;
        }
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        return head;  
    }

    Node* insertAtBegininning(int val) {
        Node* newNode = new Node(val, head);
        head = newNode;
        return head;
    }

    Node* searchForValue(int val) {
        Node* current = head;

        while(current != nullptr) {
            if(current->data == val) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int findLength() {
        Node* current = head;
        int count = 0;
        while(current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }


    // check if this function works correctly
    int deleteNode(int val) {
        if(head == nullptr) {
            return -1; // list is empty
        }

        if(val == head -> data) {
            Node* temp = head;
            head = head -> next;
            delete temp;
            return val;
        }

        Node* current = head;
        while(current -> next != nullptr && current->next->next!= nullptr) {
            if (current->next->data == val) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return val;
            }
        }

        if (current->next != nullptr && current->next->data == val) {
            Node* temp = current->next;
            current->next = nullptr;
            delete temp;
            return val;
        }

    }
};

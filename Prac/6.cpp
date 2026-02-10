#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
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
        if (head == nullptr) {
            head = new Node(val);
            return head;
        }
        
        Node* newNode = new Node(val);
        Node* current = head;
        
        while(current->next != nullptr) {
            current = current->next;
        }
        
        current->next = newNode;
        newNode->prev = current;
        
        return head;
    }
    
    Node* insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        
        // FIX: Check if list is empty before accessing head
        if (head != nullptr) {
            head->prev = newNode;
        }
        
        newNode->next = head;
        head = newNode;
        return head;
    } 
    
    Node* deleteVal(int val) {
        if (head == nullptr)
            return nullptr;
        
        // Delete head node
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            
            // FIX: Check if new head exists before accessing it
            if (head != nullptr) {
                head->prev = nullptr;
            }
            
            delete temp;
            return head;
        }
        
        // Delete middle or last node
        Node* current = head;
        
        // FIX: Check if current->next exists before accessing current->next->data
        while(current->next != nullptr) {
            if (current->next->data == val) {
                Node* temp = current->next;
                current->next = temp->next;
                
                if(temp->next != nullptr) {
                    temp->next->prev = current;
                }
                
                delete temp;
                return head;
            }
            current = current->next;
        }
        
        return head;
    }
};

int main() {
    cout << "=== Test 1: Your Original Test ===" << endl;
    LinkedList list;
    
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insertAtBeginning(0);
    
    list.traverse();  // Output: 0 1 2 3
    
    list.deleteVal(3);
    
    list.traverse();  // Output: 0 1 2
    
    
    cout << "\n=== Test 2: Insert at Beginning on Empty List ===" << endl;
    LinkedList list2;
    list2.insertAtBeginning(5);
    list2.traverse();  // Output: 5
    
    
    cout << "\n=== Test 3: Delete Only Node ===" << endl;
    LinkedList list3;
    list3.insert(10);
    list3.traverse();  // Output: 10
    list3.deleteVal(10);
    cout << "After deleting only node: ";
    list3.traverse();  // Output: (empty line)
    
    
    cout << "\n=== Test 4: Delete Non-Existent Value ===" << endl;
    LinkedList list4;
    list4.insert(1);
    list4.insert(2);
    list4.insert(3);
    list4.traverse();  // Output: 1 2 3
    list4.deleteVal(99);  // Try to delete non-existent value
    cout << "After trying to delete 99: ";
    list4.traverse();  // Output: 1 2 3 (unchanged)
    
    
    cout << "\n=== Test 5: Delete Head (Multiple Nodes) ===" << endl;
    LinkedList list5;
    list5.insert(1);
    list5.insert(2);
    list5.insert(3);
    list5.traverse();  // Output: 1 2 3
    list5.deleteVal(1);
    cout << "After deleting head: ";
    list5.traverse();  // Output: 2 3
    
    
    cout << "\n=== Test 6: Delete Middle Node ===" << endl;
    LinkedList list6;
    list6.insert(1);
    list6.insert(2);
    list6.insert(3);
    list6.traverse();  // Output: 1 2 3
    list6.deleteVal(2);
    cout << "After deleting middle: ";
    list6.traverse();  // Output: 1 3
    
    
    cout << "\n=== Test 7: Delete Last Node ===" << endl;
    LinkedList list7;
    list7.insert(1);
    list7.insert(2);
    list7.insert(3);
    list7.traverse();  // Output: 1 2 3
    list7.deleteVal(3);
    cout << "After deleting last: ";
    list7.traverse();  // Output: 1 2
    
    
    cout << "\n=== Test 8: Complex Operations ===" << endl;
    LinkedList list8;
    list8.insertAtBeginning(5);  // Empty list insert at beginning
    list8.insert(10);
    list8.insert(15);
    list8.insertAtBeginning(1);
    list8.traverse();  // Output: 1 5 10 15
    list8.deleteVal(10);
    list8.traverse();  // Output: 1 5 15
    list8.deleteVal(1);
    list8.traverse();  // Output: 5 15
    list8.deleteVal(15);
    list8.traverse();  // Output: 5
    
    return 0;
}
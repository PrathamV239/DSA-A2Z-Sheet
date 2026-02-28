#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

public:
    BST() : root(nullptr) {}
    
    Node*& getRoot() {
        return root;
    }
    
    void inorder(Node* root) {
        if (!root) 
            return;
        
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
    
    void insertNode(Node*& node, int val) {
        if (node == nullptr) {
            node = new Node(val);
            return;
        }
    
        if (val < node->data)
            insertNode(node->left, val);
        else
            insertNode(node->right, val);
    }
    
    Node* findMinNode(Node* root) {
        while(root -> left != nullptr)
            root = root -> left;
        
        return root;
    }
    
    void removeNode(Node*& node, int val) {
        if(val < node -> data)
            removeNode(node -> left, val);
        else if(val > node -> data)
            removeNode(node -> right, val);
        else {
            if(node -> left == nullptr) {
                Node* temp = node;
                node = node -> right;
                delete(temp);
            } else if(node -> right == nullptr) {
                Node* temp = node;
                node = node -> left;
                delete(temp);
            } else {
                Node* temp = findMinNode(node -> right);
                node -> data = temp -> data;
                removeNode(node -> right, temp -> data);
            }
        }
    }
    
    void insert(int val) {
        insertNode(root, val);
    }
    
    void remove(int val) {
        removeNode(root, val);
    }
    
};

int main() {
    BST bst;
    
    bst.insert(1);
    bst.insert(0);
    bst.insert(2);
    
    bst.inorder(bst.getRoot());
    cout << endl;

}
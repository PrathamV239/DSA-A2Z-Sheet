#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


class BST{

  private:
    Node* root;

  public:
    BST() :  root(nullptr){}


    Node* getRoot(){
      return root;
    }


    void inorder (Node* node){
      if(node ==  nullptr)
        return;
      
      inorder(node->left);
      cout << node->data << " ";
      inorder(node->right);
    }


    void preorder(Node* node){

      if(node == nullptr)
        return;
      
      cout<< node->data << " ";
      preorder(node->left);
      preorder(node->right);
    }

    void postorder(Node* node){

      if(node == nullptr)
        return;

      postorder(node->left);
      postorder(node->right);
      cout<< node->data << " ";
    }

    Node* insertNode(int val){

      Node* newNode = new Node(val);

      if(root == nullptr){
        root = newNode;
        return root;
      }

      Node* current = root;
      while (true){
        if(val < current -> data){
          if(current -> left == nullptr){
            current -> left = newNode;
            break;
          }
          current = current ->left ;
        }
        else {
          if(current -> right == nullptr){
            current -> right = newNode;
            break;
          }
          current = current ->right;
        }


      }
      return root;
    }
    Node* insertRecurssive(Node*& node, int val){
      if(node == nullptr){
        node = new Node(val);
        return;
      }

      if(val < node->data)
        insertRecurssive(node-> left, val);
      else 
        insertRecurssive(node->right, val);
    }




};
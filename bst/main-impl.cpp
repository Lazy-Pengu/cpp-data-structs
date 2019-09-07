#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* right;
    Node* left;

    Node(int d);

}

class BST {

  public:
    int size;
    Node* root;

    BST();
    ~BST();

    void insert(int d);
    int search(int d);
    void remove(int d);

    void print();

};

Node::Node(int d):data(d), right(), left() {}

BST::BST():size(), root() {}

void BST::insert(int d) {
  if(root == NULL) {
    root = new Node(d);
    return;
  }

  Node* cur = root;

  while(cur->right != NULL || cur->left != NULL) {
    if(cur->data < d) {
      cur = cur->right;

    } else if(cur->data >= d) {
      cur = cur->left;

    }

  }

  if(cur->right == NULL && cur->data < d) {
    cur->right = new Node(d)

  } else if(cur->left == NULL && cur->data >= d) {
    cur->left = new Node(d);

  }


}


int BST::search(int d) {
  if(root == NULL) {
    throw "Empty Tree";
    return 0;
  }

  Node* cur = root;

  while(cur != NULL) {
    if(cur->data < d) {
      cur = cur->right;

    } else if(cur->data >= d) {
      cur = cur->left;

    }

    if(cur->data == d) {
      return cur->data;

    }

  }

  throw "Tree does not contain data";

  return 0;
}

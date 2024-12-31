#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        this->root = NULL;
    }
    BinaryTree(int val) {
        this->root = new Node(val);
    }
    void insert(int val) {
        Node* newNode = new Node(val);
        if (this->root == NULL) {
            this->root = newNode;
            return;
        }
        Node* temp = this->root;
        while (temp != NULL) {
            if (temp->data < val) {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            } else {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
        }
    }
};

int main() {
    BinaryTree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(3);
    bt.insert(7);
    bt.insert(12);
    bt.insert(18);

    // Add code to traverse and print the tree if needed
    cout<<"tree implemented"<<endl;

    return 0;
}
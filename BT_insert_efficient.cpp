#include <iostream>
using namespace std;

// Node class to represent each node in the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build the binary tree
Node* buildTree() {
    int data;
    cout << "Enter Data (-1 for no node): ";
    cin >> data;

    // Base case: If data is -1, return NULL
    if (data == -1) {
        return nullptr;
    }

    // Create a new node with the entered data
    Node* root = new Node(data);

    // Recursively build the left subtree
    cout << "Enter data for the left child of " << data << endl;
    root->left = buildTree();

    // Recursively build the right subtree
    cout << "Enter data for the right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// In-order traversal to test the tree
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;

    // Traverse left subtree
    inOrderTraversal(root->left);

    // Visit root
    cout << root->data << " ";

    // Traverse right subtree
    inOrderTraversal(root->right);
}

int main() {
    // Build the tree
    cout << "Start building the binary tree:" << endl;
    Node* root = buildTree();

    // Traverse and display the tree
    cout << "In-order Traversal of the Binary Tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

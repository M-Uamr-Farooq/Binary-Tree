#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter data (-1 for NULL): ";
    int data;
    cin >> data;
    
    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for inserting left of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter data for inserting right of " << data << ": ";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraverse(Node* root) {
    if (!root) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Separator for levels

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) { // Use comparison operator
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    // Build the binary tree
    root = buildTree(root);

    // Perform level order traversal
    cout << "Level Order Traversal:" << endl;
    levelOrderTraverse(root);

    return 0;
}

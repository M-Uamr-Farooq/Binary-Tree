#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter data ( -1 for NULL) : ";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for inserting left of " << data << " : ";
    root->left = buildTree(root->left);
    cout << "Enter data for inserting right of " << data << " : ";
    root->right = buildTree(root->right);

    return root;
}

         

int main()
{

    Node *root = NULL;

    root = buildTree(root);

    return 0;
}
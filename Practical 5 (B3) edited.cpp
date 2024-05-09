#include <iostream>
using namespace std;

/* Structure of a node in threaded binary tree */
struct Node {
    int key;
    Node *left, *right;
    bool isThreaded;
};

// Helper function to create a threaded binary tree
Node* createThreaded(Node* root) {
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
        return root;

    // Create threads for left child
    if (root->left != NULL) {
        Node* l = createThreaded(root->left);
        l->right = root;
        l->isThreaded = true;
    }

    // Recurse for right child
    if (root->right != NULL)
        createThreaded(root->right);

    return root;
}

// Helper function to find the leftmost node
Node* leftMost(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

// Inorder traversal of the threaded binary tree
void inorder(Node* root) {
    if (root == NULL)
        return;

    Node* cur = leftMost(root);

    while (cur != NULL) {
        cout << cur->key << " ";

        if (cur->isThreaded)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}

// Helper function to create a new node
Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->isThreaded = false;
    return temp;
}

int main() {
    int key, leftKey, rightKey;
    cout << "Enter the root key: ";
    cin >> key;
    Node* root = newNode(key);

    cout << "Enter the left child key (-1 for no child): ";
    cin >> leftKey;
    if (leftKey != -1) {
        root->left = newNode(leftKey);
        cout << "Enter the left child's left key (-1 for no child): ";
        cin >> key;
        if (key != -1)
            root->left->left = newNode(key);
        cout << "Enter the left child's right key (-1 for no child): ";
        cin >> key;
        if (key != -1)
            root->left->right = newNode(key);
    }

    cout << "Enter the right child key (-1 for no child): ";
    cin >> rightKey;
    if (rightKey != -1) {
        root->right = newNode(rightKey);
        cout << "Enter the right child's left key (-1 for no child): ";
        cin >> key;
        if (key != -1)
            root->right->left = newNode(key);
        cout << "Enter the right child's right key (-1 for no child): ";
        cin >> key;
        if (key != -1)
            root->right->right = newNode(key);
    }

    // Convert to a threaded binary tree
    createThreaded(root);

    cout << "Inorder traversal of the threaded binary tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
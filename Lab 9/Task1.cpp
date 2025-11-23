#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;  
    return newNode;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *temp = x->right; 

    x->right = y;
    y->left = temp;

    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;

    cout << "Rotation: Right" << endl;
    return x;  
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;  
 
    y->left = x;
    x->right = temp;

    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;

    cout << "Rotation: Left" << endl;
    return y; 

int getBalance(Node *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* insert(Node* node, int key) 
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));


    int balanceFactor = getBalance(node);
    if (balanceFactor > 1 || balanceFactor < -1) {
        cout << "Node " << node->key << " Balance Factor: " << balanceFactor << endl;
    }

    if (balanceFactor > 1 && key < node->left->key)
        return rightRotate(node);
 
    if (balanceFactor < -1 && key > node->right->key)
        return leftRotate(node);

    if (balanceFactor > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }


    if (balanceFactor < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; 
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp; 
            }
            delete temp;
        } else {

            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getBalance(root);
    if (balanceFactor > 1 || balanceFactor < -1) {
        cout << "Node " << root->key << " Balance Factor: " << balanceFactor << endl;
    }

    if (balanceFactor > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balanceFactor > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
  
    if (balanceFactor < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printTreeHeight(Node* root) {
    cout << "Tree Height: " << getHeight(root) << endl;
    cout << endl;  
}

int main() {
    Node *root = NULL;

    cout << "Start Inserting" << endl;
    int insertValues[] = {10, 20, 30, 40, 50, 25}; 
    int arraySize = sizeof(insertValues) / sizeof(insertValues[0]);
    
    for(int i = 0; i < arraySize; i++) {  
        cout << "Insert: " << insertValues[i] << endl;
        root = insert(root, insertValues[i]);
        printTreeHeight(root);
    }

    cout << "Start Deleting" << endl;
    int deleteValues[] = {10, 40, 50};
    int deleteSize = sizeof(deleteValues) / sizeof(deleteValues[0]);
    
    for(int i = 0; i < deleteSize; i++) {
        cout << "Delete: " << deleteValues[i] << endl;
        root = deleteNode(root, deleteValues[i]);
        printTreeHeight(root);
    }

    return 0;
}

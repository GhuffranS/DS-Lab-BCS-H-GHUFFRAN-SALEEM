#include <iostream>
using namespace std;

struct Node {
    double price;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

Node* createNode(double price) {
    Node* newNode = new Node();
    newNode->price = price;
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
    
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;
    
    y->left = x;
    x->right = temp;
    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

int getBalance(Node *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* insert(Node* node, double price) {
    if (node == NULL)
        return createNode(price);

    if (price < node->price)
        node->left = insert(node->left, price);
    else if (price > node->price)
        node->right = insert(node->right, price);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balanceFactor = getBalance(node);

    if (balanceFactor > 1 && price < node->left->price)
        return rightRotate(node);

    if (balanceFactor < -1 && price > node->right->price)
        return leftRotate(node);

    if (balanceFactor > 1 && price > node->left->price) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balanceFactor < -1 && price < node->right->price) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void rangeQuery(Node* root, double lowPrice, double highPrice) {
    if (root == NULL) 
        return;

    if (lowPrice < root->price)
        rangeQuery(root->left, lowPrice, highPrice);

    if (lowPrice <= root->price && highPrice >= root->price)
        cout << root->price << " ";

    if (highPrice > root->price)
        rangeQuery(root->right, lowPrice, highPrice);
}

int main() {
    Node *root = NULL;
    double priceList[] = {10.5, 50.0, 15.2, 20.0, 5.5, 80.9, 35.5, 25.0};
    int numPrices = 8;

    for(int i = 0; i < numPrices; i++) {
        root = insert(root, priceList[i]);
    }

    double minPrice = 15.0;
    double maxPrice = 50.0;

    cout << "Prices between " << minPrice << " and " << maxPrice << ":" << endl;
    rangeQuery(root, minPrice, maxPrice);
    cout << endl;

    return 0;
}

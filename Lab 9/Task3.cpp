#include <iostream>
using namespace std;

struct Node {
    int severity;
    Node *left;
    Node *right;
    int height;
};

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

Node* createNode(int severity) {
    Node* node = new Node();
    node->severity = severity;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y) {
    cout << "Rotation: Right" << endl;
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x) {
    cout << "Rotation: Left" << endl;
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

Node* insert(Node* node, int severity) {
    if (node == NULL)
        return createNode(severity);

    if (severity < node->severity)
        node->left = insert(node->left, severity);
    else if (severity > node->severity)
        node->right = insert(node->right, severity);
    else
        return node;

    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if(balance > 1 || balance < -1) 
        cout << "Tree Unbalanced at: " << node->severity << endl;

    if (balance > 1 && severity < node->left->severity)
        return rightRotate(node);

    if (balance < -1 && severity > node->right->severity)
        return leftRotate(node);

    if (balance > 1 && severity > node->left->severity) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && severity < node->right->severity) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node * minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int severity) {
    if (root == NULL)
        return root;

    if (severity < root->severity)
        root->left = deleteNode(root->left, severity);
    else if (severity > root->severity)
        root->right = deleteNode(root->right, severity);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->severity = temp->severity;
            root->right = deleteNode(root->right, temp->severity);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printHighestSeverity(Node* root) {
    if(root == NULL) {
        cout << "No patients" << endl;
        return;
    }
    Node* current = root;
    while(current->right != NULL) {
        current = current->right;
    }
    cout << "Most Critical Patient Score: " << current->severity << endl;
}

void printStatus(Node* root) {
    cout << "Height: " << getHeight(root) << endl;
    printHighestSeverity(root);
    cout << endl;
}

int main() {
    Node *root = NULL;

    cout << "New Patients Arriving" << endl;
    int scores[] = {10, 20, 30, 40, 50, 25};
    for(int s : scores) {
        cout << "Admitted: " << s << endl;
        root = insert(root, s);
        printStatus(root);
    }

    cout << "Patients Discharging" << endl;
    int discharge[] = {30, 50};
    for(int s : discharge) {
        cout << "Discharged: " << s << endl;
        root = deleteNode(root, s);
        printStatus(root);
    }

    return 0;
}

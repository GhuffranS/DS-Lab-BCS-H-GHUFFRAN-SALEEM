#include <iostream>
#include <string>

using namespace std;


struct PersonNode {
    string name;
    PersonNode* mother;
    PersonNode* father;

    PersonNode(string n) {
        name = n;
        mother = NULL;
        father = NULL;
    }
};

int getHeight(PersonNode* node) {
    if (node == NULL) {
        return -1;
    }
    int leftHeight = getHeight(node->mother);
    int rightHeight = getHeight(node->father);
    
    // Replaced max() from <algorithm>
    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
}

void printLeafNodes(PersonNode* node) {
    if (node == NULL) {
        return;
    }
    if (node->mother == NULL && node->father == NULL) {
        cout << node->name << " " << endl;
    }
    printLeafNodes(node->mother);
    printLeafNodes(node->father);
}

void printLevels(PersonNode* node, int level) {
    if (node == NULL) {
        return;
    }
    cout << node->name << " is at level " << level << endl;
    printLevels(node->mother, level + 1);
    printLevels(node->father, level + 1);
}

int main() {
    cout << "--- Task 1: Family Ancestry Tree ---" << endl;

    PersonNode* root = new PersonNode("Me");
    root->mother = new PersonNode("Mom");
    root->father = new PersonNode("Dad");

    root->mother->mother = new PersonNode("Maternal GM");
    root->mother->father = new PersonNode("Maternal GF");

    root->father->mother = new PersonNode("Paternal GM");

    cout << "Root: " << root->name << endl;
    
    cout << "\nHeight of the tree: " << getHeight(root) << endl;

    cout << "\nLevel of each member:" << endl;
    printLevels(root, 0);

    cout << "\nLeaf nodes (Ancestors):" << endl;
    printLeafNodes(root);

    return 0;
}

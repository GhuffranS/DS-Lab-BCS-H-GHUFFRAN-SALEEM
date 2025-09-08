#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* child;
    Node(int x) : val(x), next(NULL), child(NULL) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

Node* flattenList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (current->child != NULL) {
            Node* tempNext = current->next;
            Node* childList = current->child;
            current->next = childList;
            current->child = NULL;

            Node* childEnd = childList;
            while (childEnd->next != NULL) {
                childEnd = childEnd->next;
            }
            childEnd->next = tempNext;
        }
        current = current->next;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);

    cout << "Multilevel List: " << endl;
    cout << "Level 1: ";
    printList(head);
    cout << "Child of 2: ";
    printList(head->next->child);

    Node* flattenedHead = flattenList(head);

    cout << "\nFlattened List: " << endl;
    printList(flattenedHead);

    return 0;
}

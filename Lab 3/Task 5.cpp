#include <iostream>

using namespace std;

struct SinglyNode {
    int val;
    SinglyNode *next;
    SinglyNode(int x) : val(x), next(NULL) {}
};

struct DoublyNode {
    int val;
    DoublyNode *prev;
    DoublyNode *next;
    DoublyNode(int x) : val(x), prev(NULL), next(NULL) {}
};

struct CircularNode {
    int val;
    CircularNode *next;
    CircularNode(int x) : val(x), next(NULL) {}
};

DoublyNode* convertToDoubly(SinglyNode* head) {
    if (head == NULL) {
        return NULL;
    }

    DoublyNode* newHead = new DoublyNode(head->val);
    DoublyNode* currentDoubly = newHead;
    SinglyNode* currentSingly = head->next;

    while (currentSingly != NULL) {
        DoublyNode* newNode = new DoublyNode(currentSingly->val);
        newNode->prev = currentDoubly;
        currentDoubly->next = newNode;
        currentDoubly = currentDoubly->next;
        currentSingly = currentSingly->next;
    }

    return newHead;
}

CircularNode* convertToCircular(SinglyNode* head) {
    if (head == NULL) {
        return NULL;
    }

    CircularNode* newHead = new CircularNode(head->val);
    CircularNode* currentCircular = newHead;
    SinglyNode* currentSingly = head->next;

    while (currentSingly != NULL) {
        CircularNode* newNode = new CircularNode(currentSingly->val);
        currentCircular->next = newNode;
        currentCircular = currentCircular->next;
        currentSingly = currentSingly->next;
    }
    currentCircular->next = newHead;

    return newHead;
}

void printSinglyList(SinglyNode* head) {
    SinglyNode* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void printDoublyList(DoublyNode* head) {
    DoublyNode* current = head;
    while (current != NULL) {
        cout << current->val << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void printCircularList(CircularNode* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    
    CircularNode* current = head;
    do {
        cout << current->val << " -> ";
        current = current->next;
    } while (current != head);
    cout << " (back to head)" << endl;
}

int main() {
    SinglyNode* singlyList = new SinglyNode(1);
    singlyList->next = new SinglyNode(2);
    singlyList->next->next = new SinglyNode(3);

    cout << "Singly Linked List: ";
    printSinglyList(singlyList);

    DoublyNode* doublyList = convertToDoubly(singlyList);
    cout << "Doubly Linked List: ";
    printDoublyList(doublyList);

    CircularNode* circularList = convertToCircular(singlyList);
    cout << "Circular Linked List: ";
    printCircularList(circularList);

    return 0;
}

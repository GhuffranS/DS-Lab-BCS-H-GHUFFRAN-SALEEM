#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    ListNode* result = NULL;
    ListNode* tail = NULL;

    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            if (result == NULL) {
                result = l2;
            } else {
                tail->next = l2;
            }
            break;
        }

        if (l2 == NULL) {
            if (result == NULL) {
                result = l1;
            } else {
                tail->next = l1;
            }
            break;
        }

        if (l1->val <= l2->val) {
            if (result == NULL) {
                result = l1;
                tail = l1;
            } else {
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        } else {
            if (result == NULL) {
                result = l2;
                tail = l2;
            } else {
                tail->next = l2;
                tail = l2;
            }
            l2 = l2->next;
        }
    }

    return result;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    ListNode* mergedList = mergeTwoLists(l1, l2);
    printList(mergedList);

    return 0;
}

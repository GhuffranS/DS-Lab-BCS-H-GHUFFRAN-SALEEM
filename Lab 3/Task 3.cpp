#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    ListNode* current = head;
    ListNode* newHead = NULL;
    ListNode* newTail = NULL;
    ListNode* lastTail = NULL;

    while (current != NULL) {
        vector<int> groupVals;
        ListNode* groupStart = current;
        for (int i = 0; i < k && current != NULL; ++i) {
            groupVals.push_back(current->val);
            current = current->next;
        }

        if (groupVals.size() < k) {
            if (lastTail != NULL) {
                lastTail->next = groupStart;
            }
            break;
        }

        for (int i = groupVals.size() - 1; i >= 0; --i) {
            ListNode* newNode = new ListNode(groupVals[i]);
            if (newHead == NULL) {
                newHead = newNode;
                newTail = newNode;
            } else {
                newTail->next = newNode;
                newTail = newTail->next;
            }
        }
        lastTail = newTail;
    }
    return newHead;
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    int k = 3;

    ListNode* reversedList = reverseKGroup(head, k);

    printList(reversedList);

    return 0;
}

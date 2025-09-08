#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findSurvivor(int n, int k) {
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return 1;
    }

    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= n; ++i) {
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = head;

    ListNode* prev = current;
    current = head;

    while (current->next != current) {
        for (int i = 0; i < k - 1; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        current = prev->next;
    }

    return current->val;
}

int main() {
    int n = 7;
    int k = 3;
    
    cout << findSurvivor(n, k) << endl;

    return 0;
}

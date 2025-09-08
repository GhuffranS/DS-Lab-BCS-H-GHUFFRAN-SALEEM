#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if (head == NULL) {
        return true;
    }

    vector<int> values;
    ListNode* current = head;
    while (current != NULL) {
        values.push_back(current->val);
        current = current->next;
    }

    int n = values.size();
    for (int i = 0; i < n / 2; i++) {
        if (values[i] != values[n - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);
    cout << isPalindrome(head1) << endl;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    cout << isPalindrome(head2) << endl;

    return 0;
}

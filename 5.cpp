#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        return;
    }

    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;

    delete nextNode;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    deleteNode(head->next);

    printList(head);

    return 0;
}

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reorderListUtil(ListNode* head, ListNode*& tail) {
    if (head == nullptr || head->next == nullptr) {
        tail = nullptr;
        return head;
    }

    ListNode* nextNode = head->next;
    ListNode* newHead = reorderListUtil(nextNode, tail);

    if (newHead == nullptr || tail == nullptr) {
        return nullptr;
    }

    if (newHead == tail || newHead->next == tail) {
        tail = nullptr;
        return head;
    }

    head->next = tail;
    tail->next = nextNode;
    tail = nextNode;

    return newHead;
}

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    ListNode* tail = nullptr;
    reorderListUtil(head, tail);
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    reorderList(head1);
    reorderList(head2);

    printList(head1);
    printList(head2);

    return 0;
}

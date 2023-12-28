#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* doubleLinkedList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    int carry = 0;
    ListNode* current = head;
    
    while (current != nullptr) {
        int sum = current->val * 2 + carry;
        current->val = sum % 10;
        carry = sum / 10;

        if (current->next == nullptr && carry > 0) {
            current->next = new ListNode(carry);
            break;
        }

        current = current->next;
    }

    return head;
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
    head1->next = new ListNode(8);
    head1->next->next = new ListNode(9);

    ListNode* head2 = new ListNode(9);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(9);

    printList(doubleLinkedList(head1));
    printList(doubleLinkedList(head2));

    return 0;
}

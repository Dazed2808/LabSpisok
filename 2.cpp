#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* current = head;
    while (current->next != nullptr) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
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
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(2);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(3);

    ListNode* result1 = deleteDuplicates(head1);
    ListNode* result2 = deleteDuplicates(head2);

    printList(result1);
    printList(result2);

    return 0;
}

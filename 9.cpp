#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* partition(ListNode* head, int x) {
    ListNode lessDummy(0);  
    ListNode greaterDummy(0);  

    ListNode* lessTail = &lessDummy;  
    ListNode* greaterTail = &greaterDummy;  

    while (head != nullptr) {
        if (head->val < x) {
            lessTail->next = head;
            lessTail = lessTail->next;
        } else {
            greaterTail->next = head;
            greaterTail = greaterTail->next;
        }

        head = head->next;
    }

    lessTail->next = greaterDummy.next;
    greaterTail->next = nullptr;

    return lessDummy.next;
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
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(2);

    ListNode* result1 = partition(head1, 3);
    printList(result1);

    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);

    ListNode* result2 = partition(head2, 2);
    printList(result2);

    return 0;
}

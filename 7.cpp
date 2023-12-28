#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

    for (ListNode* list : lists) {
        if (list != nullptr) {
            minHeap.push(list);
        }
    }

    ListNode dummy(0);
    ListNode* current = &dummy;

    while (!minHeap.empty()) {
        ListNode* minNode = minHeap.top();
        minHeap.pop();

        current->next = minNode;
        current = current->next;

        if (minNode->next != nullptr) {
            minHeap.push(minNode->next);
        }
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    std::vector<ListNode*> lists = {list1, list2, list3};

    ListNode* result = mergeKLists(lists);
    printList(result);

    return 0;
}

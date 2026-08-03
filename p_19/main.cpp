#include <iostream>

struct ListNode {
  int val;
  ListNode *next;

  ListNode(): val(0), next(nullptr) {};
  ListNode(int x): val(x), next(nullptr) {};
  ListNode(int x, ListNode *next): val(x), next(next) {};
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy_node = new ListNode(0, head);

        int length = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }

        int idx_to_remove = length - n;

        ListNode *list_to_remove = dummy_node;

        for (int i = 0; i < idx_to_remove; i++) {
            list_to_remove = list_to_remove->next;
        }

        list_to_remove->next = list_to_remove->next->next;
        
        return dummy_node->next;
    }

};


int main() {
    ListNode *listNode1 = new ListNode(
        1, new ListNode(
            2, new ListNode(
                3, new ListNode(
                    4, new ListNode(5)
                )
            )
        )
    );

    Solution *soln = new Solution();

    ListNode *newListNode1 = soln->removeNthFromEnd(listNode1, 2);

    return 0;
}
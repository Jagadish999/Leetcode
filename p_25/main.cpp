#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyList = new ListNode(0);
        dummyList->next = head;

        ListNode* tail = dummyList;

        while (true) {
            ListNode* current = tail->next;

            std::vector<ListNode*> group;

            for (int i = 0; i < k && current; i++) {
                group.push_back(current);
                current = current->next;
            }

            if (group.size() != k) break;

            for (int i = k - 1; i > 0; i--) {
                group[i]->next = group[i - 1];
            }

            group[0]->next = current;
            tail->next = group[k-1];
            tail = group[0];
        }

        return dummyList->next;
    }
};
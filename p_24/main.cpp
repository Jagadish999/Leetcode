struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummylist = new ListNode(0);
        dummylist->next = head;
        
        ListNode* tail = dummylist;
        
        while (tail->next && tail->next->next)
        {
            ListNode* secondNode = tail->next;
            ListNode* thirdNode = tail->next->next;

            secondNode->next = thirdNode->next;
            thirdNode->next = secondNode;

            tail->next = thirdNode;

            tail = thirdNode->next;
        }
        
        return dummylist->next;
    }
};
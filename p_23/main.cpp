#include <iostream>
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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        bool isAllListNull = false;

        ListNode* dummyList = new ListNode(0);
        ListNode* mergedList = dummyList;

        while (!isAllListNull) {
            isAllListNull = true;

            int lowestListIdx = -1;
            int lowestListVal = -1;
            
            for (int i = 0; i < lists.size(); i++) {
                ListNode* currentListNode = lists[i];

                if (currentListNode == nullptr) continue;

                isAllListNull = false;

                if (lowestListIdx == -1 || lowestListVal > currentListNode->val) {
                    lowestListIdx = i;
                    lowestListVal = currentListNode->val;
                }
            }

            if(isAllListNull) continue;

            mergedList->next = lists[lowestListIdx];
            mergedList = mergedList->next;

            lists[lowestListIdx] = lists[lowestListIdx]->next;
        }

        return dummyList->next;
    }
};


int main() {



    return 0;
}



// Explain this 
    // ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    //     bool isAllListNull = false;

    //     ListNode* dummyList = new ListNode;
    //     ListNode* mergedList = nullptr;

    //     dummyList->next = mergedList;

    //     while (!isAllListNull) {
    //         isAllListNull = true;
    //         ListNode* lowest_listnode = nullptr;
            
    //         for (int i = 0; i < lists.size(); i++) {
    //             ListNode* currentListNode = lists[i];

    //             if (currentListNode == nullptr) continue;

    //             isAllListNull = false;

    //             if (lowest_listnode == nullptr || currentListNode->val < lowest_listnode->val) lowest_listnode = currentListNode;
    //         }

    //         if(isAllListNull) continue;

    //         mergedList = new ListNode(lowest_listnode->val);
    //         mergedList = mergedList->next;

    //         lowest_listnode = lowest_listnode->next;
    //     }

    //     return dummyList->next;
    // }
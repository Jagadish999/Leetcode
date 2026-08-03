struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dubbyList = new ListNode();
        ListNode *mergedLists = dubbyList;

        while (list1 != nullptr || list2 != nullptr)
        {
            int low_num;

            if (list1 and list2){
                int num_1 = list1->val;
                int num_2 = list2->val;

                if (num_1 < num_2) {
                    low_num = num_1;
                    list1 = list1->next;
                }
                else{
                    low_num = num_2;
                    list2 = list2->next;
                }
            }
            else if (list1)
            {
                low_num = list1->val;
                list1 = list1->next;
            }
            else if (list2)
            {   
                low_num = list2->val;
                list2 = list2->next;
            }

            mergedLists->next = new ListNode(low_num);
            mergedLists = mergedLists->next;
        }
        
        return dubbyList->next;
    }
};

int main() {


    return 0;
}
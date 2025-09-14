#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main() {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode *sum = addTwoNumbers(l1, l2);

    while (sum != nullptr)
    {
        cout << sum->val;
        sum = sum -> next;
    }

    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *main = new ListNode();
    ListNode *sum_of_two_nums = new ListNode();

    main->next = sum_of_two_nums;

    int carry = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        int num_first = (l1 != nullptr) ? l1->val : 0;
        int num_second = (l2 != nullptr) ? l2->val : 0;

        int sum = num_first + num_second + carry;

        if (sum > 9) {
            carry = 1;
            sum -= 10;
        }
        else {
            carry = 0;
        }

        sum_of_two_nums->val = sum;
        
        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;

        if (l1 != nullptr || l2 != nullptr || carry == 1){
            sum_of_two_nums->next = new ListNode();
            sum_of_two_nums = sum_of_two_nums->next;
        }
    }

    if (carry == 1) {
        sum_of_two_nums->val = carry;
    }

    return main->next;
}